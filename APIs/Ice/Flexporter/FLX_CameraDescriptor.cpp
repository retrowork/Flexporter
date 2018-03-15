///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	FLEXPORTER - a flexible exporter
 *	Copyright (C) 2000-2004 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Flexporter.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Precompiled Header
#include "Stdafx.h"

using namespace Flexporter;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Constructor.
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CameraDescriptor::CameraDescriptor()
{
	mOrthoCam		= false;
	mFOV			= 0.0f;
	mNearClip		= 0.0f;
	mFarClip		= 0.0f;
	mTDist			= 0.0f;
	mHLineDisplay	= 0;
	mEnvNearRange	= 0.0f;
	mEnvFarRange	= 0.0f;
	mEnvDisplay		= 0;
	mManualClip		= 0;
	mFOVType		= FLX_FOV_FORCE_DWORD;
	mCamType		= FLX_CTYPE_FORCE_DWORD;
	mMasterCamera	= null;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Destructor.
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CameraDescriptor::~CameraDescriptor()
{
}