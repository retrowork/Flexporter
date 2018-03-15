///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for line-swept spheres.
 *	\file		IceLSS.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICELSS_H
#define ICELSS_H

	class ICEMATHS_API LSS : public Segment
	{
		public:
		//! Constructor
		inline_			LSS()																	{}
		//! Constructor
		inline_			LSS(const Segment& seg, float radius) : Segment(seg), mRadius(radius)	{}
		//! Destructor
		inline_			~LSS()																	{}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Computes an OBB surrounding the LSS.
		 *	\param		box		[out] the OBB
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				void	ComputeOBB(OBB& box) const;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Tests if a point is contained within the LSS.
		 *	\param		pt	[in] the point to test
		 *	\return		true if inside the LSS
		 *	\warning	point and LSS must be in same space
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	bool	Contains(const Point& pt)	const	{ return SquareDistance(pt) <= mRadius*mRadius;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Tests if a sphere is contained within the LSS.
		 *	\param		sphere	[in] the sphere to test
		 *	\return		true if inside the LSS
		 *	\warning	sphere and LSS must be in same space
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	bool	Contains(const Sphere& sphere) const
						{
							float d = mRadius - sphere.mRadius;
							if(d>=0.0f)	return SquareDistance(sphere.mCenter) <= d*d;
							else		return false;
						}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Tests if an LSS is contained within the LSS.
		 *	\param		lss		[in] the LSS to test
		 *	\return		true if inside the LSS
		 *	\warning	both LSS must be in same space
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	bool	Contains(const LSS& lss) const
						{
							// We check the LSS contains the two spheres at the start and end of the sweep
							return Contains(Sphere(lss.mP0, lss.mRadius)) && Contains(Sphere(lss.mP1, lss.mRadius));
						}

				float	mRadius;	//!< Sphere radius
	};

#endif // ICELSS_H
