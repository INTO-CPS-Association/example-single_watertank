/*
 * watertankFmu.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: kel
 */
#include "Fmu.h"
#include "FmuModel.h"

#define PERIODIC_GENERATED



#include <stdarg.h>
#include "Fmu.h"
#include "Vdm.h"

#include "Port.h"
#include "IntPort.h"
#include "BoolPort.h"
#include "RealPort.h"
#include "StringPort.h"
#include "Controller.h"
#include "System.h"
#include "LevelSensor.h"
#include "World.h"
#include "ValveActuator.h"
#include "HardwareInterface.h"

TVP sys = NULL;
fmi2Boolean syncOutAllowed = fmi2True;


void syncInputsToModel(){
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[0]);
		TVP p = GET_FIELD(HardwareInterface,HardwareInterface,g_System_hwi,level);
		SET_FIELD(RealPort,RealPort,p,value,newValue);
		vdmFree(newValue);vdmFree(p);
	}
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[1]);
		SET_FIELD(RealPort,RealPort,g_HardwareInterface_minlevel,value,newValue);
		vdmFree(newValue);
	}
	{
		TVP newValue = newReal(fmiBuffer.realBuffer[2]);
		SET_FIELD(RealPort,RealPort,g_HardwareInterface_maxlevel,value,newValue);
		vdmFree(newValue);
	}
}
void syncOutputsToBuffers(){
	if(syncOutAllowed == fmi2False) return;

	{
		TVP p = GET_FIELD(HardwareInterface,HardwareInterface,g_System_hwi,valveState);
		TVP v = GET_FIELD(BoolPort,BoolPort,p,value);
		fmiBuffer.booleanBuffer[3]=v->value.boolVal;
		vdmFree(v);vdmFree(p);
	}
}
void periodic_taskg_System_controller__Z4loopEV()
{
	CALL_FUNC(Controller, Controller, g_System_controller, CLASS_Controller__Z4loopEV);
	g_fmiCallbackFunctions->logger((void*) 1, g_fmiInstanceName, fmi2OK, "logAll", "called &periodic_taskg_System_controller__Z4loopEV\n");
}


struct PeriodicThreadStatus threads[] ={
{ 1.0E7, &periodic_taskg_System_controller__Z4loopEV, 0 }
};


void systemInit()
{
	vdm_gc_init();

	int i;

	for(i = 0; i < PERIODIC_GENERATED_COUNT; i++) threads[i].period = threads[i].period / 1.0E9;

	Port_const_init();
	IntPort_const_init();
	BoolPort_const_init();
	RealPort_const_init();
	StringPort_const_init();
	Controller_const_init();
	System_const_init();
	LevelSensor_const_init();
	World_const_init();
	ValveActuator_const_init();
	HardwareInterface_const_init();

	Port_static_init();
	IntPort_static_init();
	BoolPort_static_init();
	RealPort_static_init();
	StringPort_static_init();
	Controller_static_init();
	System_static_init();
	LevelSensor_static_init();
	World_static_init();
	ValveActuator_static_init();
	HardwareInterface_static_init();

	sys = _Z6SystemEV(NULL);

}


void systemDeInit()
{
	Port_static_shutdown();
	IntPort_static_shutdown();
	BoolPort_static_shutdown();
	RealPort_static_shutdown();
	StringPort_static_shutdown();
	Controller_static_shutdown();
	System_static_shutdown();
	LevelSensor_static_shutdown();
	World_static_shutdown();
	ValveActuator_static_shutdown();
	HardwareInterface_static_shutdown();

	Port_const_shutdown();
	IntPort_const_shutdown();
	BoolPort_const_shutdown();
	RealPort_const_shutdown();
	StringPort_const_shutdown();
	Controller_const_shutdown();
	System_const_shutdown();
	LevelSensor_const_shutdown();
	World_const_shutdown();
	ValveActuator_const_shutdown();
	HardwareInterface_const_shutdown();

	vdmFree(sys);

	vdm_gc_shutdown();
}



/*
* Both time value are given in seconds
*/
fmi2Status vdmStep(fmi2Real currentCommunicationPoint, fmi2Real communicationStepSize)
{
	int i, j;
	int threadRunCount;


	//Call each thread the appropriate number of times.
	for(i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	{
		//Times align, sync took place last time.
		if(threads[i].lastExecuted >= currentCommunicationPoint)
		{
			//Can not do anything, still waiting for the last step's turn to come.
			if(threads[i].lastExecuted >= currentCommunicationPoint + communicationStepSize)
			{
				threadRunCount = 0;
				syncOutAllowed = fmi2False;
			}
			//Previous step will finish inside this step.
			//At least one execution can be fit inside this step.
			else if(threads[i].lastExecuted + threads[i].period <= currentCommunicationPoint + communicationStepSize)
			{
				//Find number of executions to fit inside of step, allow sync.
				threadRunCount = (currentCommunicationPoint + communicationStepSize - threads[i].lastExecuted) / threads[i].period;
				syncOutAllowed = fmi2True;
			}
			//Can not execute, but can sync existing values at the end of this step.
			else 
			{
				threadRunCount = 0;
				syncOutAllowed = fmi2True;
			}
		}
		else
		{
			//Find number of executions to fit inside of step, allow sync because need to update regardless.
			threadRunCount = (currentCommunicationPoint + communicationStepSize - threads[i].lastExecuted) / threads[i].period;
			syncOutAllowed = fmi2True;

			//Period too long for this step so postpone until next step.
			if(threadRunCount == 0)
			{
				syncOutAllowed = fmi2False;
			}
		}

			
		//printf("NOW:  %Lf, TP: %Lf, LE:  %Lf, STEP:  %Lf, SYNC:  %d, RUNS:  %d\n", currentCommunicationPoint / 1E9, threads[i].period / 1E9, threads[i].lastExecuted / 1E9, communicationStepSize / 1E9, syncOutAllowed, threadRunCount);
		//printf("NOW:  %f, TP: %f, LE:  %f, STEP:  %f, SYNC:  %d, RUNS:  %d\n", currentCommunicationPoint, threads[i].period, threads[i].lastExecuted, communicationStepSize, syncOutAllowed, threadRunCount);

		//Execute each thread the number of times that its period fits in the step size.
		for(j = 0; j < threadRunCount; j++)
		{
			threads[i].call();

			//Update the thread's last execution time.
			threads[i].lastExecuted += threads[i].period;
		}

		vdm_gc();
	}

	return fmi2OK;
}

void systemMain()
{
	TVP world = _Z5WorldEV(NULL);
	CALL_FUNC(World, World, world, CLASS_World__Z3runEV);
	vdmFree(world);
}
