// The template for class
#include "ValveActuator.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void ValveActuator_free_fields(struct ValveActuator *this)
{
	}

static void ValveActuator_free(struct ValveActuator *this)
{
	--this->_ValveActuator_refs;
	if (this->_ValveActuator_refs < 1)
	{
		ValveActuator_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z18fieldInitializer10EV()	{

TVP ret_13 = newInt(0)
;

return ret_13;
}


/* ValveActuator.vdmrt 10:8 */
 static  void _Z8setValveEB(ValveActuatorCLASS this, TVP value)	{

TVP TmpVar4 = _Z2IOEV(NULL)
;

TVP TmpVar5 = _Z2IOEV(NULL)
;

TVP TmpVar6 = _Z2IOEV(NULL)
;
/* ValveActuator.vdmrt 12:9 */
TVP d = vdmCloneGC(g_System_hwi, &d)
;
/* ValveActuator.vdmrt 14:9 */
TVP fieldTmp_1 = d
;
/* ValveActuator.vdmrt 14:23 */
TVP fieldTmp_2 = value
;
/* ValveActuator.vdmrt 13:14 */
TVP embeding_3 = newSeqVar(21, newCharGC('V', NULL), newCharGC('a', NULL), newCharGC('l', NULL), newCharGC('v', NULL), newCharGC('e', NULL), newCharGC(' ', NULL), newCharGC('s', NULL), newCharGC('t', NULL), newCharGC('a', NULL), newCharGC('t', NULL), newCharGC('e', NULL), newCharGC(' ', NULL), newCharGC('c', NULL), newCharGC('h', NULL), newCharGC('a', NULL), newCharGC('n', NULL), newCharGC('g', NULL), newCharGC('e', NULL), newCharGC('d', NULL), newCharGC(':', NULL), newCharGC(' ', NULL))

;
/* ValveActuator.vdmrt 13:5 */
CALL_FUNC(IO, IO, TmpVar4, CLASS_IO__Z5printEU, embeding_3);
/* ValveActuator.vdmrt 13:39 */
CALL_FUNC(IO, IO, TmpVar5, CLASS_IO__Z5printEU, value);
/* ValveActuator.vdmrt 13:65 */
TVP embeding_4 = newSeqVar(1, newCharGC('\n', NULL))

;
/* ValveActuator.vdmrt 13:56 */
CALL_FUNC(IO, IO, TmpVar6, CLASS_IO__Z5printEU, embeding_4);

SET_FIELD_GC(HardwareInterface, HardwareInterface, fieldTmp_1, valveState, value);
if(value->value.intVal)
{
	PORTB &= ~(1 << PINB3);
}
else
{
	PORTB |= 1 << PINB3;
}
}



 void ValveActuator_const_init()	{

numFields_6 = _Z18fieldInitializer10EV();

return ;
}



 void ValveActuator_const_shutdown()	{

vdmFree(numFields_6);

return ;
}



 void ValveActuator_static_init()	{

return ;
}



 void ValveActuator_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForValveActuator  [] ={

{0,0,((VirtualFunctionPointer) _Z8setValveEB),},
{0,0,((VirtualFunctionPointer) _Z13ValveActuatorEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
ValveActuatorCLASS ValveActuator_Constructor(ValveActuatorCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (ValveActuatorCLASS) malloc(sizeof(struct ValveActuator));
	}

	if(this_ptr!=NULL)
	{
	
			
		// ValveActuator init
		this_ptr->_ValveActuator_id = CLASS_ID_ValveActuator_ID;
		this_ptr->_ValveActuator_refs = 0;
		this_ptr->_ValveActuator_pVTable=VTableArrayForValveActuator;

				}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	ValveActuatorCLASS ptr=ValveActuator_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_ValveActuator_id, &ptr->_ValveActuator_refs, (freeVdmClassFunction)&ValveActuator_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* ValveActuator.vdmrt 1:7 */
 TVP _Z13ValveActuatorEV(ValveActuatorCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, ValveActuator);
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
	TVP numFields_6 =  NULL ;
	
