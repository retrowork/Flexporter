///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	FLEXPORTER - a flexible exporter
 *	Copyright (C) 2000-2004 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Flexporter.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This file contains code for the plug-ins manager.
 *	\file		FLX_PlugManager.h
 *	\author		Pierre Terdiman
 *	\date		January, 26, 2003
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef FLX_PLUGMANAGER_H
#define FLX_PLUGMANAGER_H

	class FLEXPORTER_API PluginManager
	{
		public:
		// Constructor/Destructor
										PluginManager();
										~PluginManager();

				udword					LoadPlugins(const char* source_directory);
				void					UnloadPlugins();

		inline_	void					SelectNextExporter()
										{
											// Jump to next exporter
											mSelectedExporter++;
											if(mSelectedExporter==mNbExporters)	mSelectedExporter = 0;
										}

		// Data access
		inline_	udword					GetCurrentExporter()	const	{ return mSelectedExporter;			}
		inline_	udword					GetNbExporters()		const	{ return mNbExporters;				}
		inline_	const FormatDescriptor&	GetSelectedExporter()	const	{ return mPlugs[mSelectedExporter];	}
		inline_	FormatDescriptor&		GetSelectedExporter()			{ return mPlugs[mSelectedExporter];	}
		inline_	const FormatDescriptor&	GetExporter(udword i)	const	{ return mPlugs[i];					}
		inline_	FormatDescriptor&		GetExporter(udword i)			{ return mPlugs[i];					}

		private:
				BOOL					mInitialized;				
				udword					mSelectedExporter;
				udword					mNbExporters;
				FormatDescriptor		mPlugs[256];
	};

#endif // FLX_PLUGMANAGER_H
