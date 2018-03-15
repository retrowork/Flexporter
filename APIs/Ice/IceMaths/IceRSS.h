///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for rectangle-swept spheres.
 *	\file		IceRSS.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICERSS_H
#define ICERSS_H

	class ICEMATHS_API RSS : public Rectangle3
	{
		public:
		//! Constructor
		inline_			RSS()		{}
		//! Destructor
		inline_			~RSS()		{}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Computes an OBB surrounding the RSS.
		 *	\param		box		[out] the OBB
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				void	ComputeOBB(OBB& box);

				float	mRadius;	//!< Sphere radius
	};

#endif // ICERSS_H
