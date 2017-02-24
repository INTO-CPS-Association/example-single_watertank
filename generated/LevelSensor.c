// The template for class
#include "LevelSensor.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void LevelSensor_free_fields(struct LevelSensor *this)
{
	}

static void LevelSensor_free(struct LevelSensor *this)
{
	--this->_LevelSensor_refs;
	if (this->_LevelSensor_refs < 1)
	{
		LevelSensor_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z17fieldInitializer8EV()	{

TVP ret_10 = newInt(0)
;

return ret_10;
}


/* LevelSensor.vdmrt 9:8 */
 static  TVP _Z8getLevelEV(LevelSensorCLASS this)	{
/* LevelSensor.vdmrt 12:8 */
//TVP ret_11 = GET_FIELD_GC(HardwareInterface, HardwareInterface, vdmCloneGC(g_System_hwi, NULL), level);
/* LevelSensor.vdmrt 12:1 */

uint16_t av = ReadADC(0);
return newReal((int16_t)av);


//return ret_11;
}



 void LevelSensor_const_init()	{

numFields_4 = _Z17fieldInitializer8EV();

return ;
}



 void LevelSensor_const_shutdown()	{

vdmFree(numFields_4);

return ;
}



 void LevelSensor_static_init()	{

return ;
}



 void LevelSensor_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForLevelSensor  [] ={

{0,0,((VirtualFunctionPointer) _Z8getLevelEV),},
{0,0,((VirtualFunctionPointer) _Z11LevelSensorEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
LevelSensorCLASS LevelSensor_Constructor(LevelSensorCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (LevelSensorCLASS) malloc(sizeof(struct LevelSensor));
	}

	if(this_ptr!=NULL)
	{
	
			
		// LevelSensor init
		this_ptr->_LevelSensor_id = CLASS_ID_LevelSensor_ID;
		this_ptr->_LevelSensor_refs = 0;
		this_ptr->_LevelSensor_pVTable=VTableArrayForLevelSensor;

				}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	LevelSensorCLASS ptr=LevelSensor_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_LevelSensor_id, &ptr->_LevelSensor_refs, (freeVdmClassFunction)&LevelSensor_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* LevelSensor.vdmrt 1:7 */
 TVP _Z11LevelSensorEV(LevelSensorCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, LevelSensor);
}
;

return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
	TVP numFields_4 =  NULL ;
	
