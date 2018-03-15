///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code to handle plug-ins.
 *	\file		IcePluginManager.h
 *	\author		Pierre Terdiman
 *	\date		July, 4, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICEPLUGINMANAGER_H
#define ICEPLUGINMANAGER_H

	#define LIBRARY				HINSTANCE
	#define INVALID_LIBRARY		0

	// Forward declarations
	class String;
	class IceInterface;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Dynamically loads a library (a.k.a. module, DLL, etc)
	 *	\fn			LoadLibrary(const char* pathname, LIBRARY& handle)
	 *	\param		path_name	[in] the library's name
	 *	\param		handle		[out] library's handle
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			LoadLibrary(const char* path_name, LIBRARY& handle);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Unloads a previously dynamically-loaded library.
	 *	\fn			UnloadLibrary(LIBRARY handle)
	 *	\param		handle		[in] library's handle
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			UnloadLibrary(LIBRARY handle);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Catch the adress of an exported method.
	 *	\fn			BindSymbol(LIBRARY handle, const char* symbol)
	 *	\param		handle		[in] library's handle
	 *	\param		symbol		[in] method's name
	 *	\return		address of wanted method, or null if doesn't exist
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API void*			BindSymbol(LIBRARY handle, const char* symbol);

	//

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Returns current number of plug-ins.
	 *	\fn			GetNbPlugins()
	 *	\return		number of currently loaded plug-ins
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API udword			GetNbPlugins();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Returns the name of a plug-in.
	 *	\fn			GetPluginName(udword i)
	 *	\param		i	[in] plug-in index
	 *	\return		plug-in name, if index is valid
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API const String*	GetPluginName(udword i);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Registers a new plug-in.
	 *	\fn			RegisterPlugin(const char* filename)
	 *	\param		filename	[in] plug-in's filename
	 *	\param		tag			[in] user-defined mark
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			RegisterPlugin(const char* filename, sdword tag=0);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Unregisters a previously loaded plug-in.
	 *	\fn			UnregisterPlugin(const char* filename, IcePlugin* plugin)
	 *	\param		filename	[in] plug-in's filename, or null if unknown
	 *	\param		plugin		[in] plug-in's address, or null if unknown
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			UnregisterPlugin(const char* filename=null, IcePlugin* plugin=null);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Unregisters all plug-ins, or only the ones corresponding to given tag.
	 *	\fn			UnregisterPlugins()
	 *	\param		tag		[in] user-defined mark, or null
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			UnregisterPlugins(sdword* tag=null);

	//

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Returns current number of interfaces.
	 *	\fn			GetNbInterfaces()
	 *	\return		number of currently loaded interfaces
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API udword			GetNbInterfaces();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Interfaces enumeration function.
	 *	\fn			GetInterface(udword i)
	 *	\param		i	[in] index of desired interface
	 *	\return		interface number i, or null
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API IceInterface*	GetInterface(udword i);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Registers a new interface.
	 *	\fn			RegisterInterface(IceInterface* it)
	 *	\param		it	[in] new interface
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			RegisterInterface(IceInterface* it);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Unregisters a previously loaded interface.
	 *	\fn			UnregisterInterface(IceInterface* it)
	 *	\param		it	[in] the interface to unregister
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			UnregisterInterface(IceInterface* it);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Unregisters all interfaces.
	 *	\fn			UnregisterInterfaces()
	 *	\return		true if success
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API bool			UnregisterInterfaces();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 *	Finds interface of given type.
	 *	\fn			FindInterface(const char* type)
	 *	\param		type	[in] type of desired interface
	 *	\return		first interface found, or null
	 */
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FUNCTION ICECORE_API IceInterface*	FindInterface(const char* type);

#endif // ICEPLUGINMANAGER_H
