#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

namespace psp { namespace engine { namespace video {

//! Some types of material used in pipeline rendering.
enum MATERIAL_TYPE
{
	//! Standard solid material. Only first texture is used, as
	//! the diffuse material
	MT_SOLID = 0,

	//! Material type with standard lightmap technique: 
	//! There should be 2 textures: The first texture layer is a diffuse map,
	//! the second is a light map. Vertex light is ignored
	MT_LIGHTMAP,

	//! A transparent material. Only the first texture is used.
	//! The new color is calculated by simply adding the source color and
	//! the dest color
	MT_TRANSPARENT_ADD_COLOR,

	//! Makes the material transparent based on the vertex alpha value.
	MT_TRANSPARENT_VERTEX_ALPHA,

	//! A solid normal map renderer. First texture is the color map, the 
	//! second should be the normal map
	MT_NORMAL_MAP_SOLID,
	
	MT_NORMAL_MAP_TRANSPARENT_ADD_COLOR,
	
	MT_NORMAL_MAP_VERTEX_ALPHA,

	//! This value is not used. It only forces this enumeration to compile in 32 bit. 
	MT_FORCE_32BIT = 0x7fffffff
};

struct TMaterial
{
	TMaterial():
	FMaterialType(MT_SOLID), FAmbientColor(255,255,255,255), 
	FDiffuseColor(255,255,255,255), FEmissiveColor(0,0,0,0),
	FSpecularColor(255,255,255,255), FShininess(0.0f)
	{}

	TMaterial(const TMaterial& parMat):
	FMaterialType(parMat.FMaterialType), FAmbientColor(parMat.FAmbientColor), 
	FDiffuseColor(parMat.FDiffuseColor), FEmissiveColor(parMat.FEmissiveColor),
	FSpecularColor(parMat.FSpecularColor), FShininess(parMat.FShininess)
	{}

	~TMaterial()
	{}

	//! Type of the material
	MATERIAL_TYPE FMaterialType;

	//! How much ambient light (a global light) is reflected by this material
	//  Default as white
	TColor FAmbientColor;		

	//! How much diffuse light coming from a light source is reflected by this material
	//  Default as white
	TColor FDiffuseColor;		

	//! Light emitted by this material
	//  Default no light
	TColor FEmissiveColor;	

	//! How much specular light (highlights from a light) is reflected
	//  Default reflect white specular light
	TColor FSpecularColor;

	//! Value affecting the size of specular highlights
	f32 FShininess;

	// Material Textures
};

} // namespace video
} // namespace engine
} // namespace psp

#endif
