///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for eigen analysis of a mesh.
 *	\file		IceEigenAnalysis.h
 *	\author		Pierre Terdiman
 *	\date		January, 13, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEEIGENANALYSIS_H
#define ICEEIGENANALYSIS_H

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Eigen analysis of a triangular mesh.
	 *	\param		tris			[in] list of triangles
	 *	\param		nb_tris			[in] number of triangles
	 *	\param		verts			[in] list of vertices
	 *	\param		nb_verts		[in] number of vertices
	 *	\param		center			[out] center of mesh
	 *	\param		eigen_values	[out] eigen values
	 *	\param		eigen_vectors	[out] eigen vectors (stored in columns)
	 *	\param		use_hull		[in] true to use the convex hull
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION MESHMERIZER_API bool ComputeSpread(const IndexedTriangle* tris, udword nb_tris, const Point* verts, udword nb_verts, Point& center, Point& eigen_values, Matrix3x3& eigen_vectors, bool use_hull=false);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Computes an OBB for a triangular mesh.
	 *	\param		tris		[in] list of triangles
	 *	\param		nb_tris		[in] number of triangles
	 *	\param		verts		[in] list of vertices
	 *	\param		nb_verts	[in] number of vertices
	 *	\param		obb			[out] the obb
	 *	\param		use_hull	[in] true to compute the OBB of the mesh's convex hull
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION MESHMERIZER_API bool ComputeOBB(const IndexedTriangle* tris, udword nb_tris, const Point* verts, udword nb_verts, OBB& obb, bool use_hull);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Computes the OBB of a single triangle.
	 *	\param		p1		[in] first vertex
	 *	\param		p2		[in] second vertex
	 *	\param		p3		[in] third vertex
	 *	\param		obb		[out] oriented bounding box from input triangle
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION MESHMERIZER_API void OBBFromTriangle(const Point& p1, const Point& p2, const Point& p3, OBB& obb);

#endif	// ICEEIGENANALYSIS_H
