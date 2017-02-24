// The template for class header
#ifndef CLASSES_LevelSensor_H_
#define CLASSES_LevelSensor_H_

#define VDM_CG

#include "Vdm.h"

//include types used in the class
#include "HardwareInterface.h"
#include "LevelSensor.h"
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
 
extern TVP numFields_4;


/* -------------------------------
 *
 * The class
 *
 --------------------------------- */ 
 

//class id
#define CLASS_ID_LevelSensor_ID 3

#define LevelSensorCLASS struct LevelSensor*

// The vtable ids
#define CLASS_LevelSensor__Z8getLevelEV 0
#define CLASS_LevelSensor__Z11LevelSensorEV 1

struct LevelSensor
{
	
/* Definition of Class: 'LevelSensor' */
	VDM_CLASS_BASE_DEFINITIONS(LevelSensor);
	 
	VDM_CLASS_FIELD_DEFINITION(LevelSensor,numFields);

};


/* -------------------------------
 *
 * Constructors
 *
 --------------------------------- */ 
 

	/* LevelSensor.vdmrt 1:7 */
	TVP _Z11LevelSensorEV(LevelSensorCLASS this_);


/* -------------------------------
 *
 * public access functions
 *
 --------------------------------- */ 
 
	void LevelSensor_const_init();
	void LevelSensor_const_shutdown();
	void LevelSensor_static_init();
	void LevelSensor_static_shutdown();


/* -------------------------------
 *
 * Internal
 *
 --------------------------------- */ 
 

void LevelSensor_free_fields(LevelSensorCLASS);
LevelSensorCLASS LevelSensor_Constructor(LevelSensorCLASS);



#endif /* CLASSES_LevelSensor_H_ */