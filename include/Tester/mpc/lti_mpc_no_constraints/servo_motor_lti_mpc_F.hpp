#ifndef SERVO_MOTOR_LTI_MPC_F_HPP_
#define SERVO_MOTOR_LTI_MPC_F_HPP_

#include "python_numpy.hpp"

namespace servo_motor_lti_mpc_F {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_F =
    SparseAvailable<ColumnAvailable<true, true, false, false, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, false, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>,
                    ColumnAvailable<true, true, true, true, true, false>,
                    ColumnAvailable<true, true, true, true, false, true>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_F>;

inline auto make(void) -> type {

  auto result = make_SparseMatrixZeros<float, SparseAvailable_lti_mpc_F>();

  result.unsafe_access(0) = static_cast<float>(1.0);
  result.unsafe_access(1) = static_cast<float>(0.05);
  result.unsafe_access(2) = static_cast<float>(1.0);
  result.unsafe_access(3) = static_cast<float>(6.400995031689204);
  result.unsafe_access(4) = static_cast<float>(0.32004975158446025);
  result.unsafe_access(5) = static_cast<float>(-0.32004975158446014);
  result.unsafe_access(6) = static_cast<float>(-0.01600248757922301);
  result.unsafe_access(7) = static_cast<float>(0.005);
  result.unsafe_access(8) = static_cast<float>(1.871980730795717);
  result.unsafe_access(9) = static_cast<float>(0.14750001233069035);
  result.unsafe_access(10) = static_cast<float>(0.006400963460214144);
  result.unsafe_access(11) = static_cast<float>(1.0);
  result.unsafe_access(12) = static_cast<float>(11.880107513752037);
  result.unsafe_access(13) = static_cast<float>(0.9441468461028453);
  result.unsafe_access(14) = static_cast<float>(-0.5940053756876017);
  result.unsafe_access(15) = static_cast<float>(-0.03984619407226529);
  result.unsafe_access(16) = static_cast<float>(0.005);
  result.unsafe_access(17) = static_cast<float>(2.4943238550717632);
  result.unsafe_access(18) = static_cast<float>(0.2837240846294813);
  result.unsafe_access(19) = static_cast<float>(0.025283807246411834);
  result.unsafe_access(20) = static_cast<float>(0.0003200481730107072);
  result.unsafe_access(21) = static_cast<float>(1.0);
  result.unsafe_access(22) = static_cast<float>(15.608667469960652);
  result.unsafe_access(23) = static_cast<float>(1.810994863909413);
  result.unsafe_access(24) = static_cast<float>(-0.7804333734980324);
  result.unsafe_access(25) = static_cast<float>(-0.0652273914590131);
  result.unsafe_access(26) = static_cast<float>(0.005);
  result.unsafe_access(27) = static_cast<float>(2.7699294824387);
  result.unsafe_access(28) = static_cast<float>(0.44425414312187195);
  result.unsafe_access(29) = static_cast<float>(0.061503525878064985);
  result.unsafe_access(30) = static_cast<float>(0.0014210139670958384);
  result.unsafe_access(31) = static_cast<float>(1.0);
  result.unsafe_access(32) = static_cast<float>(16.95529751278281);
  result.unsafe_access(33) = static_cast<float>(2.820928692412773);
  result.unsafe_access(34) = static_cast<float>(-0.8477648756391404);
  result.unsafe_access(35) = static_cast<float>(-0.08698557806904106);
  result.unsafe_access(36) = static_cast<float>(0.005);
  result.unsafe_access(37) = static_cast<float>(2.6415635709133025);
  result.unsafe_access(38) = static_cast<float>(0.6105380196469188);
  result.unsafe_access(39) = static_cast<float>(0.11792182145433486);
  result.unsafe_access(40) = static_cast<float>(0.003771473137780211);
  result.unsafe_access(41) = static_cast<float>(1.0);
  result.unsafe_access(42) = static_cast<float>(15.57683369782194);
  result.unsafe_access(43) = static_cast<float>(3.847697580695699);
  result.unsafe_access(44) = static_cast<float>(-0.778841684891097);
  result.unsafe_access(45) = static_cast<float>(-0.10101366461501016);
  result.unsafe_access(46) = static_cast<float>(0.005);
  result.unsafe_access(47) = static_cast<float>(2.1024921297978096);
  result.unsafe_access(48) = static_cast<float>(0.7620894477773434);
  result.unsafe_access(49) = static_cast<float>(0.1948753935101095);
  result.unsafe_access(50) = static_cast<float>(0.0077441129102290476);
  result.unsafe_access(51) = static_cast<float>(1.0);
  result.unsafe_access(52) = static_cast<float>(11.479652116182733);
  result.unsafe_access(53) = static_cast<float>(4.75420508703182);
  result.unsafe_access(54) = static_cast<float>(-0.5739826058091364);
  result.unsafe_access(55) = static_cast<float>(-0.10444126748513285);
  result.unsafe_access(56) = static_cast<float>(0.005);
  result.unsafe_access(57) = static_cast<float>(1.200819474606006);
  result.unsafe_access(58) = static_cast<float>(0.8791097698201467);
  result.unsafe_access(59) = static_cast<float>(0.28995902626969966);
  result.unsafe_access(60) = static_cast<float>(0.01353838500151771);
  result.unsafe_access(61) = static_cast<float>(1.0);
  result.unsafe_access(62) = static_cast<float>(5.039521895814326);
  result.unsafe_access(63) = static_cast<float>(5.410528362526442);
  result.unsafe_access(64) = static_cast<float>(-0.25197609479071625);
  result.unsafe_access(65) = static_cast<float>(-0.09587783893739497);
  result.unsafe_access(66) = static_cast<float>(0.005);
  result.unsafe_access(67) = static_cast<float>(0.036618804083406786);
  result.unsafe_access(68) = static_cast<float>(0.9451954718600465);
  result.unsafe_access(69) = static_cast<float>(0.3981690597958296);
  result.unsafe_access(70) = static_cast<float>(0.021131759964228662);
  result.unsafe_access(71) = static_cast<float>(1.0);
  result.unsafe_access(72) = static_cast<float>(-3.0262343827774387);
  result.unsafe_access(73) = static_cast<float>(5.712029125086292);
  result.unsafe_access(74) = static_cast<float>(0.15131171913887173);
  result.unsafe_access(75) = static_cast<float>(-0.07558143339808235);
  result.unsafe_access(76) = static_cast<float>(0.005);
  result.unsafe_access(77) = static_cast<float>(-1.2481815766291269);
  result.unsafe_access(78) = static_cast<float>(0.949766871569468);
  result.unsafe_access(79) = static_cast<float>(0.5124090788314563);
  result.unsafe_access(80) = static_cast<float>(0.03026301537226353);
  result.unsafe_access(81) = static_cast<float>(1.0);
  result.unsafe_access(82) = static_cast<float>(-11.734031616099838);
  result.unsafe_access(83) = static_cast<float>(5.595167109942813);
  result.unsafe_access(84) = static_cast<float>(0.5867015808049915);
  result.unsafe_access(85) = static_cast<float>(-0.04547180398733978);
  result.unsafe_access(86) = static_cast<float>(0.005);
  result.unsafe_access(87) = static_cast<float>(-2.48623738184256);
  result.unsafe_access(88) = static_cast<float>(0.8898696833851623);
  result.unsafe_access(89) = static_cast<float>(0.624311869092128);
  result.unsafe_access(90) = static_cast<float>(0.040449331473981935);
  result.unsafe_access(91) = static_cast<float>(1.0);
  result.unsafe_access(92) = static_cast<float>(-19.949885465629915);
  result.unsafe_access(93) = static_cast<float>(5.048758305070603);
  result.unsafe_access(94) = static_cast<float>(0.997494273281495);
  result.unsafe_access(95) = static_cast<float>(-0.008948592492769976);
  result.unsafe_access(96) = static_cast<float>(0.005);
  result.unsafe_access(97) = static_cast<float>(-3.5057307431227533);
  result.unsafe_access(98) = static_cast<float>(0.7710645495779264);
  result.unsafe_access(99) = static_cast<float>(0.7252865371561377);
  result.unsafe_access(100) = static_cast<float>(0.05103576587685754);
  result.unsafe_access(101) = static_cast<float>(1.0);
  result.unsafe_access(102) = static_cast<float>(-26.532937302111392);
  result.unsafe_access(103) = static_cast<float>(4.118877113213544);
  result.unsafe_access(104) = static_cast<float>(1.3266468651055687);
  result.unsafe_access(105) = static_cast<float>(0.029487415763394424);
  result.unsafe_access(106) = static_cast<float>(0.005);
  result.unsafe_access(107) = static_cast<float>(-4.153273462232451);
  result.unsafe_access(108) = static_cast<float>(0.6072249750980564);
  result.unsafe_access(109) = static_cast<float>(0.8076636731116225);
  result.unsafe_access(110) = static_cast<float>(0.0612718521374671);
  result.unsafe_access(111) = static_cast<float>(1.0);
  result.unsafe_access(112) = static_cast<float>(-30.489106228140226);
  result.unsafe_access(113) = static_cast<float>(2.9063371598037224);
  result.unsafe_access(114) = static_cast<float>(1.5244553114070112);
  result.unsafe_access(115) = static_cast<float>(0.06477868940011879);
  result.unsafe_access(116) = static_cast<float>(0.005);
  result.unsafe_access(117) = static_cast<float>(-4.31580259221097);
  result.unsafe_access(118) = static_cast<float>(0.41920020298159383);
  result.unsafe_access(119) = static_cast<float>(0.8657901296105484);
  result.unsafe_access(120) = static_cast<float>(0.07040639120294001);
  result.unsafe_access(121) = static_cast<float>(1.0);
  result.unsafe_access(122) = static_cast<float>(-31.114806312627998);
  result.unsafe_access(123) = static_cast<float>(1.5566154587338565);
  result.unsafe_access(124) = static_cast<float>(1.5557403156313996);
  result.unsafe_access(125) = static_cast<float>(0.09196183579718577);
  result.unsafe_access(126) = static_cast<float>(0.005);
  result.unsafe_access(127) = static_cast<float>(-3.9384457046415973);
  result.unsafe_access(128) = static_cast<float>(0.2324501666025236);
  result.unsafe_access(129) = static_cast<float>(0.8969222852320797);
  result.unsafe_access(130) = static_cast<float>(0.07778863816996803);
  result.unsafe_access(131) = static_cast<float>(1.0);
  result.unsafe_access(132) = static_cast<float>(-28.110699496079945);
  result.unsafe_access(133) = static_cast<float>(0.24309450563308815);
  result.unsafe_access(134) = static_cast<float>(1.4055349748039974);
  result.unsafe_access(135) = static_cast<float>(0.10684582774296794);
  result.unsafe_access(136) = static_cast<float>(0.005);
  result.unsafe_access(137) = static_cast<float>(-3.0356830272911406);
  result.unsafe_access(138) = static_cast<float>(0.07390543036573807);
  result.unsafe_access(139) = static_cast<float>(0.9017841513645569);
  result.unsafe_access(140) = static_cast<float>(0.08296254696488833);
  result.unsafe_access(141) = static_cast<float>(1.0);
  result.unsafe_access(142) = static_cast<float>(-21.64820047102577);
  result.unsafe_access(143) = static_cast<float>(-0.8545453829176415);
  result.unsafe_access(144) = static_cast<float>(1.0824100235512883);
  result.unsafe_access(145) = static_cast<float>(0.1066287167550311);
  result.unsafe_access(146) = static_cast<float>(0.005);
  result.unsafe_access(147) = static_cast<float>(-1.6938665600656044);
  result.unsafe_access(148) = static_cast<float>(-0.031573974291005946);
  result.unsafe_access(149) = static_cast<float>(0.8846933280032803);
  result.unsafe_access(150) = static_cast<float>(0.08574085558102315);
  result.unsafe_access(151) = static_cast<float>(1.0);
  result.unsafe_access(152) = static_cast<float>(-12.376710044692002);
  result.unsafe_access(153) = static_cast<float>(-1.5741785964812767);
  result.unsafe_access(154) = static_cast<float>(0.6188355022345998);
  result.unsafe_access(155) = static_cast<float>(0.09036608480830664);
  result.unsafe_access(156) = static_cast<float>(0.005);
  result.unsafe_access(157) = static_cast<float>(-0.06419822718650492);
  result.unsafe_access(158) = static_cast<float>(-0.0646886113663139);
  result.unsafe_access(159) = static_cast<float>(0.8532099113593253);
  result.unsafe_access(160) = static_cast<float>(0.08624768563486537);
  result.unsafe_access(161) = static_cast<float>(1.0);
  result.unsafe_access(162) = static_cast<float>(-1.3667782827404813);
  result.unsafe_access(163) = static_cast<float>(-1.7942558055215292);
  result.unsafe_access(164) = static_cast<float>(0.06833891413702396);
  result.unsafe_access(165) = static_cast<float>(0.05921866908857723);
  result.unsafe_access(166) = static_cast<float>(0.005);
  result.unsafe_access(167) = static_cast<float>(1.653500555116068);
  result.unsafe_access(168) = static_cast<float>(-0.014664108110428398);
  result.unsafe_access(169) = static_cast<float>(0.8173249722441968);
  result.unsafe_access(170) = static_cast<float>(0.08492186152905029);
  result.unsafe_access(171) = static_cast<float>(1.0);
  result.unsafe_access(172) = static_cast<float>(10.00726149533612);
  result.unsafe_access(173) = static_cast<float>(-1.452832620286274);
  result.unsafe_access(174) = static_cast<float>(-0.5003630747668057);
  result.unsafe_access(175) = static_cast<float>(0.016431605981031012);
  result.unsafe_access(176) = static_cast<float>(0.005);
  result.unsafe_access(177) = static_cast<float>(3.2346307369219103);
  result.unsafe_access(178) = static_cast<float>(0.1187441214345249);
  result.unsafe_access(179) = static_cast<float>(0.7882684631539046);
  result.unsafe_access(180) = static_cast<float>(0.08247796076144448);
  result.unsafe_access(181) = static_cast<float>(1.0);
  result.unsafe_access(182) = static_cast<float>(20.23324656177642);
  result.unsafe_access(183) = static_cast<float>(-0.5597785212092776);
  result.unsafe_access(184) = static_cast<float>(-1.0116623280888206);
  result.unsafe_access(185) = static_cast<float>(-0.03296915438685814);
  result.unsafe_access(186) = static_cast<float>(0.005);
  result.unsafe_access(187) = static_cast<float>(4.458541041012722);
  result.unsafe_access(188) = static_cast<float>(0.3245384814928337);
  result.unsafe_access(189) = static_cast<float>(0.7770729479493641);
  result.unsafe_access(190) = static_cast<float>(0.07982762393080305);
  result.unsafe_access(191) = static_cast<float>(1.0);
  result.unsafe_access(192) = static_cast<float>(27.856454944065664);
  result.unsafe_access(193) = static_cast<float>(0.7999223464753544);
  result.unsafe_access(194) = static_cast<float>(-1.3928227472032841);
  result.unsafe_access(195) = static_cast<float>(-0.08274048963322454);
  result.unsafe_access(196) = static_cast<float>(0.005);

  return result;
}

} // namespace servo_motor_lti_mpc_F

#endif // SERVO_MOTOR_LTI_MPC_F_HPP_
