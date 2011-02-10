#ifndef _ENGINE_H
#define _ENGINE_H

#include "GameEngine.h"

#include "Functions.h"

// object includes
#include "AnimatedMeshMD2.h"
#include "StaticMeshOBJ.h"

// gui includes
#include "GUI.h"

// io includes
#include "ReadFile.h"
#include "WriteFile.h"

// network inlcudes
#include "AdhocNetwork.h"

//! You will find all concepts and implementations of 34Lettres DEV Team
namespace psp 
{ 
	//! In this namespace tou will find al functions relative to memory management
	namespace Memory {}

	//! Everything in the 34Lettres 3D Engine can be found in this namespace
	namespace engine 
	{
	//! All basics types used in engine
		namespace core {}

		//! All scene objects can be found in this namespace: Mesh loading, billboards, ...
		namespace object {}

		//! All elements for user interface management
		namespace gui {}

		//! Provides interfaces for input/output: Reading and writing files
		namespace io {}

		//! All rendering elements in this namespace
		namespace video {}

		//! Namespace for networking functions
		namespace net {}

	} // engine namespace

} // psp namespace

#endif
