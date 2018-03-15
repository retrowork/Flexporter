///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for anchors.
 *	\file		IceAnchor.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEANCHOR_H
#define ICEANCHOR_H

	class ICERENDERER_API Anchor
	{
		public:
		// Constructor/Destructor
										Anchor();
		virtual							~Anchor();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Computes the new anchor vertices.
		 *	- computed vertices are stored within the class, accessed with GetAnchorVerts().
		 *	- computed vertices are expressed in world space, in mAnchorVerts
		 *
		 *	\param		pos				[in] anchor position in world space (important! else the scaling won't be correct)
		 *	\param		rd				[in] renderer shortcut
		 *	\param		view			[in] view matrix (or null)
		 *	\param		proj			[in] proj matrix (or null)
		 *	\return		true if success, world-vertices stored in mAnchorVerts
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					bool				ComputeAnchor(const Point& pos, Renderer* rd, const ViewMatrix* view=null, const ProjMatrix* proj=null);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Renders the anchor.
		 *	\param		rd		[in] renderer shortcut
		 *	\param		bool	[in] false to disable texturing
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					bool				RenderAnchor(Renderer* rd, bool texturing=false);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Stabs the anchor with a ray. This is kept at the renderer level since the anchor is purely a renderer entity.
		 *	\param		stabinfo	[in] stabbing parameters
		 *	\param		sf			[out] stabbed face
		 *	\return		true if the anchor gets stabbed by the ray
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					bool				StabAnchor(const STABCREATE& stabinfo, StabbedFace& sf);
		// Settings
		inline_		void				SetSizeX(float sizex)			{ mSizeX = sizex;								}
		inline_		void				SetSizeY(float sizey)			{ mSizeY = sizey;								}
		inline_		void				SetSize(float size)				{ mSizeX = mSizeY = size;						}
		inline_		void				SetConstantSize(bool flag)		{ mConstantSize = flag;							}
		// Data access
		inline_		const PT_Vertex*	GetAnchorVerts()		const	{ return mAnchorVerts;							}
		inline_		udword*				GetAnchorFaces()		const	{ return mAnchorFaces;							}
		inline_		udword				GetAnchorNbFaces()		const	{ return 2;										}
		inline_		float				GetSizeX()				const	{ return mSizeX;								}
		inline_		float				GetSizeY()				const	{ return mSizeY;								}
		inline_		bool				HasConstantSize()		const	{ return mConstantSize;							}

		inline_		float				ComputeDiagonal()		const	{ return sqrtf(mSizeX*mSizeX+mSizeY*mSizeY);	}

		private:
		static		udword				mAnchorFaces[6];	//!< Shared indices
					PT_Vertex			mAnchorVerts[4];	//!< Anchor's vertices
					float				mSizeX, mSizeY;		//!< Anchor's size
					bool				mConstantSize;		//!< True to constrain anchor's screen-size
	};

#endif // ICEANCHOR_H
