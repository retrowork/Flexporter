///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for point shells.
 *	\file		IcePointShell.h
 *	\author		Pierre Terdiman
 *	\date		July, 10, 2003
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEPOINTSHELL_H
#define ICEPOINTSHELL_H

	// Forward declarations
	class IndexedSurface;

	class MESHMERIZER_API PointShell : public VertexCloud
	{
		public:
							PointShell();
		virtual				~PointShell();

				bool		Init(const IndexedSurface& surface, float min_distance);
	};

#endif // ICEPOINTSHELL_H
