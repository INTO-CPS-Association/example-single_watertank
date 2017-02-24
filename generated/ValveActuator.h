// The template for class header
#ifndef CLASSES_ValveActuator_H_
#define CLASSES_ValveActuator_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "HardwareInterface.h"
#include "IO.h"
#include "ValveActuator.h"
#include "System.h"


/* -------------------------------
 *
 * Quotes
 *
 --------------------------------- */ 
 


/* -------------------------------
 *
 * values / global const
 *
 --------------------------------- */ 
 
extern TVP numFields_6;


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_ValveActuator_ID 5

#define ValveActuatorCLASS struct ValveActuator*

// The vtable ids
#define CLASS_ValveActuator__Z8setValveEB 0
#define CLASS_ValveActuator__Z13ValveActuatorEV 1

struct ValveActuator
{
	
/* Definition of Class: 'ValveActuator' */
	VDM_CLASS_BASE_DEFINITIONS(ValveActuator);
	 
	VDM_CLASS_FIELD_DEFINITION(ValveActuator,numFields);

};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* ValveActuator.vdmrt 1:7 */
	TVP _Z13ValveActuatorEV(ValveActuatorCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void ValveActuator_const_init();
	void ValveActuator_const_shutdown();
	void ValveActuator_static_init();
	void ValveActuator_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void ValveActuator_free_fields(ValveActuatorCLASS);
ValveActuatorCLASS ValveActuator_Constructor(ValveActuatorCLASS);



#endif /* CLASSES_ValveActuator_H_ */