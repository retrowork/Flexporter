///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	FLEXPORTER - a flexible exporter
 *	Copyright (C) 2000-2004 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Flexporter.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This file contains the motion-related exported structures.
 *	\file		FLX_AddMotion.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef FLX_ADDMOTION_H
#define FLX_ADDMOTION_H

	//! The motion information class. A MotionInfo is used to describe a Character Studio BIPED motion.
	class FLEXPORTER_API MotionDescriptor : public ObjectDescriptor
	{
		public:
		// Constructor / Destructor
							MotionDescriptor();
		virtual				~MotionDescriptor();
		// Note: mLinkID is the owner character's ID

				udword		mNbBones;				//!< Number of bones involved in this motion
				udword		mNbVirtualBones;		//!< Number of virtual bones involved in this motion

				void*		mData;					//!< Motion data
				ubyte*		mType;					//!< Motion type

	//	Motion data format:
	//	for each bone
	//	{
	//		udword	CSID		the current bone's ID
	//		udword	NbFrames	the number of recorded frames
	//		for each frame
	//		{
	//			x,y,z			a translation vector
	//			x,y,z,w			a rotation component (quaternion)
	//		}
	//	}
	//
	//	Non-uniform scales are always removed for Character Studio motions, hence the scale
	//	is always (1, 1, 1) and is never explicitely exported. Translation and rotation parts
	//	are relative or absolute, according to the exportation settings.
	//
	//	Please note the motion data weren't converted to D3D frame before version 1.13.
	//
	};

#endif // FLX_ADDMOTION_H
