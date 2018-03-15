///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Flexine SDK main header.
 *	\file		FlexineSDK.h
 *	\author		Pierre Terdiman
 *	\date		July, 21, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef FLEXINESDK_H
#define FLEXINESDK_H

	//! SDK version number
	#define	FLEXINE_SDK_VERSION		0x1000

	#define DECLARE_ICE_INTERFACE(current_class, base_class)	_DECLARE_ICE_ABSTRACT_CLASS(current_class, base_class)

	class FLEXINE_API IceInterface : public Cell
	{
		public:
		//! Constructor
										IceInterface()			{}
		//! Destructor
		virtual							~IceInterface()			{}

						DECLARE_ICE_INTERFACE(IceInterface, Cell)

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Registration callback.
		 *	\return		true if success (else the interface is discarded)
		 *	\see		OnClose()
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			OnOpen()				{ return true;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Un-registration callback.
		 *	\return		true if success (info purpose)
		 *	\see		OnOpen()
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			OnClose()				{ return true;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Get singleton status. If the interface represents a singleton, the system looks for a similar interface
		 *	at load time and discards the previous one.
		 *	\return		true for singletons
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		virtual			bool			IsSingleton()	const	{ return false;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets a possible menu handle for the plug-in. If the plug doesn't have a menu, return null.
		 *	\return		menu handle, or null
		 *	\see		MenuCallback()
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			HMENU			GetMenuHandle()			{ return null;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	This method is called when the user selects the plug-in in the app's menu.
		 *	\param		id		[in] menu ID (selected menu item), or INVALID_ID if the plug-in's name has been selected
		 *	\return		true if success
		 *	\see		GetMenuHandle()
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			MenuCallback(udword id)	{ return true;	}
	};

	// Standard interfaces

	//! Basic serialization interface
	class FLEXINE_API ImportExport : public IceInterface
	{
		public:
		//! Constructor
										ImportExport()			{}
		//! Destructor
		virtual							~ImportExport()			{}

						DECLARE_ICE_INTERFACE(ImportExport, IceInterface)

		virtual			bool			CanImport()		const	= 0;
		virtual			bool			CanExport()		const	= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets supported file extensions.
		 *	\return		supported file extensions (ex: "bmp", "bmp tga", etc)
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			const char*		GetExtensions()	const	= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Checks the interface supports a given extension
		 *	\param		extension	[in] extension to check (ex: "bmp")
		 *	\return		true if supported
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						bool			SupportsExtension(const char* extension) const;
	};

	//! Basic sound interface
	class FLEXINE_API SoundInterface : public IceInterface
	{
		public:
		//! Constructor
										SoundInterface()		{}
		//! Destructor
		virtual							~SoundInterface()		{}

						DECLARE_ICE_INTERFACE(SoundInterface, IceInterface)

		virtual			Handle			LoadSample(const char* filename)	= 0;
		virtual			bool			PlaySample(Handle handle)			= 0;
	};

	//! Basic compression interface
	class FLEXINE_API DataPacker : public IceInterface
	{
		public:
		//! Constructor
										DataPacker()			{}
		//! Destructor
		virtual							~DataPacker()			{}

						DECLARE_ICE_INTERFACE(DataPacker, IceInterface)

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets supported compression method.
		 *	\return		supported compression method (ex: "rle", "zip", etc)
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			const char*		GetCompressionMethod()	const	= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Compresses a buffer.
		 *	\param		dest		[out] destination buffer
		 *	\param		dest_size	[in/out] size of destination/compressed buffer
		 *	\param		source		[in] source buffer
		 *	\param		source_size	[in] size of source buffer
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			Compress(ubyte* dest, udword& dest_size, const void* source, udword source_size)	=	0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Decompresses a buffer.
		 *	\param		dest			[out] destination buffer
		 *	\param		original_size	[in/out] size of original/decompressed buffer
		 *	\param		compressed		[in] source (compressed) buffer
		 *	\param		compressed_size	[in] size of source buffer
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			Decompress(ubyte* dest, udword& original_size, const void* compressed_buffer, udword compressed_size)	=	0;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Compresses a buffer. This method needs registered compression plug-ins.
	 *	\fn			Compress(ubyte* dest, udword& dest_size, const void* source, udword source_size, const char* method)
	 *	\param		dest		[out] destination (compressed) buffer
	 *	\param		dest_size	[out] size of compressed buffer
	 *	\param		source		[in] source (input) buffer
	 *	\param		source_size	[in] size of source buffer
	 *	\param		method		[in] method to use for compression. If no method specified (null), try all available methods and keep the best.
	 *	\return		name of used method, null if failed
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION FLEXINE_API const char* Compress(ubyte* dest, udword& dest_size, const void* source, udword source_size, const char* method=null);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Decompresses a buffer. This method needs registered compression plug-ins.
	 *	\fn			Decompress(ubyte* dest, udword& original_size, const void* compressed_buffer, udword compressed_size, const char* method)
	 *	\param		dest				[out] destination (decompressed) buffer
	 *	\param		original_size		[out] size of decompressed buffer (shoul be the original size of source buffer)
	 *	\param		compressed_buffer	[in] source (compressed) buffer
	 *	\param		compressed_size		[in] size of source buffer
	 *	\param		method				[in] method to use for decompression. If null, try all of them.
	 *	\return		name of used method, null if failed
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION FLEXINE_API const char* Decompress(ubyte* dest, udword& original_size, const void* compressed_buffer, udword compressed_size, const char* method=null);


/*
	//! Interface dynamic cast
	inline_ IceInterface* DynamicCast(IceInterface* it, const char* interfacename)
	{
		// Check type
		if(!it || !it->IsKindOf(interfacename))	return null;
		//
		return it;
	}
*/
	// We want to be able to create static plugin descriptors on the heap, without problems.
	// So this class shouldn't be derived from anything special, and should be kept very simple.
	class FLEXINE_API IcePlugin
	{
		public:
		// Constructor/Destructor
										IcePlugin()				{}
		virtual							~IcePlugin()			{}

		// Namings

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets plug-in's name
		 *	\return		name of plug-in
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			const char*		GetPlugName()			= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets plug-in's related API
		 *	\return		name of API
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			const char*		GetMasterAPI()			= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets plug-in's description
		 *	\return		description of plug-in
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			const char*		GetPlugDescription()	= 0;

		// Interfaces

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets number of interfaces exposed by the plug-in
		 *	\return		number of exposed interfaces
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			udword			GetNbInterfaces()		= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets interface of given index
		 *	\param		i	[in] index of desired interface
		 *	\return		interface number i
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			IceInterface*	GetInterface(udword i)	= 0;

		// Lifetime

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes the plug-in. Called by the framework.
		 *	If returns false, the plug-in loading is aborted.
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			Init()					= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Closes the plug-in. Called by the framework.
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool			Close()					= 0;
	};

//	FUNCTION FLEXINE_API udword		GetSDKVersion();
//	FUNCTION FLEXINE_API IcePlugin*	GetPlugin();

#endif // FLEXINESDK_H