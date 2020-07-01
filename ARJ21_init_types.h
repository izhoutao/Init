/*
 * File: ARJ21_init_types.h
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

#ifndef RTW_HEADER_ARJ21_init_types_h_
#define RTW_HEADER_ARJ21_init_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CompWeights_t_
#define DEFINED_TYPEDEF_FOR_CompWeights_t_

typedef struct {
  real_T conf_weight;
  real_T payload_lb;
  real_T lw_tank_fuel_lb;
  real_T rw_tank_fuel_lb;
  real_T owe_lb;
  real_T fuel_lb;
} CompWeights_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Init_t_
#define DEFINED_TYPEDEF_FOR_Init_t_

typedef struct {
  real_T dCG2AcFt[3];
  real_T IxxLbsInch2;
  real_T IyyLbsInch2;
  real_T IzzLbsInch2;
  real_T IxzLbsInch2;
  real_T IxyLbsInch2;
  real_T IyzLbsInch2;
  real_T WeightLb;
  real_T InertiaSlugFt2[9];
  CompWeights_t CompWeights;
} Init_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_StartupBus_
#define DEFINED_TYPEDEF_FOR_StartupBus_

typedef struct {
  Init_t Init;
  real_T Reset;
} StartupBus;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ARJ21_init_T RT_MODEL_ARJ21_init_T;

#endif                                 /* RTW_HEADER_ARJ21_init_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
