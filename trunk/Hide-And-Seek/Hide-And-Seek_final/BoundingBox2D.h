#ifndef BOUNDING_BOX_2D_H
#define BOUNDING_BOX_2D_H
/*!
 * \file BoundingBox2D.h
 * \brief Bounding Box 2D
 * \author Arnaud Casella
 * \version 0.1
 */
#include "config.h"
#include <cmath>
#include "LoggerTypes.h"
#include "vector2d.h"
#include "vector3d.h"

#ifdef COMPILE_PC
#include <iostream>
#endif

namespace psp { namespace engine { namespace core {

/*! \class TBoundingBox2D
 * \brief class modeling the bounding box 2d
 *
 *  The box builds itself as we are adding points. It's used to detect collisions
 */
typedef enum FACE_SIDE {
	FS_LEFT = 1,
	FS_RIGHT = 2,
	FS_TOP = 4,
	FS_BOTTOM = 8,
	FS_NONE = 16,
	FS_ERROR = 20000
}FACE_SIDE;
template <class T>
class TBoundingBox2D
{
public:
	/*!
     *  \brief Empty Constructor
     */
	TBoundingBox2D() : 
	FLeft(0), FRight(0),
	FBottom(0), FTop(0),
	FX(0), FY(0),
	FInit(false) 
	{}

	TBoundingBox2D(const TBoundingBox2D& parBBox): 
	FLeft(parBBox.FLeft), FRight(parBBox.FRight),
	FBottom(parBBox.FBottom), FTop(parBBox.FTop),
	FX(parBBox.FX), FY(parBBox.FY),
	FInit(parBBox.FInit) 
	{}
	// Getters/Setters : Refer to macro.h file 
	// With GETTER_SETTER(T, MyVar), use GetMyVar and SetMyVar
	GETTER_SETTER(T, Left);
	GETTER_SETTER(T, Right);
	GETTER_SETTER(T, Bottom);
	GETTER_SETTER(T, Top);
	GETTER_SETTER(T, X);
	GETTER_SETTER(T, Y);
	
	inline bool IsInit() const {return FInit;}

	inline T GetWidth() const {return FRight - FLeft;}
	inline T GetHeight() const {return FTop - FBottom;}
	
	//! Reinitialize Bounding Box
	void Reset()
	{
		FLeft = FRight = FBottom = FTop = FX = FY = (T)0;
		FInit = false;
	}

	/*!
     *  \brief Add a new point to the bounding box
     *
     *  Add a new point. The new bounding box is updated automatically.
     *
     *  \param parPoint : The point to add
     */
	void AddPoint(const vector2d<T>& parPoint)
	{
		//if the bounding box hasn't been initialized
		if(!FInit)
		{
			FLeft = FRight = parPoint.X;
			FBottom = FTop = parPoint.Y;
			FInit = true;
		}
		else
		{
			if(parPoint.X < FLeft)
				FLeft = parPoint.X;
			else if(parPoint.X > FRight)
				FRight = parPoint.X;

			if(parPoint.Y < FBottom)
				FBottom = parPoint.Y;
			else if(parPoint.Y > FTop)
				FTop = parPoint.Y;
		}

		UpdateCenter();
	}

	void AddPoint(const T& parX, const T& parY)
	{
		//get the 2d coordinate of the new point
		
		//if the bounding box hasn't been initialized
		if(!FInit)
		{
			FLeft = FRight = parX;
			FBottom = FTop = parY;
			FInit = true;
		}
		else
		{
			if(parX < FLeft)
				FLeft = parX;
			else if(parX > FRight)
				FRight = parX;

			if(parY < FBottom)
				FBottom = parY;
			else if(parY > FTop)
				FTop = parY;
		}

		UpdateCenter();
	}
    
	/*!
     *  \brief Check intersection
     *
     *  Check intersection with another bounding box 2D
     *
     *  \param b : the other bounding box 2D
     *  \return true a collision is detected,
     *  false else
     */
	bool Intersect(const TBoundingBox2D<T>& parBBox) const
	{
		//checking the two bounding boxes
		LAssert( FInit && parBBox.FInit );

		/**
		T H = (h1 + h2) / 2
		T W = (w1 + w2) / 2
		*/
		T H = ( (FTop - FBottom) + (parBBox.FTop - parBBox.FBottom) ) / (T)2;
		T W = ( (FRight - FLeft) + (parBBox.FRight - parBBox.FLeft) ) / (T)2;

		 return	(parBBox.FX >= FX - W) &&
				(parBBox.FX <= FX + W) &&
				(parBBox.FY >= FY - H) &&
				(parBBox.FY <= FY + H);
	}

	FACE_SIDE Intersect_WithFaceTouch(const TBoundingBox2D<T>& parBBox) const
	{
		//checking the two bounding boxes
		LAssert( FInit && parBBox.FInit );

		/**
		T H = (h1 + h2) / 2
		T W = (w1 + w2) / 2
		*/
		T H = ( (FTop - FBottom) + (parBBox.FTop - parBBox.FBottom) ) / (T)2;
		T W = ( (FRight - FLeft) + (parBBox.FRight - parBBox.FLeft) ) / (T)2;

		bool locIntersect =		(parBBox.FX >= FX - W) &&
								(parBBox.FX <= FX + W) &&
								(parBBox.FY >= FY - H) &&
								(parBBox.FY <= FY + H);

		// Seek for the side collision

		if( !locIntersect )
			return FS_NONE;

		// to keep the faces / faces where the collision is :
		bool locSubBoxTop = false;
		bool locSubBoxBottom = false;
		bool locSubBoxRight = false;
		bool locSubBoxLeft = false;

		if( parBBox.FTop >= FTop )
			locSubBoxTop = true;

		if( parBBox.FBottom <= FBottom )
			locSubBoxBottom = true;

		if( parBBox.FRight >= FRight )
			locSubBoxRight = true;

		if( parBBox.FLeft <= FLeft )
			locSubBoxLeft = true;

		// on a une box qui englobe les 2 bbox, on divise en 4
		// sous box 1 (top ou left)
		if( locSubBoxTop && locSubBoxLeft )
		{
			if( abs( parBBox.FRight - FLeft ) > abs( FTop - parBBox.FBottom ) )
				return FS_TOP;
			else return FS_LEFT;
		}

		// sous box 2 (top ou right)
		if( locSubBoxTop && locSubBoxRight )
		{
			if( abs( FRight - parBBox.FLeft ) > abs( FTop - parBBox.FBottom ) )
				return FS_TOP;
			else return FS_RIGHT;
		}
				
		// sous box 3 (bottom ou left)
		if( locSubBoxBottom && locSubBoxLeft )
		{
			if( abs( parBBox.FRight - FLeft) > abs( parBBox.FTop - FBottom ) )
				return FS_BOTTOM;
			else return FS_LEFT;
		}

		// sous box 4 (bottom ou right)
		if( locSubBoxBottom && locSubBoxRight )
		{
			if( abs( FRight - parBBox.FLeft) > abs( parBBox.FTop - FBottom ) )
				return FS_BOTTOM;
			else return FS_RIGHT;
		}

		if( locSubBoxTop )
			return FS_TOP;

		if( locSubBoxBottom )
			return FS_BOTTOM;

		if( locSubBoxRight )
			return FS_RIGHT;

		if( locSubBoxLeft )
			return FS_LEFT;

		return FS_ERROR;
	}
	
	void Translate(const vector3d<T>& parTranslation)
	{
		//checking the two bounding boxes
		LAssert( FInit );
/*
		FLeft += (T)parTranslation.X;
		FRight += (T)parTranslation.X;
		FTop += (T)parTranslation.Y;
		FBottom += (T)parTranslation.Y;
		FX += (T)parTranslation.X;
		FY += (T)parTranslation.Y;
//*/
//*
		FLeft += (T)parTranslation.X;
		FRight += (T)parTranslation.X;
		FTop += (T)parTranslation.Z;
		FBottom += (T)parTranslation.Z;
		FX += (T)parTranslation.X;
		FY += (T)parTranslation.Z;
//*/
	}

	void Rotate(const vector3d<T>& parRotation, const vector3d<T>& parCenter)
	{
		//checking the two bounding boxes
		LAssert( FInit );

		vector3d<T> locLT(FLeft, 0.f, FTop);
		vector3d<T> locRT(FRight, 0.f, FTop);
		vector3d<T> locLB(FLeft, 0.f, FBottom);
		vector3d<T> locRB(FRight, 0.f, FBottom);

		locLT.rotate(parRotation, parCenter);
		locRT.rotate(parRotation, parCenter);
		locLB.rotate(parRotation, parCenter);
		locRB.rotate(parRotation, parCenter);

		FLeft	= (T)MIN(locLT.X, MIN(locRT.X, MIN(locLB.X, locRB.X)));
		FRight	= (T)MAX(locLT.X, MAX(locRT.X, MAX(locLB.X, locRB.X)));
		FBottom = (T)MIN(locLT.Z, MIN(locRT.Z, MIN(locLB.Z, locRB.Z)));
		FTop	= (T)MAX(locLT.Z, MAX(locRT.Z, MAX(locLB.Z, locRB.Z)));

		UpdateCenter();
	}

	//! Adapt current bbox to contains parBBox
	void AdaptWith(const TBoundingBox2D& parBBox)
	{
		LAssert(parBBox.IsInit());
		LAssert(FInit);

		if(parBBox.FLeft < FLeft)
			FLeft = parBBox.FLeft;

		if(parBBox.FRight > FRight)
			FRight = parBBox.FRight;

		if(parBBox.FBottom < FBottom)
			FBottom = parBBox.FBottom;

		if(parBBox.FTop > FTop)
			FTop = parBBox.FTop;
	}
    
    //! Returns true if these coordinates are in the BoundindBox
	bool IsIn(const vector2d<T>& parPoint)
	{
		LAssert(FInit);

		return	(parPoint.X <= FRight)	&&
				(parPoint.X >= FLeft)	&&
				(parPoint.Y <= FTop)	&&
				(parPoint.Y >= FBottom);
	}

	bool IsIn(const T& parX, const T& parY)
	{
		LAssert(FInit);

		return	(parX <= FRight)	&&
				(parX >= FLeft)		&&
				(parY <= FTop)		&&
				(parY >= FBottom);
	}

	TBoundingBox2D& operator =(const TBoundingBox2D& parBBox)
	{
		FLeft = parBBox.FLeft;
		FRight = parBBox.FRight;
		FTop = parBBox.FTop;
		FBottom = parBBox.FBottom;
		FX = parBBox.FX;
		FY = parBBox.FY;
		FInit = parBBox.FInit;

		return *this;
	}

	bool IsNearAtMost ( const TBoundingBox2D<T>& parBBox, float parPourcent ) const
	{
		//checking the two bounding boxes
		LAssert( FInit && parBBox.FInit );

		vector2df locDistanceBetweenBox( (FX - parBBox.FX), (FY - parBBox.FY) );

		float locLimitDistance = ( GetWidth() + GetHeight() + parBBox.GetWidth() + parBBox.GetHeight() ) /4.f ;

		if( locDistanceBetweenBox.getLength() < ( locLimitDistance + parPourcent ) )
			return true;
			
		return false;
	}

private:
	void UpdateCenter()
	{
		FX = (FRight + FLeft) / (T)2;
		FY = (FTop + FBottom) / (T)2;
	}

	T FLeft;	// left border
	T FRight;	// right border
	T FBottom;	// bottom border
	T FTop;		// top border
	T FX;		// x position
	T FY;		// y position
	
	// true if the bounding box has been initialized
	bool FInit;
};


} // core namespace
} // engine namespace
} // psp namespace

//! Typedef for f32 BoundingBox2D
typedef psp::engine::core::TBoundingBox2D<f32> bb2Df;

#ifdef COMPILE_PC
template<class T>
std::ostream& operator <<(std::ostream& stream, const psp::engine::core::TBoundingBox2D<T>& bbox)
{
	stream << "left " << bbox.GetLeft() << " right " << bbox.GetRight() << " bottom " << bbox.GetBottom() << " top " << bbox.GetTop() << std::endl;

	return stream;
}
#endif

#endif
