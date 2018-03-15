///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for a vertex container.
 *	\file		IceVertices.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEVERTICES_H
#define ICEVERTICES_H

	class ICEMATHS_API Vertices : public Container
	{
		public:
		// Constructor / Destructor
								Vertices()								{}
								Vertices(udword nb, const Point* verts)	{ Add(&verts->x, nb*(sizeof(Point)/sizeof(float)));	}
								~Vertices()								{}

		inline_	udword			GetNbVertices()					const	{ return GetNbEntries()/3;							}
		inline_	const Point*	GetVertices()					const	{ return (const Point*)GetEntries();				}

				Vertices&		AddVertex(const Point& p)				{ Add(p.x).Add(p.y).Add(p.z);	return *this;		}
				Vertices&		AddVertex(float x, float y, float z)	{ Add(x).Add(y).Add(z);			return *this;		}
	};

#endif //ICEVERTICES_H
