#ifndef POINT_2D_H
#define POINT_2D_H

#include "engineTypes.h"

namespace psp { namespace engine { namespace core {

template <class T>
class TPoint2D
{
	public:
		TPoint2D(const T& x, const T& y): X(x), Y(y) {};


		TPoint2D(): X(0), Y(0) {};


		TPoint2D(const TPoint2D<T>& parOther): X(parOther.X), Y(parOther.Y) {};

		const TPoint2D<T>& operator()(const T& x, const T& y)
		{
			X = x;
			Y = y;
			return *this;
		}


		bool operator == (const TPoint2D<T>& parOther) const
		{
			return (X == parOther.X) && (Y == parOther.Y);
		}


		bool operator != (const TPoint2D<T>& parOther) const
		{
			return (X != parOther.X) || (Y != parOther.Y);
		}

		const TPoint2D<T>& operator+=(const TPoint2D<T>& parOther)
		{
			X += parOther.X;
			Y += parOther.Y;
			return *this;
		}

		const TPoint2D<T>& operator-=(const TPoint2D<T>& parOther)
		{
			X -= parOther.X;
			Y -= parOther.Y;
			return *this;
		}

		TPoint2D<T> operator-(const TPoint2D<T>& parOther) const
		{
			return TPoint2D<T>(X-parOther.X, Y-parOther.Y);
		}

		TPoint2D<T> operator+(const TPoint2D<T>& parOther) const
		{
			return TPoint2D<T>(X+parOther.X, Y+parOther.Y);
		}

		const TPoint2D<T>& operator=(const TPoint2D<T>& parOther) 
		{
			X = parOther.X;
			Y = parOther.Y;
			return *this;
		}

		T X, Y;
};

//! typedef for standard float point
typedef TPoint2D<f32> p2Df;

//! typedef for standard int point
typedef TPoint2D<s32> p2Di;

} // namespace core
} // namespace engine
} // psp namespace

#endif


