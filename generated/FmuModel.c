/*
 * watertankFmu.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: kel
 */
#include "Fmu.h"

#define PERIODIC_GENERATED


#include <stdarg.h>
#include "Fmu.h"
#include "Vdm.h"
#include "adcutil.h"

#include "Controller.h"
#include "HardwareInterface.h"
#include "LevelSensor.h"
#include "System.h"
#include "ValveActuator.h"
#include "World.h"
#include "IO.h"

TVP sys = NULL;


void syncInputsToModel(){
	
}
void syncOutputsToBuffers(){
	
}
#define PERIODIC_GENERATED_COUNT 0



struct PeriodicThreadStatus threads[] ={

};


void systemInit()
{
	Controller_const_init();
	HardwareInterface_const_init();
	LevelSensor_const_init();
	System_const_init();
	ValveActuator_const_init();
	World_const_init();
	IO_const_init();

	Controller_static_init();
	HardwareInterface_static_init();
	LevelSensor_static_init();
	System_static_init();
	ValveActuator_static_init();
	World_static_init();
	IO_static_init();

	sys = _Z6SystemEV(NULL);

}


void systemDeInit()
{
	Controller_static_shutdown();
	HardwareInterface_static_shutdown();
	LevelSensor_static_shutdown();
	System_static_shutdown();
	ValveActuator_static_shutdown();
	World_static_shutdown();
	IO_static_shutdown();

	Controller_const_shutdown();
	HardwareInterface_const_shutdown();
	LevelSensor_const_shutdown();
	System_const_shutdown();
	ValveActuator_const_shutdown();
	World_const_shutdown();
	IO_const_shutdown();

	vdmFree(sys);

}



/*
* Both time value are given in seconds
*/
fmi2Status vdmStep(fmi2Real currentCommunicationPoint, fmi2Real communicationStepSize)
{
	//convert seconds to nanoseconds
	currentCommunicationPoint = currentCommunicationPoint*1E9;
	communicationStepSize = communicationStepSize*1E9;

	int i, j;
	int threadRunCount;


	//We want to be able to align synchronization on either step size or thread boundary.
	for(i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	{
		if(
			(communicationStepSize >= threads[i].period) &&
			(((long long int) communicationStepSize) % ((long long int)threads[i].period) != 0))
		{
			return fmi2Discard;
		}
		else if(
			(threads[i].period >= communicationStepSize) &&
			(((long long int)threads[i].period) % ((long long int) communicationStepSize) != 0))
		{
			return fmi2Discard;
		}
	}


	//Call each thread the appropriate number of times.
	for(i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
	{
		if(communicationStepSize >= threads[i].period)
		{
			threadRunCount = ((long long int) communicationStepSize) / ((long long int)threads[i].period);
		}
		else
		{
			//Taking into account rounding errors.
			if(((long long int)currentCommunicationPoint) - 2 <= ((long long int)(threads[i].lastExecuted)) && ((long long int)(threads[i].lastExecuted) <= ((long long int)currentCommunicationPoint) + 2))
			{
				threadRunCount = 1;
			}
			else
			{
				threadRunCount = 0;
			}
		}

//		printf("THREAD COUNT:  %d\nSTEP SIZE:  %lf\nCURRENT POINT:  %lf\nTHREAD PERIOD:  %llf\nLAST EXECUTED %llf\n", threadRunCount, communicationStepSize, currentCommunicationPoint, threads[i].period, threads[i].lastExecuted);

		//Execute each thread the number of times that its period fits in the step size.
		for(j = 0; j < threadRunCount; j++)
		{
			threads[i].call();
//			printf("RUN THREAD AT %lf\n", currentCommunicationPoint / 1E9);

			//Update the thread's last execution time.
			threads[i].lastExecuted += threads[i].period;
		}
	}

	return fmi2OK;
}

void systemMain()
{
	TVP world = _Z5WorldEV(NULL);
	CALL_FUNC(World, World, world, CLASS_World__Z3runEV);
	vdmFree(world);
}


#ifdef PERIODIC_GENERATED


void fmuLoggerCache(void *componentEnvironment, fmi2String instanceName, fmi2Status status, fmi2String category,
                    fmi2String message, ...)
{
    va_list(args);
    
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
}

int main()
{
	vdm_gc_init();

	DDRB = 0xff;
	PORTB = 0xff;

    InitADC();
	
    fmi2CallbackFunctions callback={&fmuLoggerCache,NULL,NULL,NULL,NULL};
    
    fmi2Instantiate("this system",fmi2CoSimulation,"","",&callback,fmi2True,fmi2True);
    systemInit();
    syncInputsToModel();
    
    double stepSize = 0;
    double totalTime = 10E9;
    
    
    for(int i = 0;  i < PERIODIC_GENERATED_COUNT; i++)
    {
        if(stepSize < threads[i].period)
        {
            stepSize = threads[i].period;
        }
    }
    
    //convert to seconds
    stepSize = stepSize / 1E9;
    
    printf("Stepsize is: %f seconds.\n",stepSize);
    
    for (double time =0; time < totalTime; time=time+stepSize) {
    printf("Stepping... \n");
        
            if(fmi2OK !=fmi2DoStep(NULL,time,stepSize,fmi2False))
            {
                printf("Step did not return ok\n");
                return 1;
            }

	PORTB |= (1 << PINB0);
        _delay_ms(200);
        PORTB &= ~(1 << PINB0);
        _delay_ms(200);
	    
	    printf("Calling GC.\n");
	    vdm_gc();
    }
    printf("Done\n");
    vdm_gc_shutdown();
  
}


#endif
