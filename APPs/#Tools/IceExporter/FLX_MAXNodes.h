///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	FLEXPORTER - a flexible exporter
 *	Copyright (C) 2000-2004 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Flexporter.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This file contains a container for MAX nodes.
 *	\file		FLX_MAXNodes.h
 *	\author		Pierre Terdiman
 *	\date		September, 24, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef FLX_MAXNODES_H
#define FLX_MAXNODES_H

	//! A container customized for MAX nodes
	class MAXNodes : private Container
	{
		public:
		// Constructor/Destructor
								MAXNodes()					{}
								~MAXNodes()					{}

		inline_		void		AddNode(INode* node)		{ Add(udword(node));			}

		inline_		udword		GetNbNodes()		const	{ return GetNbEntries();		}
		inline_		INode*		GetNode(udword i)	const	{ return (INode*)GetEntry(i);	}
		inline_		INode**		GetNodes()			const	{ return (INode**)GetEntries();	}
	};

#endif // FLX_MAXNODES_H
