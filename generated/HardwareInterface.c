// The template for class
#include "HardwareInterface.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void HardwareInterface_free_fields(struct HardwareInterface *this)
{
					vdmFree(this->m_HardwareInterface_level);
			vdmFree(this->m_HardwareInterface_valveState);
	}

static void HardwareInterface_free(struct HardwareInterface *this)
{
	--this->_HardwareInterface_refs;
	if (this->_HardwareInterface_refs < 1)
	{
		HardwareInterface_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z18fieldInitializer15EV()	{
/* HardwareInterface.vdmrt 19:33 */
TVP ret_14 = newBool(false)
;

return ret_14;
}



 static  TVP _Z18fieldInitializer14EV()	{
/* HardwareInterface.vdmrt 14:28 */
TVP ret_15 = newReal(0.0)
;

return ret_15;
}



 static  TVP _Z18fieldInitializer13EV()	{
/* HardwareInterface.vdmrt 9:30 */
TVP ret_16 = newReal(2.0)
;

return ret_16;
}



 static  TVP _Z18fieldInitializer12EV()	{
/* HardwareInterface.vdmrt 7:30 */
TVP ret_17 = newReal(1.0)
;

return ret_17;
}



 static  TVP _Z18fieldInitializer11EV()	{

TVP ret_18 = newInt(4)
;

return ret_18;
}



 void HardwareInterface_const_init()	{

numFields_7 = _Z18fieldInitializer11EV();

g_HardwareInterface_minlevel = _Z18fieldInitializer12EV();

g_HardwareInterface_maxlevel = _Z18fieldInitializer13EV();

return ;
}



 void HardwareInterface_const_shutdown()	{

vdmFree(numFields_7);

vdmFree(g_HardwareInterface_minlevel);

vdmFree(g_HardwareInterface_maxlevel);

return ;
}



 void HardwareInterface_static_init()	{

return ;
}



 void HardwareInterface_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForHardwareInterface  [] ={

{0,0,((VirtualFunctionPointer) _Z17HardwareInterfaceEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
HardwareInterfaceCLASS HardwareInterface_Constructor(HardwareInterfaceCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (HardwareInterfaceCLASS) malloc(sizeof(struct HardwareInterface));
	}

	if(this_ptr!=NULL)
	{
	
			
		// HardwareInterface init
		this_ptr->_HardwareInterface_id = CLASS_ID_HardwareInterface_ID;
		this_ptr->_HardwareInterface_refs = 0;
		this_ptr->_HardwareInterface_pVTable=VTableArrayForHardwareInterface;

													this_ptr->m_HardwareInterface_level= _Z18fieldInitializer14EV();
						this_ptr->m_HardwareInterface_valveState= _Z18fieldInitializer15EV();
			}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	HardwareInterfaceCLASS ptr=HardwareInterface_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_HardwareInterface_id, &ptr->_HardwareInterface_refs, (freeVdmClassFunction)&HardwareInterface_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* HardwareInterface.vdmrt 3:7 */
 TVP _Z17HardwareInterfaceEV(HardwareInterfaceCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, HardwareInterface);
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
	TVP numFields_7 =  NULL ;
		TVP g_HardwareInterface_minlevel =  NULL ;
		TVP g_HardwareInterface_maxlevel =  NULL ;
			
