/*
 * File: ARJ21_init.c
 *
 * Code generated for Simulink model 'ARJ21_init'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Jun 30 10:36:23 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARJ21_init.h"
#include "ARJ21_init_private.h"

/* Exported block parameters */
real_T Flight_InertiaSelect = 0.0;     /* Variable: Flight_InertiaSelect
                                        * Referenced by:
                                        *   '<S7>/Constant2'
                                        *   '<S8>/Constant22'
                                        * For InertiaSelect. Default=0
                                          1: Inertia values are provided
                                          0: Inertia are computed in the model from weight and CG.
                                        */
real_T Flight_Trimming = 0.0;          /* Variable: Flight_Trimming
                                        * Referenced by: '<S1>/Constant1'
                                        * Trimming flag. Default=0
                                        */
real_T Flight_ixx = 0.0;               /* Variable: Flight_ixx
                                        * Referenced by: '<S7>/Constant1'
                                        * Ixx moment of inertia
                                        */
real_T Flight_ixz = 0.0;               /* Variable: Flight_ixz
                                        * Referenced by: '<S7>/Constant13'
                                        * Ixz moment of inertia
                                        */
real_T Flight_iyy = 0.0;               /* Variable: Flight_iyy
                                        * Referenced by: '<S7>/Constant10'
                                        * Iyy moment of inertia
                                        */
real_T Flight_izz = 0.0;               /* Variable: Flight_izz
                                        * Referenced by: '<S7>/Constant12'
                                        * Izz moment of inertia
                                        */
real_T Flight_lgdown = 0.0;            /* Variable: Flight_lgdown
                                        * Referenced by:
                                        *   '<S20>/Constant'
                                        *   '<S26>/Constant'
                                        *   '<S30>/Constant'
                                        * Landing Gear Up/Dn. Default=0
                                        */
real_T Flight_lw_fuel = 0.0;           /* Variable: Flight_lw_fuel
                                        * Referenced by: '<S29>/Constant2'
                                        * Left main fuel weight.
                                        */
real_T Flight_rw_fuel = 0.0;           /* Variable: Flight_rw_fuel
                                        * Referenced by: '<S29>/Constant3'
                                        * Right main fuel weight.
                                        */
real_T Flight_weight = 0.0;            /* Variable: Flight_weight
                                        * Referenced by:
                                        *   '<S29>/Constant1'
                                        *   '<S23>/Constant1'
                                        *   '<S24>/Constant1'
                                        * Aircraft weight. Default=
                                        */
real_T Flight_xcg = 25.0;              /* Variable: Flight_xcg
                                        * Referenced by:
                                        *   '<S8>/Constant11'
                                        *   '<S23>/Constant4'
                                        * Aircraft center of gravity position along X axis. Default=25
                                        */
real_T Flight_ycg = 0.0;               /* Variable: Flight_ycg
                                        * Referenced by:
                                        *   '<S8>/Constant8'
                                        *   '<S24>/Constant4'
                                        * Aircraft center of gravity position along Y axis. Default=0
                                        */
real_T Flight_zcg = 0.0;               /* Variable: Flight_zcg
                                        * Referenced by: '<S8>/Constant9'
                                        * Aircraft center of gravity position along Z axis. Default= 0
                                        */

/* Block signals (default storage) */
B_ARJ21_init_T ARJ21_init_B;

/* Block states (default storage) */
DW_ARJ21_init_T ARJ21_init_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ARJ21_init_T ARJ21_init_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ARJ21_init_T ARJ21_init_Y;

/* Real-time model */
RT_MODEL_ARJ21_init_T ARJ21_init_M_;
RT_MODEL_ARJ21_init_T *const ARJ21_init_M = &ARJ21_init_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void ARJ21_init_step(void)
{
  real_T total_fuel_lb;
  real_T rtb_func3;
  real_T rtb_Product2;
  real_T rtb_Mass_FuelLeft_xcg;
  real_T rtb_Switch[6];
  real_T rtb_func2;
  real_T rtb_Sum2;
  real_T rtb_Subtract2[6];
  int32_T i;
  real_T rtb_Subtract2_0[6];
  real_T tmp[6];
  real_T tmp_0[6];
  real_T rtb_TmpSignalConversionAtDotP_0;
  real_T rtb_TmpSignalConversionAtDot_lg;
  real_T rtb_dCG2AcFt_idx_0;
  real_T rtb_dCG2AcFt_idx_2;
  real_T rtb_TmpSignalConversionAtDotP_a;
  real_T rtb_TmpSignalConversionAtDot__0;
  real_T rtb_TmpSignalConversionAtDo_a_0;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_2;
  real_T rtb_TmpSignalConversionAtDotP_1;
  real_T rtb_TmpSignalConversionAtDo_a_1;
  real_T rtb_TmpSignalConversionAtDotP_3;
  real_T rtb_TmpSignalConversionAtDotP_4;
  real_T DotProduct1_tmp;

  /* Gain: '<S29>/Correction4' incorporates:
   *  UnitDelay: '<S31>/Unit Delay'
   */
  rtb_Mass_FuelLeft_xcg = 0.5 * ARJ21_init_DW.UnitDelay_DSTATE;

  /* Sum: '<S29>/Sum1' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   */
  ARJ21_init_B.lw_tank_fuel_lb = Flight_lw_fuel - rtb_Mass_FuelLeft_xcg;
  ARJ21_init_B.rw_tank_fuel_lb = Flight_rw_fuel - rtb_Mass_FuelLeft_xcg;

  /* Sum: '<S29>/Sum2' incorporates:
   *  Constant: '<S29>/Constant1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  rtb_Sum2 = Flight_weight - ARJ21_init_DW.UnitDelay_DSTATE;

  /* MATLAB Function: '<S30>/MATLAB Function1' incorporates:
   *  Constant: '<S30>/Constant4'
   *  Sum: '<S29>/Sum3'
   */
  ARJ21_init_B.conf_weight = fmax(0.0, rtb_Sum2);
  ARJ21_init_B.fuel_lb = ARJ21_init_B.lw_tank_fuel_lb +
    ARJ21_init_B.rw_tank_fuel_lb;
  total_fuel_lb = ARJ21_init_B.fuel_lb;
  if (rtb_Sum2 - ARJ21_init_B.fuel_lb < 0.0) {
    total_fuel_lb = rtb_Sum2;
  }

  /* Gain: '<S30>/Correction7' incorporates:
   *  Constant: '<S30>/Constant1'
   *  MATLAB Function: '<S30>/MATLAB Function1'
   */
  ARJ21_init_B.owe_lb = 54264.6;

  /* Gain: '<S30>/Correction1' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant3'
   *  MATLAB Function: '<S30>/MATLAB Function1'
   */
  ARJ21_init_B.payload_lb = fmin(19698.0, (ARJ21_init_B.conf_weight - 54264.6) -
    total_fuel_lb);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   */
  if (Flight_lgdown >= 0.5) {
    rtb_dCG2AcFt_idx_0 = -666.6;
    rtb_dCG2AcFt_idx_2 = -14.41;
  } else {
    rtb_dCG2AcFt_idx_0 = -666.25;
    rtb_dCG2AcFt_idx_2 = -16.43;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Lookup_n-D: '<S19>/Mass_FuelLeft_ycg' */
  rtb_Mass_FuelLeft_xcg = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelLeft_ycg_tableData,
    172U);

  /* Lookup_n-D: '<S22>/Mass_FuelRight_ycg' */
  total_fuel_lb = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelRight_ycg_tableData,
    172U);

  /* DotProduct: '<S24>/Dot Product' incorporates:
   *  DotProduct: '<S16>/Dot Product2'
   *  SignalConversion generated from: '<S23>/Dot Product'
   *  SignalConversion generated from: '<S24>/Dot Product'
   */
  rtb_func3 = ARJ21_init_B.lw_tank_fuel_lb * rtb_Mass_FuelLeft_xcg;
  rtb_TmpSignalConversionAtDotP_1 = ARJ21_init_B.rw_tank_fuel_lb * total_fuel_lb;

  /* SignalConversion generated from: '<S16>/Dot Product2' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/Constant4'
   *  DotProduct: '<S24>/Dot Product'
   *  Product: '<S24>/Divide'
   *  Product: '<S24>/Product1'
   *  SignalConversion generated from: '<S23>/Dot Product'
   *  Sum: '<S24>/Sum'
   */
  rtb_Sum2 = (Flight_weight * Flight_ycg - ((ARJ21_init_B.owe_lb * 0.1 +
    rtb_func3) + rtb_TmpSignalConversionAtDotP_1)) / ARJ21_init_B.payload_lb;

  /* Product: '<S16>/Product2' incorporates:
   *  DotProduct: '<S16>/Dot Product2'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   */
  rtb_func3 = (((ARJ21_init_B.owe_lb * 0.1 + ARJ21_init_B.payload_lb * rtb_Sum2)
                + rtb_func3) + rtb_TmpSignalConversionAtDotP_1) /
    ARJ21_init_B.conf_weight;

  /* Lookup_n-D: '<S19>/Mass_FuelLeft_zcg' */
  rtb_TmpSignalConversionAtDotP_1 = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled10, 172U);

  /* Lookup_n-D: '<S22>/Mass_FuelRight_zcg' */
  rtb_TmpSignalConversionAtDo_a_0 = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled10, 172U);

  /* Sum: '<S10>/Sum1' incorporates:
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S11>/Sum1'
   *  Sum: '<S14>/Sum1'
   *  Sum: '<S15>/Sum2'
   */
  rtb_Sum2 -= rtb_func3;
  rtb_TmpSignalConversionAtDotP_a = rtb_Mass_FuelLeft_xcg - rtb_func3;
  rtb_TmpSignalConversionAtDot_lg = total_fuel_lb - rtb_func3;

  /* Product: '<S18>/Product2' incorporates:
   *  DotProduct: '<S18>/Dot Product2'
   *  Lookup_n-D: '<S19>/Mass_FuelLeft_zcg'
   *  Lookup_n-D: '<S22>/Mass_FuelRight_zcg'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  SignalConversion generated from: '<S18>/Dot Product2'
   */
  total_fuel_lb = (((ARJ21_init_B.owe_lb * rtb_dCG2AcFt_idx_2 +
                     ARJ21_init_B.payload_lb) + ARJ21_init_B.lw_tank_fuel_lb *
                    rtb_TmpSignalConversionAtDotP_1) +
                   ARJ21_init_B.rw_tank_fuel_lb *
                   rtb_TmpSignalConversionAtDo_a_0) / ARJ21_init_B.conf_weight;

  /* Sum: '<S10>/Sum2' incorporates:
   *  SignalConversion generated from: '<S18>/Dot Product2'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S13>/Sum2'
   *  Sum: '<S14>/Sum'
   */
  rtb_dCG2AcFt_idx_2 -= total_fuel_lb;
  rtb_TmpSignalConversionAtDot__0 = rtb_dCG2AcFt_idx_2;

  /* DotProduct: '<S10>/Dot Product1' incorporates:
   *  DotProduct: '<S13>/Dot Product1'
   *  DotProduct: '<S15>/Dot Product1'
   *  Math: '<S10>/Math Function'
   *  Math: '<S10>/Math Function1'
   *  Math: '<S13>/Math Function1'
   *  Math: '<S15>/Math Function1'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   */
  rtb_TmpSignalConversionAtDotP_3 = (1.0 - total_fuel_lb) * (1.0 - total_fuel_lb);
  rtb_TmpSignalConversionAtDotP_4 = (0.1 - rtb_func3) * (0.1 - rtb_func3);
  rtb_Product_idx_1 = rtb_Sum2 * rtb_Sum2;
  rtb_TmpSignalConversionAtDotP_0 = (rtb_TmpSignalConversionAtDotP_4 +
    rtb_dCG2AcFt_idx_2 * rtb_dCG2AcFt_idx_2) * ARJ21_init_B.owe_lb +
    (rtb_TmpSignalConversionAtDotP_3 + rtb_Product_idx_1) *
    ARJ21_init_B.payload_lb;

  /* Sum: '<S10>/Sum2' incorporates:
   *  Lookup_n-D: '<S19>/Mass_FuelLeft_zcg'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S13>/Sum2'
   *  Sum: '<S14>/Sum'
   */
  rtb_dCG2AcFt_idx_2 = rtb_TmpSignalConversionAtDotP_1 - total_fuel_lb;

  /* DotProduct: '<S10>/Dot Product1' incorporates:
   *  DotProduct: '<S15>/Dot Product1'
   *  Math: '<S10>/Math Function'
   *  Math: '<S10>/Math Function1'
   *  Math: '<S15>/Math Function1'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  rtb_Product_idx_2 = rtb_TmpSignalConversionAtDotP_a *
    rtb_TmpSignalConversionAtDotP_a;
  rtb_TmpSignalConversionAtDotP_0 += (rtb_Product_idx_2 + rtb_dCG2AcFt_idx_2 *
    rtb_dCG2AcFt_idx_2) * ARJ21_init_B.lw_tank_fuel_lb;

  /* Sum: '<S10>/Sum2' incorporates:
   *  Lookup_n-D: '<S22>/Mass_FuelRight_zcg'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S13>/Sum2'
   *  Sum: '<S14>/Sum'
   */
  rtb_TmpSignalConversionAtDotP_1 = rtb_dCG2AcFt_idx_2;
  rtb_dCG2AcFt_idx_2 = rtb_TmpSignalConversionAtDo_a_0 - total_fuel_lb;

  /* DotProduct: '<S10>/Dot Product1' incorporates:
   *  DotProduct: '<S13>/Dot Product1'
   *  DotProduct: '<S15>/Dot Product1'
   *  Math: '<S10>/Math Function'
   *  Math: '<S10>/Math Function1'
   *  Math: '<S13>/Math Function1'
   *  Math: '<S15>/Math Function1'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S10>/Sum'
   */
  rtb_Product_idx_0 = rtb_dCG2AcFt_idx_2 * rtb_dCG2AcFt_idx_2;
  DotProduct1_tmp = rtb_TmpSignalConversionAtDot_lg *
    rtb_TmpSignalConversionAtDot_lg;
  ARJ21_init_B.DotProduct1 = (DotProduct1_tmp + rtb_Product_idx_0) *
    ARJ21_init_B.rw_tank_fuel_lb + rtb_TmpSignalConversionAtDotP_0;

  /* Lookup_n-D: '<S19>/Mass_FuelLeft_xcg' */
  rtb_Mass_FuelLeft_xcg = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled11, 172U);

  /* Lookup_n-D: '<S22>/Mass_FuelRight_xcg' */
  rtb_func2 = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
    ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled11, 172U);

  /* DotProduct: '<S23>/Dot Product' incorporates:
   *  DotProduct: '<S17>/Dot Product2'
   *  SignalConversion generated from: '<S23>/Dot Product'
   * */
  rtb_Product2 = ARJ21_init_B.owe_lb * rtb_dCG2AcFt_idx_0;
  rtb_TmpSignalConversionAtDotP_0 = ARJ21_init_B.lw_tank_fuel_lb *
    rtb_Mass_FuelLeft_xcg;
  rtb_TmpSignalConversionAtDo_a_1 = ARJ21_init_B.rw_tank_fuel_lb * rtb_func2;

  /* SignalConversion generated from: '<S17>/Dot Product2' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/Constant7'
   *  DotProduct: '<S23>/Dot Product'
   *  Fcn: '<S23>/xcg2ac'
   *  Gain: '<S23>/Gain'
   *  Product: '<S23>/Divide'
   *  Product: '<S23>/Product1'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S23>/Sum1'
   */
  rtb_TmpSignalConversionAtDo_a_0 = (-((Flight_xcg - 25.0) * 12.0 / 100.0 *
    11.3393376332 + 649.31931211679989) * Flight_weight - ((rtb_Product2 +
    rtb_TmpSignalConversionAtDotP_0) + rtb_TmpSignalConversionAtDo_a_1)) /
    ARJ21_init_B.payload_lb;

  /* Product: '<S17>/Product2' incorporates:
   *  DotProduct: '<S17>/Dot Product2'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   */
  rtb_Product2 = (((rtb_Product2 + ARJ21_init_B.payload_lb *
                    rtb_TmpSignalConversionAtDo_a_0) +
                   rtb_TmpSignalConversionAtDotP_0) +
                  rtb_TmpSignalConversionAtDo_a_1) / ARJ21_init_B.conf_weight;

  /* Sum: '<S13>/Sum1' incorporates:
   *  SignalConversion generated from: '<S17>/Dot Product2'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDo_a_1 = rtb_dCG2AcFt_idx_0 - rtb_Product2;

  /* DotProduct: '<S13>/Dot Product1' incorporates:
   *  Math: '<S13>/Math Function'
   *  Math: '<S13>/Math Function1'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum2'
   */
  rtb_TmpSignalConversionAtDotP_0 = (rtb_TmpSignalConversionAtDo_a_1 *
    rtb_TmpSignalConversionAtDo_a_1 + rtb_TmpSignalConversionAtDot__0 *
    rtb_TmpSignalConversionAtDot__0) * ARJ21_init_B.owe_lb;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Sum: '<S12>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_dCG2AcFt_idx_0 = rtb_TmpSignalConversionAtDo_a_1;
  rtb_TmpSignalConversionAtDo_a_1 = rtb_TmpSignalConversionAtDo_a_0 -
    rtb_Product2;

  /* DotProduct: '<S13>/Dot Product1' incorporates:
   *  Math: '<S13>/Math Function'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S13>/Sum'
   */
  rtb_TmpSignalConversionAtDotP_0 += (rtb_TmpSignalConversionAtDotP_3 +
    rtb_TmpSignalConversionAtDo_a_1 * rtb_TmpSignalConversionAtDo_a_1) *
    ARJ21_init_B.payload_lb;

  /* Sum: '<S13>/Sum1' incorporates:
   *  SignalConversion generated from: '<S17>/Dot Product2'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDo_a_0 = rtb_TmpSignalConversionAtDo_a_1;
  rtb_TmpSignalConversionAtDo_a_1 = rtb_Mass_FuelLeft_xcg - rtb_Product2;

  /* DotProduct: '<S13>/Dot Product1' incorporates:
   *  Math: '<S13>/Math Function'
   *  Math: '<S13>/Math Function1'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum2'
   */
  rtb_TmpSignalConversionAtDotP_0 += (rtb_TmpSignalConversionAtDo_a_1 *
    rtb_TmpSignalConversionAtDo_a_1 + rtb_TmpSignalConversionAtDotP_1 *
    rtb_TmpSignalConversionAtDotP_1) * ARJ21_init_B.lw_tank_fuel_lb;

  /* Sum: '<S13>/Sum1' incorporates:
   *  SignalConversion generated from: '<S17>/Dot Product2'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_Mass_FuelLeft_xcg = rtb_TmpSignalConversionAtDo_a_1;
  rtb_TmpSignalConversionAtDo_a_1 = rtb_func2 - rtb_Product2;

  /* DotProduct: '<S13>/Dot Product1' incorporates:
   *  DotProduct: '<S15>/Dot Product1'
   *  Math: '<S13>/Math Function'
   *  Math: '<S15>/Math Function'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S13>/Sum'
   */
  rtb_TmpSignalConversionAtDotP_3 = rtb_TmpSignalConversionAtDo_a_1 *
    rtb_TmpSignalConversionAtDo_a_1;
  ARJ21_init_B.DotProduct1_o = (rtb_TmpSignalConversionAtDotP_3 +
    rtb_Product_idx_0) * ARJ21_init_B.rw_tank_fuel_lb +
    rtb_TmpSignalConversionAtDotP_0;

  /* DotProduct: '<S15>/Dot Product1' incorporates:
   *  Math: '<S15>/Math Function'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S15>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_0 = (rtb_TmpSignalConversionAtDotP_4 +
    rtb_dCG2AcFt_idx_0 * rtb_dCG2AcFt_idx_0) * ARJ21_init_B.owe_lb;

  /* Product: '<S12>/Product' incorporates:
   *  Product: '<S11>/Product'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_4 = ARJ21_init_B.owe_lb * rtb_dCG2AcFt_idx_0;
  rtb_Product_idx_0 = rtb_TmpSignalConversionAtDotP_4 *
    rtb_TmpSignalConversionAtDot__0;
  rtb_dCG2AcFt_idx_0 = rtb_TmpSignalConversionAtDotP_4;

  /* DotProduct: '<S15>/Dot Product1' incorporates:
   *  Math: '<S15>/Math Function'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S15>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_0 += (rtb_TmpSignalConversionAtDo_a_0 *
    rtb_TmpSignalConversionAtDo_a_0 + rtb_Product_idx_1) *
    ARJ21_init_B.payload_lb;

  /* Product: '<S12>/Product' incorporates:
   *  Product: '<S11>/Product'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_4 = ARJ21_init_B.payload_lb *
    rtb_TmpSignalConversionAtDo_a_0;
  rtb_Product_idx_1 = (1.0 - total_fuel_lb) * rtb_TmpSignalConversionAtDotP_4;
  rtb_TmpSignalConversionAtDo_a_0 = rtb_TmpSignalConversionAtDotP_4;

  /* DotProduct: '<S15>/Dot Product1' incorporates:
   *  Math: '<S15>/Math Function'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S15>/Sum'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_0 += (rtb_Mass_FuelLeft_xcg *
    rtb_Mass_FuelLeft_xcg + rtb_Product_idx_2) * ARJ21_init_B.lw_tank_fuel_lb;

  /* Product: '<S12>/Product' incorporates:
   *  Product: '<S11>/Product'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S15>/Sum1'
   */
  rtb_TmpSignalConversionAtDotP_4 = ARJ21_init_B.lw_tank_fuel_lb *
    rtb_Mass_FuelLeft_xcg;
  rtb_Product_idx_2 = rtb_TmpSignalConversionAtDotP_4 *
    rtb_TmpSignalConversionAtDotP_1;
  rtb_Mass_FuelLeft_xcg = rtb_TmpSignalConversionAtDotP_4;

  /* DotProduct: '<S15>/Dot Product1' incorporates:
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S15>/Sum'
   */
  ARJ21_init_B.DotProduct1_g = (rtb_TmpSignalConversionAtDotP_3 +
    DotProduct1_tmp) * ARJ21_init_B.rw_tank_fuel_lb +
    rtb_TmpSignalConversionAtDotP_0;

  /* Product: '<S12>/Product' incorporates:
   *  Product: '<S11>/Product'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   */
  rtb_TmpSignalConversionAtDotP_4 = ARJ21_init_B.rw_tank_fuel_lb *
    rtb_TmpSignalConversionAtDo_a_1;

  /* Product: '<S11>/Product' incorporates:
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S11>/Sum1'
   */
  rtb_dCG2AcFt_idx_0 *= 0.1 - rtb_func3;
  rtb_TmpSignalConversionAtDo_a_0 *= rtb_Sum2;
  rtb_Mass_FuelLeft_xcg *= rtb_TmpSignalConversionAtDotP_a;

  /* Sum: '<S12>/Sum of Elements' incorporates:
   *  Product: '<S12>/Product'
   */
  ARJ21_init_B.SumofElements = ((rtb_Product_idx_0 + rtb_Product_idx_1) +
    rtb_Product_idx_2) + rtb_TmpSignalConversionAtDotP_4 * rtb_dCG2AcFt_idx_2;

  /* Sum: '<S11>/Sum of Elements' incorporates:
   *  Product: '<S11>/Product'
   */
  ARJ21_init_B.SumofElements_g = ((rtb_dCG2AcFt_idx_0 +
    rtb_TmpSignalConversionAtDo_a_0) + rtb_Mass_FuelLeft_xcg) +
    rtb_TmpSignalConversionAtDotP_4 * rtb_TmpSignalConversionAtDot_lg;

  /* Sum: '<S14>/Sum of Elements' incorporates:
   *  Product: '<S14>/Product'
   *  SignalConversion generated from: '<S16>/Dot Product2'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S14>/Sum1'
   */
  ARJ21_init_B.SumofElements_d = (((1.0 - total_fuel_lb) *
    ARJ21_init_B.payload_lb * rtb_Sum2 + ARJ21_init_B.owe_lb *
    rtb_TmpSignalConversionAtDot__0 * (0.1 - rtb_func3)) +
    ARJ21_init_B.lw_tank_fuel_lb * rtb_TmpSignalConversionAtDotP_1 *
    rtb_TmpSignalConversionAtDotP_a) + ARJ21_init_B.rw_tank_fuel_lb *
    rtb_dCG2AcFt_idx_2 * rtb_TmpSignalConversionAtDot_lg;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant10'
   *  Constant: '<S7>/Constant12'
   *  Constant: '<S7>/Constant13'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant5'
   *  Constant: '<S7>/Constant8'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S5>/Subtract1'
   *  Sum: '<S5>/Subtract2'
   *  Sum: '<S5>/Subtract4'
   */
  if (Flight_InertiaSelect >= 0.5) {
    rtb_Switch[0] = Flight_ixx;
    rtb_Switch[1] = Flight_iyy;
    rtb_Switch[2] = Flight_izz;
    rtb_Switch[3] = Flight_ixz;
    rtb_Switch[4] = 0.0;
    rtb_Switch[5] = 0.0;
  } else {
    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant2'
     */
    for (i = 0; i < 6; i++) {
      if (Flight_lgdown >= 0.5) {
        rtb_Subtract2[i] = ARJ21_init_ConstP.Constant1_Value_b[i];
      } else {
        rtb_Subtract2[i] = ARJ21_init_ConstP.Constant2_Value_e[i];
      }
    }

    /* End of Switch: '<S26>/Switch' */

    /* Sum: '<S5>/Subtract4' */
    rtb_Subtract2_0[0] = rtb_Subtract2[0];
    rtb_Subtract2_0[1] = rtb_Subtract2[1];
    rtb_Subtract2_0[2] = rtb_Subtract2[2];
    rtb_Subtract2_0[3] = rtb_Subtract2[3];
    rtb_Subtract2_0[4] = rtb_Subtract2[4];
    rtb_Subtract2_0[5] = rtb_Subtract2[5];

    /* Sum: '<S5>/Subtract1' incorporates:
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Ixx'
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Ixy'
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Ixz'
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Iyy'
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Iyz'
     *  Lookup_n-D: '<S25>/Mass_FuelLeft_Izz'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Ixx'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Ixy'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Ixz'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Iyy'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Iyz'
     *  Lookup_n-D: '<S28>/Mass_FuelRight_Izz'
     */
    tmp[0] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled6, 172U);
    tmp[1] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled5, 172U);
    tmp[2] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled4, 172U);
    tmp[3] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled3, 172U);
    tmp[4] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelLeft_Ixy_tableData,
      172U);
    tmp[5] = look1_binlxpw(ARJ21_init_B.lw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelLeft_Iyz_tableData,
      172U);
    tmp_0[0] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled6, 172U);
    tmp_0[1] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled5, 172U);
    tmp_0[2] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled4, 172U);
    tmp_0[3] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.pooled3, 172U);
    tmp_0[4] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelRight_Ixy_tableData,
      172U);
    tmp_0[5] = look1_binlxpw(ARJ21_init_B.rw_tank_fuel_lb,
      ARJ21_init_ConstP.pooled2, ARJ21_init_ConstP.Mass_FuelRight_Iyz_tableData,
      172U);
    for (i = 0; i < 6; i++) {
      rtb_Subtract2[i] = (tmp[i] + tmp_0[i]) + rtb_Subtract2_0[i];
    }

    rtb_Switch[0] = ARJ21_init_B.DotProduct1 + rtb_Subtract2[0];
    rtb_Switch[1] = ARJ21_init_B.DotProduct1_o + rtb_Subtract2[1];
    rtb_Switch[2] = ARJ21_init_B.DotProduct1_g + rtb_Subtract2[2];
    rtb_Switch[3] = ARJ21_init_B.SumofElements + rtb_Subtract2[3];
    rtb_Switch[4] = ARJ21_init_B.SumofElements_g + rtb_Subtract2[4];
    rtb_Switch[5] = ARJ21_init_B.SumofElements_d + rtb_Subtract2[5];
  }

  /* End of Switch: '<S7>/Switch' */

  /* Gain: '<S7>/const' */
  for (i = 0; i < 6; i++) {
    rtb_Subtract2[i] = 0.0002158403 * rtb_Switch[i];
  }

  /* End of Gain: '<S7>/const' */

  /* Concatenate: '<S7>/Matrix Concatenation' */
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[0] = rtb_Subtract2[0];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[3] = rtb_Subtract2[4];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[6] = rtb_Subtract2[3];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[1] = rtb_Subtract2[4];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[4] = rtb_Subtract2[1];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[7] = rtb_Subtract2[5];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[2] = rtb_Subtract2[3];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[5] = rtb_Subtract2[5];
  ARJ21_init_Y.Init.Init.InertiaSlugFt2[8] = rtb_Subtract2[2];

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant11'
   *  Constant: '<S8>/Constant22'
   *  Constant: '<S8>/Constant8'
   *  Constant: '<S8>/Constant9'
   *  Fcn: '<S8>/func4'
   */
  if (Flight_InertiaSelect >= 0.5) {
    rtb_dCG2AcFt_idx_0 = Flight_xcg;
    rtb_func3 = Flight_ycg;
    rtb_dCG2AcFt_idx_2 = Flight_zcg;
  } else {
    rtb_dCG2AcFt_idx_0 = (rtb_Product2 - 649.31931211679989) * 100.0 /
      136.07205159839998 + 25.0;
    rtb_dCG2AcFt_idx_2 = total_fuel_lb;
  }

  /* End of Switch: '<S8>/Switch' */

  /* BusCreator generated from: '<Root>/Init' incorporates:
   *  Fcn: '<S8>/func1'
   *  Fcn: '<S8>/func2'
   *  Fcn: '<S8>/func3'
   */
  ARJ21_init_Y.Init.Init.dCG2AcFt[0] = (rtb_dCG2AcFt_idx_0 - 25.0) / 100.0 *
    11.3393376332;
  ARJ21_init_Y.Init.Init.dCG2AcFt[1] = rtb_func3 / 12.0;
  ARJ21_init_Y.Init.Init.dCG2AcFt[2] = (rtb_dCG2AcFt_idx_2 - -14.781890236799999)
    / 12.0;

  /* Gain: '<S7>/Correction4' */
  ARJ21_init_B.IxxLbsInch2 = rtb_Switch[0];

  /* Gain: '<S7>/Correction5' */
  ARJ21_init_B.IyyLbsInch2 = rtb_Switch[1];

  /* Gain: '<S7>/Correction6' */
  ARJ21_init_B.IzzLbsInch2 = rtb_Switch[2];

  /* Gain: '<S7>/Correction7' */
  ARJ21_init_B.IxzLbsInch2 = rtb_Switch[3];

  /* Gain: '<S7>/Correction8' */
  ARJ21_init_B.IxyLbsInch2 = rtb_Switch[4];

  /* Gain: '<S7>/Correction9' */
  ARJ21_init_B.IyzLbsInch2 = rtb_Switch[5];

  /* Gain: '<S7>/Correction13' */
  ARJ21_init_B.WeightLb = ARJ21_init_B.conf_weight;

  /* BusCreator generated from: '<Root>/Init' */
  ARJ21_init_Y.Init.Init.CompWeights.conf_weight = ARJ21_init_B.conf_weight;
  ARJ21_init_Y.Init.Init.CompWeights.payload_lb = ARJ21_init_B.payload_lb;
  ARJ21_init_Y.Init.Init.CompWeights.lw_tank_fuel_lb =
    ARJ21_init_B.lw_tank_fuel_lb;
  ARJ21_init_Y.Init.Init.CompWeights.rw_tank_fuel_lb =
    ARJ21_init_B.rw_tank_fuel_lb;
  ARJ21_init_Y.Init.Init.CompWeights.owe_lb = ARJ21_init_B.owe_lb;
  ARJ21_init_Y.Init.Init.CompWeights.fuel_lb = ARJ21_init_B.fuel_lb;

  /* BusCreator generated from: '<Root>/Init' */
  ARJ21_init_Y.Init.Init.IxxLbsInch2 = ARJ21_init_B.IxxLbsInch2;
  ARJ21_init_Y.Init.Init.IyyLbsInch2 = ARJ21_init_B.IyyLbsInch2;
  ARJ21_init_Y.Init.Init.IzzLbsInch2 = ARJ21_init_B.IzzLbsInch2;
  ARJ21_init_Y.Init.Init.IxzLbsInch2 = ARJ21_init_B.IxzLbsInch2;
  ARJ21_init_Y.Init.Init.IxyLbsInch2 = ARJ21_init_B.IxyLbsInch2;
  ARJ21_init_Y.Init.Init.IyzLbsInch2 = ARJ21_init_B.IyzLbsInch2;
  ARJ21_init_Y.Init.Init.WeightLb = ARJ21_init_B.WeightLb;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Fcn: '<S1>/Fcn1'
   */
  ARJ21_init_B.Filter_Reset = (Flight_Trimming > 0.5);

  /* BusCreator generated from: '<Root>/Init' incorporates:
   *  Outport: '<Root>/Init'
   */
  ARJ21_init_Y.Init.Reset = ARJ21_init_B.Filter_Reset;

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant2'
   *  Inport: '<Root>/FuelFlowLbSec'
   *  Product: '<S31>/Product1'
   *  Sum: '<S31>/Sum2'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if (ARJ21_init_B.Filter_Reset > 0.5) {
    ARJ21_init_DW.UnitDelay_DSTATE = 0.0;
  } else {
    ARJ21_init_DW.UnitDelay_DSTATE += ARJ21_init_U.FuelFlowLbSec *
      0.0016666666666666668;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S31>/Const'
   *  RelationalOperator: '<S31>/Relational Operator'
   */
  if (1.0E+7 <= ARJ21_init_DW.UnitDelay_DSTATE) {
    ARJ21_init_DW.UnitDelay_DSTATE = 1.0E+7;
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Switch: '<S31>/Switch3' incorporates:
   *  Constant: '<S31>/Const1'
   *  RelationalOperator: '<S31>/Relational Operator1'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if (0.0 >= ARJ21_init_DW.UnitDelay_DSTATE) {
    ARJ21_init_DW.UnitDelay_DSTATE = 0.0;
  }

  /* End of Switch: '<S31>/Switch3' */
}

/* Model initialize function */
void ARJ21_init_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ARJ21_init_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
