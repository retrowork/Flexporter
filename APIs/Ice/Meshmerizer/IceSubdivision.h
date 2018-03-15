///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains surface subdivision code.
 *	\file		IceSubdivision.h
 *	\author		Pierre Terdiman
 *	\date		January, 17, 1999
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICESUBDIVISION_H
#define ICESUBDIVISION_H

	// Alpha
	// From Piecewise smooth reconstruction (Hoppe)
	inline_ float ComputeAlpha(udword n)
	{
		float tmp = 3.0f + 2.0f * cosf(2.0f * PI/float(n));
		float a = 5.0f/8.0f - (tmp*tmp)/64.0f;
		return (n*(1.0f-a)/a);
	}

	class MESHMERIZER_API SubdivScheme
	{
		public:
		// Constructor / Destructor
													SubdivScheme();
		virtual										~SubdivScheme();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Subdivides a surface, regardless of the subdivision scheme. This is a generic subdivision process: for each triangle we create four new triangles,
		 *	and three new vertices along the three edges of the triangle. New vertices are cached so that the subdividers are only called once per edge.
		 *	After the call, the input surface is updated with the new one.
		 *	\param		surface		[in] the surface to subdivide.
		 *	\param		use_cache	[in] true to cache computed vertices and only call the subdividers once per edge, else always call them three times per triangle
		 *	\param		history		[out] subdivision history (or null)
		 *	\return		true if success.
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								bool				Subdivide(IndexedSurface& surface, bool use_cache=true, SubdivHistory* history=null);

		protected:

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes the subdivision scheme.
		 *	\param		surface		[in] the surface to subdivide
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual					bool				Init(IndexedSurface& surface)																		= 0;
		virtual					bool				Close(IndexedSurface& surface)	{ return true; }
		virtual					bool				ComputeNewVertex(udword face_id, udword vref0, udword vref1, Point& p, SubdivHistory* history=null)	= 0;
	};

	class MESHMERIZER_API PolyhedralScheme : public SubdivScheme
	{
		public:
		// Constructor / Destructor
													PolyhedralScheme();
		virtual										~PolyhedralScheme();

		protected:
								Point*				mVerts;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes the subdivision scheme.
		 *	\param		surface		[in] the surface to subdivide
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(SubdivScheme)	bool				Init(IndexedSurface& surface);
		override(SubdivScheme)	bool				ComputeNewVertex(udword face_id, udword vref0, udword vref1, Point& p, SubdivHistory* history);
	};

	class MESHMERIZER_API ChaosScheme : public SubdivScheme
	{
		public:
		// Constructor / Destructor
													ChaosScheme();
		virtual										~ChaosScheme();

//		inline_					void				SetDisplacement(float d)			{ mDisplacement = d;		}
//		inline_					float				GetDisplacement()			const	{ return mDisplacement;		}

		protected:
//								float				mDisplacement;
								const Point*		mVerts;
								const IndexedTriangle*	mFaces;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes the subdivision scheme.
		 *	\param		surface		[in] the surface to subdivide
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(SubdivScheme)	bool				Init(IndexedSurface& surface);
		override(SubdivScheme)	bool				ComputeNewVertex(udword face_id, udword vref0, udword vref1, Point& p, SubdivHistory* history);
	};

#endif // ICESUBDIVISION_H

