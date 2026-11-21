#include "PythonNumpyLinalgTester.hpp"

#include "base_matrix_cholesky_decomposition.hpp"
#include "base_matrix_eigen_solver.hpp"
#include "base_matrix_inverse.hpp"
#include "base_matrix_lu_decomposition.hpp"
#include "base_matrix_qr_decomposition.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iomanip>
#include <limits>
#include <sstream>
#include <tuple>

#include <Arduino.h>

namespace {

using Base::Matrix::cholesky_decomposition;
using Base::Matrix::EigenSolverReal;
using Base::Matrix::gmres_k;
using Base::Matrix::LUDecomposition;
using Base::Matrix::Matrix;
using Base::Matrix::QRDecomposition;
using Base::Matrix::Vector;

constexpr std::size_t SAMPLE_COUNT = 7;
constexpr char CSV_SEPARATOR[] = ", ";
using TimingSamples = std::array<unsigned long, SAMPLE_COUNT>;

struct Metric {
  const char *name;
  double value;
};

template <typename Result, typename Operation>
unsigned long measure(Result &result, Operation operation) {
  asm volatile("" : : "g"(&result) : "memory");
  const unsigned long start = micros();
  operation();
  // Keep the entire result observable before taking the end timestamp.
  asm volatile("" : : "g"(&result) : "memory");
  return micros() - start;
}

template <typename Result, typename Operation>
TimingSamples measure_repeatedly(Result &result, Operation operation) {
  TimingSamples samples;
  for (auto &sample : samples) {
    // The legacy QR solver accumulates Q if the object is reused.
    result = Result{};
    sample = measure(result, operation);
  }
  return samples;
}

void report(const char *algorithm, const char *fixture, std::size_t rows,
            std::size_t cols, TimingSamples samples,
            const std::initializer_list<Metric> &metrics) {
  std::sort(samples.begin(), samples.end());
  std::ostringstream line;
  line << algorithm << CSV_SEPARATOR << fixture << CSV_SEPARATOR << rows
       << CSV_SEPARATOR << cols << CSV_SEPARATOR << samples.size()
       << CSV_SEPARATOR << samples.front() << CSV_SEPARATOR
       << samples[samples.size() / 2] << std::scientific
       << std::setprecision(9);
  for (const auto &metric : metrics) {
    line << CSV_SEPARATOR << metric.name << CSV_SEPARATOR << metric.value;
  }
  for (std::size_t i = metrics.size(); i < 3; ++i) {
    line << ",,";
  }
  Serial.println(line.str().c_str());
  Serial.flush();
}

double max_magnitude(double previous, double value) {
  if (!std::isfinite(value)) {
    return std::numeric_limits<double>::infinity();
  }
  return (std::max)(previous, std::fabs(value));
}

template <std::size_t N> Vector<float, N> reference_solution() {
  Vector<float, N> solution;
  for (std::size_t i = 0; i < N; ++i) {
    const float magnitude = static_cast<float>(i + 1);
    solution[i] = i % 2 == 0 ? magnitude : -magnitude;
  }
  return solution;
}

template <std::size_t N>
std::array<Metric, 2> solution_metrics(const Matrix<float, N, N> &matrix,
                                       const Vector<float, N> &rhs,
                                       const Vector<float, N> &solution,
                                       const Vector<float, N> &reference) {
  double error = 0.0;
  double reference_scale = 0.0;
  double residual = 0.0;
  double rhs_scale = 0.0;
  for (std::size_t i = 0; i < N; ++i) {
    error = max_magnitude(error, double(solution[i]) - reference[i]);
    reference_scale = max_magnitude(reference_scale, reference[i]);

    double ax = 0.0;
    for (std::size_t j = 0; j < N; ++j) {
      ax += double(matrix(i, j)) * solution[j];
    }
    residual = max_magnitude(residual, ax - rhs[i]);
    rhs_scale = max_magnitude(rhs_scale, rhs[i]);
  }
  return {{{"solution_rel_inf_error", error / reference_scale},
           {"residual_rel_inf", residual / rhs_scale}}};
}

void test_gmres(const char *fixture, bool scale_columns) {
  constexpr std::size_t N = 8;
  Matrix<float, N, N> matrix;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      const float value =
          i == j ? 4.0F + float(i) / 8.0F : float((i * 7 + j * 3) % 5) / 32.0F;
      matrix(i, j) = scale_columns ? value * float(1U << j) : value;
    }
  }

  const auto reference = reference_solution<N>();
  const auto rhs = matrix * reference;
  const Vector<float, N> zero;
  constexpr float decay_rate = 0.0F;
  constexpr float division_min = 1.0e-12F;
  decltype(gmres_k(matrix, rhs, zero, decay_rate, division_min)) result;
  const auto samples = measure_repeatedly(result, [&] {
    result = gmres_k(matrix, rhs, zero, decay_rate, division_min);
  });

  const auto metrics =
      solution_metrics(matrix, rhs, std::get<0>(result), reference);
  report("gmres_k", fixture, N, N, samples, {metrics[0], metrics[1]});
}

template <std::size_t Rows, std::size_t Cols>
Matrix<float, Rows, Cols> dense_fixture(float diagonal_offset) {
  Matrix<float, Rows, Cols> matrix;
  for (std::size_t i = 0; i < Rows; ++i) {
    for (std::size_t j = 0; j < Cols; ++j) {
      matrix(i, j) = float(int((i * 13 + j * 7) % 19) - 9) / 8.0F;
      if (i == j) {
        matrix(i, j) += diagonal_offset;
      }
    }
  }
  return matrix;
}

void test_lu(const char *fixture, bool tiny_first_pivot) {
  constexpr std::size_t N = 6;
  auto matrix = dense_fixture<N, N>(float(N));
  if (tiny_first_pivot) {
    matrix(0, 0) = 1.0F / 1048576.0F;
  }
  LUDecomposition<float, N> solver;
  const auto samples =
      measure_repeatedly(solver, [&] { solver.solve(matrix); });

  // Test the factors through the common solve(A, b) API, which applies
  // pivoting.
  const auto reference = reference_solution<N>();
  const auto rhs = matrix * reference;
  const auto solution = solver.solve(matrix, rhs);
  const auto metrics = solution_metrics(matrix, rhs, solution, reference);
  report("lu_factor", fixture, N, N, samples, {metrics[0], metrics[1]});
}

template <std::size_t N> void test_cholesky(const char *fixture) {
  // A = L L^T is positive definite because L has a positive diagonal.
  Matrix<float, N, N> lower;
  for (std::size_t i = 0; i < N; ++i) {
    lower(i, i) = 2.0F + static_cast<float>(i % 5 + 1) / 8.0F;
    for (std::size_t j = 0; j < i; ++j) {
      const int entry = static_cast<int>((i * 5 + j * 3) % 7) - 3;
      lower(i, j) = static_cast<float>(entry) / 8.0F;
    }
  }
  Matrix<float, N, N> matrix;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j <= i; ++j) {
      float value = 0.0F;
      for (std::size_t k = 0; k <= j; ++k) {
        value += lower(i, k) * lower(j, k);
      }
      matrix(i, j) = value;
      matrix(j, i) = value;
    }
  }
  const Matrix<float, N, N> fallback;
  constexpr float division_min = 1.0e-20F;
  decltype(cholesky_decomposition(matrix, fallback, division_min)) result;
  const auto samples = measure_repeatedly(result, [&] {
    result = cholesky_decomposition(matrix, fallback, division_min);
  });

  const auto &upper = std::get<0>(result);
  const bool failed = std::get<1>(result);
  double reconstruction = 0.0;
  double scale = 0.0;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      double utu = 0.0;
      for (std::size_t k = 0; k < N; ++k) {
        utu += double(upper(k, i)) * upper(k, j);
      }
      reconstruction = max_magnitude(reconstruction, utu - matrix(i, j));
      scale = max_magnitude(scale, matrix(i, j));
    }
  }
  const double error =
      failed ? std::numeric_limits<double>::infinity() : reconstruction / scale;
  report("cholesky_factor", fixture, N, N, samples,
         {{"reconstruction_rel_max", error},
          {"decomposition_failed", static_cast<double>(failed)}});
}

template <std::size_t Rows, std::size_t Cols>
void test_qr(const char *fixture) {
  const auto matrix = dense_fixture<Rows, Cols>(3.0F);
  QRDecomposition<float, Rows, Cols> solver;
  const auto samples =
      measure_repeatedly(solver, [&] { solver.solve(matrix); });

  const auto q = solver.get_Q();
  const auto r = solver.get_R();
  double reconstruction = 0.0;
  double scale = 0.0;
  double below_diagonal = 0.0;
  double orthogonality = 0.0;
  for (std::size_t i = 0; i < Rows; ++i) {
    for (std::size_t j = 0; j < Cols; ++j) {
      double qr = 0.0;
      for (std::size_t k = 0; k < Rows; ++k) {
        qr += double(q(i, k)) * r(k, j);
      }
      reconstruction = max_magnitude(reconstruction, qr - matrix(i, j));
      scale = max_magnitude(scale, matrix(i, j));
      if (i > j) {
        below_diagonal = max_magnitude(below_diagonal, r(i, j));
      }
    }
    for (std::size_t j = 0; j < Rows; ++j) {
      double qtq_minus_identity = i == j ? -1.0 : 0.0;
      for (std::size_t k = 0; k < Rows; ++k) {
        qtq_minus_identity += double(q(k, i)) * q(k, j);
      }
      orthogonality = max_magnitude(orthogonality, qtq_minus_identity);
    }
  }
  report("qr_givens", fixture, Rows, Cols, samples,
         {{"reconstruction_rel_max", reconstruction / scale},
          {"orthogonality_max", orthogonality},
          {"r_below_diagonal_rel_max", below_diagonal / scale}});
}

template <std::size_t N, typename Values>
double eigenvalue_error(const Values &values,
                        const std::array<double, N> &reference) {
  std::array<double, N> sorted;
  for (std::size_t i = 0; i < N; ++i) {
    if (!std::isfinite(values[i])) {
      return std::numeric_limits<double>::infinity();
    }
    sorted[i] = values[i];
  }
  std::sort(sorted.begin(), sorted.end());
  double error = 0.0;
  for (std::size_t i = 0; i < N; ++i) {
    error = max_magnitude(error, sorted[i] - reference[i]);
  }
  return error / reference.back();
}

template <std::size_t N, typename Values>
double eigenvector_residual(const Matrix<float, N, N> &matrix,
                            const Values &values,
                            const Matrix<float, N, N> &vectors) {
  double matrix_norm_squared = 0.0;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      matrix_norm_squared += double(matrix(i, j)) * matrix(i, j);
    }
  }
  double maximum = 0.0;
  for (std::size_t j = 0; j < N; ++j) {
    double vector_norm_squared = 0.0;
    double residual_squared = 0.0;
    for (std::size_t i = 0; i < N; ++i) {
      const double v = vectors(i, j);
      double residual = -double(values[j]) * v;
      for (std::size_t k = 0; k < N; ++k) {
        residual += double(matrix(i, k)) * vectors(k, j);
      }
      vector_norm_squared += v * v;
      residual_squared += residual * residual;
    }
    if (vector_norm_squared == 0.0 || !std::isfinite(vector_norm_squared)) {
      return std::numeric_limits<double>::infinity();
    }
    maximum = max_magnitude(
        maximum, std::sqrt(residual_squared /
                           (matrix_norm_squared * vector_norm_squared)));
  }
  return maximum;
}

void test_eigen() {
  constexpr std::size_t N = 4;
  const std::array<double, N> reference = {{1.0, 2.0, 4.0, 8.0}};
  // Q diag(1, 2, 4, 8) Q^T, with Q = I - ones(4, 4) / 2.
  const Matrix<float, N, N> matrix({{3.75F, 2.25F, 1.25F, -0.75F},
                                    {2.25F, 3.75F, 0.75F, -1.25F},
                                    {1.25F, 0.75F, 3.75F, -2.25F},
                                    {-0.75F, -1.25F, -2.25F, 3.75F}});
  TimingSamples value_samples;
  TimingSamples vector_samples;
  double value_error = 0.0;
  double vector_residual = 0.0;
  for (std::size_t i = 0; i < SAMPLE_COUNT; ++i) {
    // Start each inverse iteration from the values obtained in this trial.
    EigenSolverReal<float, N> solver;
    value_samples[i] =
        measure(solver, [&] { solver.solve_eigen_values(matrix); });
    vector_samples[i] =
        measure(solver, [&] { solver.solve_eigen_vectors(matrix); });
    if (i + 1 == SAMPLE_COUNT) {
      const auto values = solver.get_eigen_values();
      value_error = eigenvalue_error(values, reference);
      vector_residual =
          eigenvector_residual(matrix, values, solver.get_eigen_vectors());
    }
  }
  report("eigenvalues_real", "symmetric_dense", N, N, value_samples,
         {{"eigenvalue_rel_max_error", value_error}});
  report("eigenvectors_real", "symmetric_dense", N, N, vector_samples,
         {{"eigenpair_rel_residual", vector_residual}});
}

} // namespace

void PythonNumpyLinalgTester::test_linalg() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("algorithm, fixture, rows, cols, samples, min_us, median_us, "
                 "metric_1, value_1, metric_2, value_2, metric_3, value_3");
  Serial.flush();

  test_gmres("diagonal_dominant", false);
  test_gmres("columns_scaled", true);
  test_lu("dense", false);
  test_lu("tiny_first_pivot", true);
  test_cholesky<4>("dense_spd_4x4");
  test_cholesky<16>("dense_spd_16x16");
  test_qr<8, 8>("dense_square");
  test_qr<8, 4>("dense_tall");
  test_eigen();
}
