/**
* This file is generated by Overture's VDM-to-C code generator version 0.1.3-SNAPSHOT.
* Website: https://github.com/overturetool/vdm2c
*/

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
				vdmFree(this->m_System_levelSensor);
			vdmFree(this->m_System_valveActuator);
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
 

 static  TVP _Z18fieldInitializer11EV()	{
/* System.vdmrt 13:46 */
TVP ret_13 = NULL
;

return ret_13;
}



 static  TVP _Z18fieldInitializer10EV()	{
/* System.vdmrt 6:41 */
TVP ret_14 = _Z17HardwareInterfaceEV(NULL)
;

return ret_14;
}



 static  TVP _Z17fieldInitializer9EV()	{

TVP ret_15 = newInt(4)
;

return ret_15;
}



 void System_const_init()	{

numFields_3 = _Z17fieldInitializer9EV();

return ;
}



 void System_const_shutdown()	{

vdmFree(numFields_3);

return ;
}



 void System_static_init()	{

g_System_hwi = _Z18fieldInitializer10EV();

g_System_controller = _Z18fieldInitializer11EV();

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

										this_ptr->m_System_levelSensor= NULL ;
						this_ptr->m_System_valveActuator= NULL ;
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
 

/* System.vdmrt 18:8 */
 TVP _Z6SystemEV(SystemCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, System);
}
;
/* System.vdmrt 21:20 */
TVP field_tmp_7 = _Z11LevelSensorE8CRealPort(NULL, GET_FIELD_GC(HardwareInterface, HardwareInterface, vdmCloneGC(g_System_hwi, NULL), level))
;

SET_FIELD_PTR_GC(System, System, this, levelSensor, field_tmp_7);

vdmFree(field_tmp_7);
/* System.vdmrt 22:23 */
TVP field_tmp_8 = _Z13ValveActuatorE4CPort(NULL, GET_FIELD_GC(HardwareInterface, HardwareInterface, vdmCloneGC(g_System_hwi, NULL), valveState))
;

SET_FIELD_PTR_GC(System, System, this, valveActuator, field_tmp_8);

vdmFree(field_tmp_8);
/* System.vdmrt 24:5 */
g_System_controller = _Z10ControllerE11CLevelSensor13CValveActuator(NULL, GET_FIELD_PTR_GC(System, System, this, levelSensor), GET_FIELD_PTR_GC(System, System, this, valveActuator));

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
	