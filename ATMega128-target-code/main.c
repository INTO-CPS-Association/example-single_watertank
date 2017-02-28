/*
 * main.c
 *
 *  Created on: Sep 29, 2016
 *      Author: parallels
 */

#include <stdarg.h>

#include "Vdm.h"
#include "VdmModel.h"

#include "adcutil.h"
#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>



int main()
{
	DDRB = 0xff;
	PORTB = 0xff;

	InitADC();

	fmi2CallbackFunctions callback={&fmuLoggerCache,NULL,NULL,NULL,NULL};
	fmi2Instantiate("this system",fmi2CoSimulation,"","",&callback,fmi2True,fmi2True);
	systemInit();

	double now = 0;
	double step = 0.001;

	while (true)
	{
		//hardware sync inputs to buffer
		fmiBuffer.realBuffer[_A_MISSING_ID_FOR_LEVEL]=ReadADC(0);
		
		fmi2DoStep(NULL, now, step);
		now = now + step;

		//sync buffer with hardware
		if( fmiBuffer.boolBuffer[_A_MISSING_ID_FOR_VALVE] )
		{
			PORTB &= ~(1 << PINB3);
		}else
		{
			PORTB |= 1 << PINB3;
		}

		//alive indicator
		PORTB |= (1 << PINB0);
		_delay_ms(200);
		PORTB &= ~(1 << PINB0);
		_delay_ms(200);

		vdm_gc();
	}

	return 0;
}
