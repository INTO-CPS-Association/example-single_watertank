/*
 * main.c
 *
 *  Created on: Sep 29, 2016
 *      Author: parallels
 */

#include <stdarg.h>

#define FATAL_ERROR(message)

#include "Vdm.h"
#include "Fmu.h"
#include "FmuModel.h"

#include "adcutil.h"
#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>

#define FMI_LEVEL_ID 0
#define FMI_VALVE_STATE 3

void fmuLoggerCache(void *componentEnvironment, fmi2String instanceName,
                    fmi2Status status, fmi2String category, fmi2String message,
                    ...) {}

int main() {
  DDRB = 0xff;
  PORTB = 0xff;

  InitADC();

  fmi2CallbackFunctions callback = {&fmuLoggerCache, NULL, NULL, NULL, NULL};
 
  //systemInit();

  //Initialize rest of the buffer.

	fmiBuffer.realBuffer[1] = 400.0;
	fmiBuffer.realBuffer[2] = 700.0;

   fmi2Component instReturn = fmi2Instantiate("this system", fmi2CoSimulation, _FMU_GUID, "", &callback, fmi2True,
                  fmi2True);

	if(instReturn == NULL)
		return 1;

  double now = 0;
  double step = 0.01;

  while (true) {
    // hardware sync inputs to buffer
    fmiBuffer.realBuffer[FMI_LEVEL_ID] = ReadADC(0);
	


    fmi2DoStep(NULL, now, step, false);
	
    now = now + step;

    // sync buffer with hardware
    if (fmiBuffer.booleanBuffer[FMI_VALVE_STATE]) {
		PORTB &= ~(1 << PINB3);
    } else {
      PORTB |= 1 << PINB3;
    }

    // alive indicator
    PORTB |= (1 << PINB0);
    _delay_ms(200);
    PORTB &= ~(1 << PINB0);
    _delay_ms(200);

    vdm_gc();
  }

  return 0;
}
