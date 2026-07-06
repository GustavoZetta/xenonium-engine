#ifndef XENONIUM_API
	#if defined(_WIN32) || defined(_WIN64)
		// If compiling with GCC (MinGW) or Clang, use GCC attributes
		#if defined(__GNUC__) || defined(__clang__)
			#ifdef _XENONIUM_DLL
				#define XENONIUM_API __attribute__((dllexport))
			#else
				#define XENONIUM_API __attribute__((dllimport))
			#endif
		#else
			// else, if MSVC, use __declspec
			#ifdef _XENONIUM_DLL
				#define XENONIUM_API __declspec(dllexport)
			#else
				#define XENONIUM_API __declspec(dllimport)
			#endif
		#endif
	#else
		// Linux and MacOS dont need dllexport
		#define XENONIUM_API
	#endif
#endif