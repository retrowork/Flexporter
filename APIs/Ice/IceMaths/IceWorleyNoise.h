///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Cellular noise.
 *	\file		IceWorleyNoise.h
 *	\author		Pierre Terdiman
 *	\date		January, 29, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEWORLEYNOISE_H
#define ICEWORLEYNOISE_H

	#define PERMUT_SIZE		256

	class ICEMATHS_API WorleyNoise
	{
		public:
		// Constructor/Destructor
								WorleyNoise();
								~WorleyNoise();

				float*			Compute(const Point& vector);

		protected:
				float			mMinDist[4];			// Results

				udword*			mP;						// Permutation table
				udword			mRnd;					// Random seed

				WorleyNoise&	ComputeMinDist(udword i, udword j, udword k, const Point& vector);
		inline_	udword			Random()									{ mRnd = mRnd * 2147001325 + 715136305; return mRnd; }
	};

#endif // ICEWORLEYNOISE_H
