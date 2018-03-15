///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for segment-rectangle distance
 *	\file		CTC_SegmentRectangleDistance.h
 *	\author		Pierre Terdiman
 *	\date		January, 13, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef CTCSEGMENTRECTANGLEDISTANCE_H
#define CTCSEGMENTRECTANGLEDISTANCE_H

	CONTACT_API float SegmentRectangleSqrDist(const Segment& segment, const Rectangle3& rectangle, float* t=null, float* u=null, float* v=null);

#endif // CTCSEGMENTRECTANGLEDISTANCE_H
