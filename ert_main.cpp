/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ARJ21_init'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Jun 17 15:37:04 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "ARJ21_init.h"                /* Model's header file */
#include "rtwtypes.h"
#include "Utils.h"
#include "SimConfig.h"

 /*
  * Associating rt_OneStep with a real-time clock or interrupt service routine
  * is what makes the generated code "real-time".  The function rt_OneStep is
  * always associated with the base rate of the model.  Subrates are managed
  * by the base rate from inside the generated code.  Enabling/disabling
  * interrupts and floating point context switches are target specific.  This
  * example code indicates where these should take place relative to executing
  * the generated code step function.  Overrun behavior should be tailored to
  * your application needs.  This example simply sets an error status in the
  * real-time model and returns from rt_OneStep.
  */
void rt_OneStep(void);
void rt_OneStep(void)
{
	static boolean_T OverrunFlag = false;

	/* Disable interrupts here */

	/* Check for overrun */
	if (OverrunFlag) {
		rtmSetErrorStatus(ARJ21_init_M, "Overrun");
		return;
	}

	OverrunFlag = true;

	/* Save FPU context here (if necessary) */
	/* Re-enable timer or interrupt here */
	/* Set model inputs here */

	/* Step the model */
	ARJ21_init_step();

	/* Get model outputs here */

	/* Indicate task complete */
	OverrunFlag = false;

	/* Disable interrupts here */
	/* Restore FPU context here (if necessary) */
	/* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char* argv[])
{
	/* Unused arguments */
	//(void)(argc);
	//(void)(argv);
	string configFile;
	if (argc > 1) {
		cout << argv[1];
		configFile = string(argv[1]);
	}
	else {
		cout << "Invalid command" << endl;
		cout << "usage: Init 'configFile'";
		return -1;
	}
	cout << configFile;
	/* Initialize model */
	ARJ21_init_initialize();
	
	/* Load simulation config and initialize simulation environment */
	SimConfig config;
	config.readConfig(configFile);
	Utils utils(config);
	utils.readManeuverFile();
	utils.readSaveListFile();
	ofstream o;	
	o.open(configFile.substr(0, configFile.rfind(".")) + ".output");
	if (!o.is_open())
	{
		cout << "open file savedSignals.txt has failed!" << endl;
	}
	/* Simulate model and save outputs */
	o << "T";
	utils.saveSignalNames(o);
	utils.execSimulation(rt_OneStep, o);
	o.close();
	///* Attach rt_OneStep to a timer or interrupt service routine with
	// * period 0.0016666666666666668 seconds (the model's base sample time) here.  The
	// * call syntax for rt_OneStep is
	// *
	// *  rt_OneStep();
	// */
	//printf("Warning: The simulation will run forever. "
	//       "Generated ERT main won't simulate model step behavior. "
	//       "To change this behavior select the 'MAT-file logging' option.\n");
	//fflush((NULL));
	//while (rtmGetErrorStatus(ARJ21_init_M) == (NULL)) {
	//  /*  Perform other application tasks here */
	//}

	/* Disable rt_OneStep() here */
	/* Terminate model */
	ARJ21_init_terminate();
	return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
