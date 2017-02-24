// The template for class
#include "World.h"
#include <stdio.h>
#include <string.h>


/* -------------------------------
 *
 * Memory management methods
 *
 --------------------------------- */

void World_free_fields(struct World *this)
{
	}

static void World_free(struct World *this)
{
	--this->_World_refs;
	if (this->_World_refs < 1)
	{
		World_free_fields(this);
		free(this);
	}
}


/* -------------------------------
 *
 * Member methods 
 *
 --------------------------------- */
 

 static  TVP _Z17fieldInitializer9EV()	{

TVP ret_12 = newInt(0)
;

return ret_12;
}


/* World.vdmrt 10:8 */
 static  void _Z3runEV(WorldCLASS this)	{
/* World.vdmrt 14:3 */
CALL_FUNC(Controller, Controller, vdmCloneGC(g_System_controller, NULL), CLASS_Controller__Z4loopEV);
}


/* World.vdmrt 17:9 */
 static  void _Z5blockEV(WorldCLASS this)	{
/* World.vdmrt 19:3 */
{
//Skip
};
}



 void World_const_init()	{

numFields_5 = _Z17fieldInitializer9EV();

return ;
}



 void World_const_shutdown()	{

vdmFree(numFields_5);

return ;
}



 void World_static_init()	{

return ;
}



 void World_static_shutdown()	{

return ;
}




/* -------------------------------
 *
 * VTable
 *
 --------------------------------- */
 
// VTable for this class
 static  struct VTable VTableArrayForWorld  [] ={

{0,0,((VirtualFunctionPointer) _Z3runEV),},
{0,0,((VirtualFunctionPointer) _Z5blockEV),},
{0,0,((VirtualFunctionPointer) _Z5WorldEV),},
				
}  ;

// Overload VTables


/* -------------------------------
 *
 * Internal memory constructor
 *
 --------------------------------- */
 
 
WorldCLASS World_Constructor(WorldCLASS this_ptr)
{

	if(this_ptr==NULL)
	{
		this_ptr = (WorldCLASS) malloc(sizeof(struct World));
	}

	if(this_ptr!=NULL)
	{
	
			
		// World init
		this_ptr->_World_id = CLASS_ID_World_ID;
		this_ptr->_World_refs = 0;
		this_ptr->_World_pVTable=VTableArrayForWorld;

				}

	return this_ptr;
}

// Method for creating new "class"
static TVP new()
{
	WorldCLASS ptr=World_Constructor(NULL);

	return newTypeValue(VDM_CLASS, (TypedValueType)
			{	.ptr=newClassValue(ptr->_World_id, &ptr->_World_refs, (freeVdmClassFunction)&World_free, ptr)});
}



/* -------------------------------
 *
 * Public class constructors
 *
 --------------------------------- */ 
 

/* World.vdmrt 6:7 */
 TVP _Z5WorldEV(WorldCLASS this)	{

TVP __buf = NULL
;

if ( this == NULL )
	
	{

__buf = new();

this = TO_CLASS_PTR(__buf, World);
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
	TVP numFields_5 =  NULL ;
	
