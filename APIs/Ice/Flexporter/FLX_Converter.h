///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	FLEXPORTER - a flexible exporter
 *	Copyright (C) 2000-2004 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Flexporter.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This file contains the main converter.
 *	\file		FLX_Converter.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef FLX_CONVERTER_H
#define FLX_CONVERTER_H

	class FLEXPORTER_API ConversionSettings
	{
		public:
						ConversionSettings()
						{
							mExporter		= null;
							mSettings		= null;
							mSceneFile		= false;
#ifdef SUPPORT_OLD_LIGHTMAPPER
							mLightmapPass	= false;
#endif
						}

						ExportFormat*		mExporter;		// The exporter object to use
						ExportSettings*		mSettings;		// The exportation settings
						String				mOutputName;	// Output filename
						bool				mSceneFile;		// true for scene file, false for motion files
#ifdef SUPPORT_OLD_LIGHTMAPPER
						bool				mLightmapPass;	// true for a lightmap pass
#endif
	};

	class FLEXPORTER_API Converter : public Parsable
	{
		public:
		// Constructor/Destructor
											Converter();
		virtual								~Converter();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	The main conversion entry point.
		 *	\param		params		[in] the conversion settings
		 *	\return		true if success.
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool				Convert(const ConversionSettings* params);

		protected:
		// Exportation settings
						ExportFormat*		mExporter;
						ExportSettings*		mSettings;
		// Export array for log file
						CustomArray			mArrayLog;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	This method is called once before starting the export process.
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			void				StartExport()	{}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	This method is called once after the export process.
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			void				EndExport()		{}

		//
						void				DumpLogString();
	};

#endif // FLX_CONVERTER_H
