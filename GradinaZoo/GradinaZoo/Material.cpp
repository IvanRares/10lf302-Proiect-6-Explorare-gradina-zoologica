#include "Material.h"

Material::Material(glm::vec3 ambient,glm::vec3 diffuse,glm::vec3 specular,GLint diffuseTex):
	ambient(ambient),
	diffuse(diffuse),
	specular(specular),
	diffuseTex(diffuseTex)
{
}

void Material::SendToShader(Shader &program)
{
	program.SetVec3F(ambient, "material.ambient");
	program.SetVec3F(diffuse, "material.diffuse");
	program.SetVec3F(specular, "material.specular");
	program.Set1i(diffuseTex, "material.diffuseTex");
}
