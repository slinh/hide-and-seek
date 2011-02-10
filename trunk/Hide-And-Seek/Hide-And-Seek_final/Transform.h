#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3d.h"
#include "BoundingBox2D.h"
#include "WriteFile.h"
#include "ReadFile.h"

namespace psp { namespace engine { 

	using namespace core;
	using namespace io;
	
	namespace video {

	class TTransform
	{
		/*	Fields	*/
	private:
		vector3df FTranslation;
		vector3df FRotation;

		/*	Method	*/
	public:
		TTransform(void);
		TTransform(c8** parBuffer);
		TTransform(const vector3df &parTranslation, const vector3df &parRotation);
		TTransform(const TTransform& parTransform);
		~TTransform(void);

		bb2Df& ApplyTransform(bb2Df &parBBox) const;
		
		static u32 SerializedSize();
		void Serialize(c8** parBuffer);
		void Deserialize(c8** parBuffer);

		GETTER_SETTER(vector3df, Translation)
		GETTER(vector3df, Rotation)
	};

} // engine video
} // engine namespace
} // psp namespace

#endif
