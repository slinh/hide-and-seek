#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#ifndef PSP_LEGACY_TYPES_DEFINED
#define PSP_LEGACY_TYPES_DEFINED

/** All macros for bit access */
#define BIT(POS) (1<<(POS))

/** All typedef ensure portability of the engine. */

//! 8 bit unsigned variable.
typedef unsigned char		u8; 

//! 8 bit signed variable
typedef signed char			s8; 


//! 16 bit unsigned variable
typedef unsigned short		u16;

//! 16 bit signed variable
typedef signed short		s16; 


//! 32 bit unsigned variable
typedef unsigned int		u32;

//! 32 bit signed variable
typedef signed int			s32; 

typedef unsigned long long u64;


#endif
//! 8 bit character variable
typedef char				c8; 

//! 32 bit floating point variable
typedef float				f32; 

//! 64 bit floating point variable
typedef double				f64; 

namespace psp {
#ifdef WIN64
	typedef u64 ptr_t;
#else
	typedef u32 ptr_t;
#endif
}

// define the wchar_t type if not already built in
#ifdef _MSC_VER 
#ifndef _WCHAR_T_DEFINED
//! A 16 bit wide character type
/**
	Defines the wchar_t-type.
	In VS6, its not possible to tell
	the standard compiler to treat wchar_t as a built-in type, and 
	sometimes we just don't want to include the huge stdlib.h or wchar.h,
	so we'll use this.
*/
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif // wchar is not defined
#endif // microsoft compiler

//! define a break macro for debugging only in Win32 mode.
#if (defined(WIN32) || defined(WIN64)) && defined(_MSC_VER) && defined(_DEBUG)
#define _engine_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_asm int 3}
#else 
#define _engine_DEBUG_BREAK_IF( _CONDITION_ )
#endif

//! Defines a small statement to work around a microsoft compiler bug.
/** The microsft compiler 7.0 - 7.1 has a bug:
When you call unmanaged code that returns a bool type value of false from managed code, 
the return value may appear as true. See 
http://support.microsoft.com/default.aspx?kbid=823071 for details. 
Compiler version defines: VC6.0 : 1200, VC7.0 : 1300, VC7.1 : 1310, VC8.0 : 1400*/
#if defined(WIN32) && defined(_MSC_VER) && (_MSC_VER > 1299) && (_MSC_VER < 1400)
#define _engine_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX __asm mov eax,100
#else
#define _engine_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX
#endif // _engine_MANAGED_MARSHALLING_BUGFIX

#endif // ENGINE_TYPES_H


