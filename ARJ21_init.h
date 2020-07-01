/*
 * File: ARJ21_init.h
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

#ifndef RTW_HEADER_ARJ21_init_h_
#define RTW_HEADER_ARJ21_init_h_
#include <math.h>
#ifndef ARJ21_init_COMMON_INCLUDES_
# define ARJ21_init_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ARJ21_init_COMMON_INCLUDES_ */

#include "ARJ21_init_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T owe_lb;                       /* '<S30>/Correction7' */
  real_T payload_lb;                   /* '<S30>/Correction1' */
  real_T lw_tank_fuel_lb;              /* '<S30>/Correction2' */
  real_T rw_tank_fuel_lb;              /* '<S30>/Correction3' */
  real_T conf_weight;                  /* '<S30>/Correction4' */
  real_T DotProduct1;                  /* '<S10>/Dot Product1' */
  real_T DotProduct1_o;                /* '<S13>/Dot Product1' */
  real_T DotProduct1_g;                /* '<S15>/Dot Product1' */
  real_T SumofElements;                /* '<S12>/Sum of Elements' */
  real_T SumofElements_g;              /* '<S11>/Sum of Elements' */
  real_T SumofElements_d;              /* '<S14>/Sum of Elements' */
  real_T IxxLbsInch2;                  /* '<S7>/Correction4' */
  real_T IyyLbsInch2;                  /* '<S7>/Correction5' */
  real_T IzzLbsInch2;                  /* '<S7>/Correction6' */
  real_T IxzLbsInch2;                  /* '<S7>/Correction7' */
  real_T IxyLbsInch2;                  /* '<S7>/Correction8' */
  real_T IyzLbsInch2;                  /* '<S7>/Correction9' */
  real_T WeightLb;                     /* '<S7>/Correction13' */
  real_T fuel_lb;                      /* '<S30>/Correction5' */
  real_T Filter_Reset;                 /* '<S1>/Data Type Conversion' */
} B_ARJ21_init_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S31>/Unit Delay' */
} DW_ARJ21_init_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Mass_FuelRight_Iyz
   * Referenced by: '<S28>/Mass_FuelRight_Iyz'
   */
  real_T Mass_FuelRight_Iyz_tableData[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S19>/Mass_FuelLeft_xcg'
   *   '<S19>/Mass_FuelLeft_ycg'
   *   '<S19>/Mass_FuelLeft_zcg'
   *   '<S22>/Mass_FuelRight_xcg'
   *   '<S22>/Mass_FuelRight_ycg'
   *   '<S22>/Mass_FuelRight_zcg'
   *   '<S25>/Mass_FuelLeft_Ixx'
   *   '<S25>/Mass_FuelLeft_Ixy'
   *   '<S25>/Mass_FuelLeft_Ixz'
   *   '<S25>/Mass_FuelLeft_Iyy'
   *   '<S25>/Mass_FuelLeft_Iyz'
   *   '<S25>/Mass_FuelLeft_Izz'
   *   '<S28>/Mass_FuelRight_Ixx'
   *   '<S28>/Mass_FuelRight_Ixy'
   *   '<S28>/Mass_FuelRight_Ixz'
   *   '<S28>/Mass_FuelRight_Iyy'
   *   '<S28>/Mass_FuelRight_Iyz'
   *   '<S28>/Mass_FuelRight_Izz'
   */
  real_T pooled2[173];

  /* Expression: Mass_FuelRight_Ixy
   * Referenced by: '<S28>/Mass_FuelRight_Ixy'
   */
  real_T Mass_FuelRight_Ixy_tableData[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S25>/Mass_FuelLeft_Ixz'
   *   '<S28>/Mass_FuelRight_Ixz'
   */
  real_T pooled3[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S25>/Mass_FuelLeft_Izz'
   *   '<S28>/Mass_FuelRight_Izz'
   */
  real_T pooled4[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S25>/Mass_FuelLeft_Iyy'
   *   '<S28>/Mass_FuelRight_Iyy'
   */
  real_T pooled5[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S25>/Mass_FuelLeft_Ixx'
   *   '<S28>/Mass_FuelRight_Ixx'
   */
  real_T pooled6[173];

  /* Expression: Mass_FuelLeft_Iyz
   * Referenced by: '<S25>/Mass_FuelLeft_Iyz'
   */
  real_T Mass_FuelLeft_Iyz_tableData[173];

  /* Expression: Mass_FuelLeft_Ixy
   * Referenced by: '<S25>/Mass_FuelLeft_Ixy'
   */
  real_T Mass_FuelLeft_Ixy_tableData[173];

  /* Expression: [Mass_OWElgDown_Ixx Mass_OWElgDown_Iyy Mass_OWElgDown_Izz Mass_OWElgDown_Ixz Mass_OWElgDown_Ixy Mass_OWElgDown_Iyz]
   * Referenced by: '<S26>/Constant1'
   */
  real_T Constant1_Value_b[6];

  /* Expression: [Mass_OWElgUp_Ixx Mass_OWElgUp_Iyy Mass_OWElgUp_Izz Mass_OWElgUp_Ixz Mass_OWElgUp_Ixy Mass_OWElgUp_Iyz]
   * Referenced by: '<S26>/Constant2'
   */
  real_T Constant2_Value_e[6];

  /* Expression: Mass_FuelLeft_ycg
   * Referenced by: '<S19>/Mass_FuelLeft_ycg'
   */
  real_T Mass_FuelLeft_ycg_tableData[173];

  /* Expression: Mass_FuelRight_ycg
   * Referenced by: '<S22>/Mass_FuelRight_ycg'
   */
  real_T Mass_FuelRight_ycg_tableData[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S19>/Mass_FuelLeft_zcg'
   *   '<S22>/Mass_FuelRight_zcg'
   */
  real_T pooled10[173];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S19>/Mass_FuelLeft_xcg'
   *   '<S22>/Mass_FuelRight_xcg'
   */
  real_T pooled11[173];
} ConstP_ARJ21_init_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T FuelFlowLbSec;                /* '<Root>/FuelFlowLbSec' */
} ExtU_ARJ21_init_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  StartupBus Init;                     /* '<Root>/Init' */
} ExtY_ARJ21_init_T;

/* Real-time Model Data Structure */
struct tag_RTM_ARJ21_init_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_ARJ21_init_T ARJ21_init_B;

/* Block states (default storage) */
extern DW_ARJ21_init_T ARJ21_init_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ARJ21_init_T ARJ21_init_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ARJ21_init_T ARJ21_init_Y;

/* Constant parameters (default storage) */
extern const ConstP_ARJ21_init_T ARJ21_init_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Flight_InertiaSelect;    /* Variable: Flight_InertiaSelect
                                        * Referenced by:
                                        *   '<S7>/Constant2'
                                        *   '<S8>/Constant22'
                                        * For InertiaSelect. Default=0
                                          1: Inertia values are provided
                                          0: Inertia are computed in the model from weight and CG.
                                        */
extern real_T Flight_Trimming;         /* Variable: Flight_Trimming
                                        * Referenced by: '<S1>/Constant1'
                                        * Trimming flag. Default=0
                                        */
extern real_T Flight_ixx;              /* Variable: Flight_ixx
                                        * Referenced by: '<S7>/Constant1'
                                        * Ixx moment of inertia
                                        */
extern real_T Flight_ixz;              /* Variable: Flight_ixz
                                        * Referenced by: '<S7>/Constant13'
                                        * Ixz moment of inertia
                                        */
extern real_T Flight_iyy;              /* Variable: Flight_iyy
                                        * Referenced by: '<S7>/Constant10'
                                        * Iyy moment of inertia
                                        */
extern real_T Flight_izz;              /* Variable: Flight_izz
                                        * Referenced by: '<S7>/Constant12'
                                        * Izz moment of inertia
                                        */
extern real_T Flight_lgdown;           /* Variable: Flight_lgdown
                                        * Referenced by:
                                        *   '<S20>/Constant'
                                        *   '<S26>/Constant'
                                        *   '<S30>/Constant'
                                        * Landing Gear Up/Dn. Default=0
                                        */
extern real_T Flight_lw_fuel;          /* Variable: Flight_lw_fuel
                                        * Referenced by: '<S29>/Constant2'
                                        * Left main fuel weight.
                                        */
extern real_T Flight_rw_fuel;          /* Variable: Flight_rw_fuel
                                        * Referenced by: '<S29>/Constant3'
                                        * Right main fuel weight.
                                        */
extern real_T Flight_weight;           /* Variable: Flight_weight
                                        * Referenced by:
                                        *   '<S29>/Constant1'
                                        *   '<S23>/Constant1'
                                        *   '<S24>/Constant1'
                                        * Aircraft weight. Default=
                                        */
extern real_T Flight_xcg;              /* Variable: Flight_xcg
                                        * Referenced by:
                                        *   '<S8>/Constant11'
                                        *   '<S23>/Constant4'
                                        * Aircraft center of gravity position along X axis. Default=25
                                        */
extern real_T Flight_ycg;              /* Variable: Flight_ycg
                                        * Referenced by:
                                        *   '<S8>/Constant8'
                                        *   '<S24>/Constant4'
                                        * Aircraft center of gravity position along Y axis. Default=0
                                        */
extern real_T Flight_zcg;              /* Variable: Flight_zcg
                                        * Referenced by: '<S8>/Constant9'
                                        * Aircraft center of gravity position along Z axis. Default= 0
                                        */

/* Model entry point functions */
extern void ARJ21_init_initialize(void);
extern void ARJ21_init_step(void);
extern void ARJ21_init_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ARJ21_init_T *const ARJ21_init_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Gain' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain18' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain19' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain20' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain4' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain6' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain7' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain8' : Eliminated nontunable gain of 1
 * Block '<S7>/Reshape' : Reshape block reduction
 * Block '<S7>/Reshape1' : Reshape block reduction
 * Block '<S7>/Reshape2' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ARJ21_init'
 * '<S1>'   : 'ARJ21_init/Subsystem'
 * '<S2>'   : 'ARJ21_init/Trim_Init'
 * '<S3>'   : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia'
 * '<S4>'   : 'ARJ21_init/Trim_Init/Comp CGs'
 * '<S5>'   : 'ARJ21_init/Trim_Init/Comp Inertia'
 * '<S6>'   : 'ARJ21_init/Trim_Init/CompWeights'
 * '<S7>'   : 'ARJ21_init/Trim_Init/Inertia output'
 * '<S8>'   : 'ARJ21_init/Trim_Init/dCG2AcFt'
 * '<S9>'   : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/AC cg'
 * '<S10>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Ixx'
 * '<S11>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Ixy'
 * '<S12>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Ixz'
 * '<S13>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Iyy'
 * '<S14>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Iyz'
 * '<S15>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/Izz'
 * '<S16>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/AC cg/BLCG'
 * '<S17>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/AC cg/FSCG'
 * '<S18>'  : 'ARJ21_init/Trim_Init/AC cg and Transform Inertia/AC cg/WLCG'
 * '<S19>'  : 'ARJ21_init/Trim_Init/Comp CGs/LeftFuel CG'
 * '<S20>'  : 'ARJ21_init/Trim_Init/Comp CGs/OWE CG'
 * '<S21>'  : 'ARJ21_init/Trim_Init/Comp CGs/Payload CG'
 * '<S22>'  : 'ARJ21_init/Trim_Init/Comp CGs/RightFuel CG'
 * '<S23>'  : 'ARJ21_init/Trim_Init/Comp CGs/Payload CG/XcgPayload'
 * '<S24>'  : 'ARJ21_init/Trim_Init/Comp CGs/Payload CG/YcgPayload'
 * '<S25>'  : 'ARJ21_init/Trim_Init/Comp Inertia/Left'
 * '<S26>'  : 'ARJ21_init/Trim_Init/Comp Inertia/OWE'
 * '<S27>'  : 'ARJ21_init/Trim_Init/Comp Inertia/Payload'
 * '<S28>'  : 'ARJ21_init/Trim_Init/Comp Inertia/Right'
 * '<S29>'  : 'ARJ21_init/Trim_Init/CompWeights/Subsystem'
 * '<S30>'  : 'ARJ21_init/Trim_Init/CompWeights/Subsystem1'
 * '<S31>'  : 'ARJ21_init/Trim_Init/CompWeights/Subsystem/Subsystem'
 * '<S32>'  : 'ARJ21_init/Trim_Init/CompWeights/Subsystem1/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_ARJ21_init_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
