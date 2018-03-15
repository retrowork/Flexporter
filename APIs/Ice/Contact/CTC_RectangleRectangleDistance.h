///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for rectangle-rectangle distance
 *	\file		CTC_RectangleRectangleDistance.h
 *	\author		Pierre Terdiman
 *	\date		January, 13, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef CTCRECTANGLERECTANGLEDISTANCE_H
#define CTCRECTANGLERECTANGLEDISTANCE_H

	CONTACT_API float RectangleRectangleSqrDist(
		const Rectangle3& rkRct0,
		const Rectangle3& rkRct1,
		float* pfRct0P0=null, float* pfRct0P1=null,
		float* pfRct1P0=null, float* pfRct1P1=null);

#endif // CTCRECTANGLERECTANGLEDISTANCE_H
