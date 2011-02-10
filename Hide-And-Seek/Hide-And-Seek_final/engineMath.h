#ifndef ENGINE_MATH_H
#define ENGINE_MATH_H

#include "engineTypes.h"
#include "Assert.h"
#include <cmath>

namespace psp { namespace engine { namespace core {

	//! Rounding error constant often used when comparing f32 values.
	const f32 EPSILON		= 0.000001f;

	//! Constant for PI.
	const f32 PI			= 3.1415926535897932384626433832795f;

	//! Constant for converting between degrees and radiants.
	const f64 RAD_TO_DEG	= 180.0f / PI;

	//! Constant for converting between degrees and radiants.
	const f64 DEG_TO_RAD	= PI / 180.0;

	//! Returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T MIN(const T a, const T b)
	{
		return a < b ? a : b;
	}
	
	//! Returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline T MAX(const T a, const T b)
	{
		return a < b ? b : a;
	}

	//! Returns abs of two values. Own implementation to get rid of STL (VS6 problems)
	template<class T>
	inline T ABS(const T a)
	{
		return a < 0 ? -a : a;
	}

	//! Returns if a float equals the other one, taking floating 
	inline bool EQUALS(f32 a, f32 b)
	{
		return (a + EPSILON > b) && (a - EPSILON < b);
	}

	//! Returns a^b
	template<class T>
	inline T POW(T a, s32 b)
	{
		T locResult = 1;
		s32 count = ABS(b);

		while(count > 0)
		{
			--count;
			locResult *= a;
		}

		return b>0? locResult : (T)(1.f/(f32)locResult);
	}

	//! Return Round of a
	inline s32 ROUND(f32 a)	
	{
		return (s32)floor(a+0.5f);
	}
	
	inline u64 ROUND(f64 a)	
	{
		return (u64)floor(a+0.5);
	}

	template<class T>
	inline T CLAMP(const T& value, const T& inf, const T& sup)
	{
		LAssert(sup > inf);

		T delta = sup - inf;

		return value > sup? value - delta:
			   (value < inf? value + delta: value);
	}

} // namespace core
} // namespace engine
} // namespace psp

#endif


