///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains a tri-surface class.
 *	\file		IceTriSurface.h
 *	\author		Pierre Terdiman
 *	\date		January, 17, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICETRISURFACE_H
#define ICETRISURFACE_H

	// A non-indexed triangle surface
	class MESHMERIZER_API TriSurface
	{
		public:
		// Constructor/Destructor
							TriSurface();
		virtual				~TriSurface();

		// Surface init

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes a tri-surface.
		 *	\param		nb_faces	[in] the number of triangles in the surface
		 *	\param		faces		[in] possible list of faces if available
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				bool		Init(udword nb_faces, const Triangle* faces=null);

		// Surface construction

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Adds a triangle to the surface.
		 *	\param		p0		[in] first vertex
		 *	\param		p1		[in] second vertex
		 *	\param		p2		[in] third vertex
		 *	\param		i		[in] face index
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				bool		SetFace(const Point& p0, const Point& p1, const Point& p2, udword i);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Adds a triangle to the surface.
		 *	\param		triangle	[in] new triangle
		 *	\param		i			[in] face index
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				bool		SetFace(const Triangle& triangle, udword i);

		// Surface destruction

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Frees all used bytes and releases everything.
		 *	\return		Self-reference
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				TriSurface&	Clean();

		// Surface operations

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Cuts a tri-surface by a given plane. This method splits the source surface into two (positive and negative) sub-surfaces.
		 *	\param		cut_plane			[in] plane equation
		 *	\param		positive_surface	[in] the positive destination surface (or null)
		 *	\param		negative_surface	[in] the negative destination surface (or null)
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				bool		Cut(const Plane& cut_plane, TriSurface* positive_surface, TriSurface* negative_surface);

				Plane		FindBestDivider();

		// Data access
		inline_	udword		GetNbFaces()		const	{ return mNbFaces;		}
		inline_	Triangle*	GetFaces()			const	{ return mFaces;		}
		inline_	Triangle*	GetFace(udword i)	const	{ return &mFaces[i];	}

		private:
		// Mixed topology-geometry
				udword		mNbFaces;			//!< Number of triangles
				Triangle*	mFaces;				//!< List of non-indexed triangles
	};

#endif // ICETRISURFACE_H
