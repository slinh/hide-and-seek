#include "BoundingBox2D.h"

namespace psp { namespace engine { namespace core {

	template<class T>
	TBoundingBox2D<T>::TBoundingBox2D(): 
	FLeft(0), FRight(0),
	FBottom(0), FTop(0),
	FX(0), FY(0),
	FInit(false) 
	{}

	template<class T>
	TBoundingBox2D<T>::TBoundingBox2D(const TBoundingBox2D<T>& parBBox): 
	FLeft(parBBox.FLeft), FRight(parBBox.FRight),
	FBottom(parBBox.FBottom), FTop(parBBox.FTop),
	FX(parBBox.FX), FY(parBBox.FY),
	FInit(parBBox.FInit) 
	{}
	
	//! Reinitialize Bounding Box
	template<class T>
	void TBoundingBox2D<T>::Reset()
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
	template<class T>
	void TBoundingBox2D<T>::AddPoint(const vector2d<T>& parPoint)
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

	template<class T>
	void TBoundingBox2D<T>::AddPoint(const T& parX, const T& parY)
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
	template<class T>
	bool TBoundingBox2D<T>::Intersect(const TBoundingBox2D<T>& parBBox) const
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

	template<class T>
	FACE_SIDE TBoundingBox2D<T>::Intersect_WithFaceTouch(const TBoundingBox2D<T>& parBBox) const
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

		LOGC_3D(" locSubBoxBottom %d \n", locSubBoxBottom);
		LOGC_3D(" locSubBoxTop %d \n", locSubBoxTop);
		LOGC_3D(" locSubBoxLeft %d \n", locSubBoxLeft);
		LOGC_3D(" locSubBoxRight %d \n", locSubBoxRight);


		return FS_ERROR;
	}
	
	template<class T>
	void TBoundingBox2D<T>::Translate(const vector3d<T>& parTranslation)
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

	template<class T>
	void TBoundingBox2D<T>::Rotate(const vector3d<T>& parRotation, const vector3d<T>& parCenter)
	{
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
	template<class T>
	void TBoundingBox2D<T>::AdaptWith(const TBoundingBox2D<T>& parBBox)
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
	template<class T>
	bool TBoundingBox2D<T>::IsIn(const vector2d<T>& parPoint)
	{
		LAssert(FInit);

		return	(parPoint.X <= FRight)	&&
				(parPoint.X >= FLeft)	&&
				(parPoint.Y <= FTop)	&&
				(parPoint.Y >= FBottom);
	}

	template<class T>
	bool TBoundingBox2D<T>::IsIn(const T& parX, const T& parY)
	{
		LAssert(FInit);

		return	(parX <= FRight)	&&
				(parX >= FLeft)		&&
				(parY <= FTop)		&&
				(parY >= FBottom);
	}

	template<class T>
	TBoundingBox2D<T>& TBoundingBox2D<T>::operator=(const TBoundingBox2D<T>& parBBox)
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

	template<class T>
	bool TBoundingBox2D<T>::IsNearAtMost ( const TBoundingBox2D<T>& parBBox, float parPourcent ) const
	{
		//checking the two bounding boxes
		LAssert( FInit && parBBox.FInit );

		vector2df locDistanceBetweenBox( (FX - parBBox.FX), (FY - parBBox.FY) );

		float locLimitDistance = ( GetWidth() + GetHeight() + parBBox.GetWidth() + parBBox.GetHeight() ) /4. ;

		if( locDistanceBetweenBox.getLength() < ( locLimitDistance + parPourcent ) )
			return true;
			
		return false;
	}
	
	template<class T>
	void TBoundingBox2D<T>::UpdateCenter()
	{
		FX = (FRight + FLeft) / (T)2;
		FY = (FTop + FBottom) / (T)2;
	}

} // core namespace
} // engine namespace
} // psp namespace
