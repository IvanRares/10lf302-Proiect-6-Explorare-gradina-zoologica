#include "Material.h"

Material::Material(glm::vec3 ambient,glm::vec3 diffuse,glm::vec3 specular,GLint diffuseTex,GLint specularTex):
	ambient(ambient),
	diffuse(diffuse),
	specular(specular),
	diffuseTex(diffuseTex),
	specularTex(specularTex)
{
}

void Material::SendToShader(Shader &program)
{
	program.SetVec3F(ambient, "material.ambient");
	program.SetVec3F(diffuse, "material.diffuse");
	program.SetVec3F(specular, "material.specular");
	program.Set1i(diffuseTex, "material.diffuseTex");
	program.Set1i(specularTex, "material.specularTex");
}
