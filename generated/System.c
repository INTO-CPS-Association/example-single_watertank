// The template for class
#include "System.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void System_free_fields(struct System *this)
{
			}

static void System_free(struct System *this)
{
	--this->_System_refs;
	if (this->_System_refs < 1)
	{
		System_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z17fieldInitializer7EV()	{
/* System.vdmrt 11:46 */
TVP ret_7 = NULL
;

return ret_7;
}



 static  TVP _Z17fieldInitializer6EV()	{
/* System.vdmrt 6:41 */
TVP ret_8 = _Z17HardwareInterfaceEV(NULL)
;

return ret_8;
}



 static  TVP _Z17fieldInitializer5EV()	{

TVP ret_9 = newInt(2)
;

return ret_9;
}



 void System_const_init()	{

numFields_3 = _Z17fieldInitializer5EV();

return ;
}



 void System_const_shutdown()	{

vdmFree(numFields_3);

return ;
}



 void System_static_init()	{

g_System_hwi = _Z17fieldInitializer6EV();

g_System_controller = _Z17fieldInitializer7EV();

return ;
}



 void System_static_shutdown()	{

vdmFree(g_System_hwi);

vdmFree(g_System_controller);

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForSystem  [] ={

{0,0,((VirtualFunctionPointer) _Z6SystemEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
SystemCLASS System_Constructor(SystemCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (SystemCLASS) malloc(sizeof(struct System));
	}

	if(this_ptr!=NULL)
	{
	
			
		// System init
		this_ptr->_System_id = CLASS_ID_System_ID;
		this_ptr->_System_refs = 0;
		this_ptr->_System_pVTable=VTableArrayForSystem;

										}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	SystemCLASS ptr=System_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_System_id, &ptr->_System_refs, (freeVdmClassFunction)&System_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* System.vdmrt 16:8 */
 TVP _Z6SystemEV(SystemCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, System);
}
;
/* System.vdmrt 19:9 */
TVP levelSensor = _Z11LevelSensorEV(NULL)
;
/* System.vdmrt 20:13 */
TVP valveActuator = _Z13ValveActuatorEV(NULL)
;
/* System.vdmrt 22:9 */
g_System_controller = _Z10ControllerE11CLevelSensor13CValveActuator(NULL, levelSensor, valveActuator);

return __buf;
}




/* -------------------------------
 *
 * Global class fields
 *
 --------------------------------- */
 
// initialize globals - this is done last since they are declared in the header but uses init functions which are printet in any order
	TVP numFields_3 =  NULL ;
		TVP g_System_hwi =  NULL ;
		TVP g_System_controller =  NULL ;
	
