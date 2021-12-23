#version 440

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	sampler2D specularTex;
};

in vec3 vsPosition;
in vec2 vsTexCoord;
in vec3 vsNormal;

out vec4 fsColor;

uniform Material material;

uniform vec3 lightPos0;
uniform vec3 cameraPos;

vec3 CalculateAmbient(Material material)
{
	return material.ambient;
}

vec3 CalculateDiffuse(Material material, vec3 vsPosition, vec3 vsNormal, vec3 lightPos0)
{
	vec3 posToLightDirVec = normalize(lightPos0 - vsPosition);
	float diffuse = clamp(dot(posToLightDirVec, vsNormal), 0, 1);
	vec3 diffuseFinal = material.diffuse * diffuse;
	
	return diffuseFinal;
}

vec3 CalculateSpecular(Material material, vec3 vsPosition,vec3 vsNormal, vec3 lightPos0, vec3 cameraPos)
{
	vec3 lightToPosDirVec = normalize(vsPosition - lightPos0);
	vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, normalize(vsNormal)));
	vec3 posToViewDirVec = normalize(cameraPos - vsPosition);
	float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 30);
	vec3 specularFinal = material.specular * specularConstant;

	return specularFinal;
}

void main()
{
	//fsColor = vec4(vsColor,1.f);
	//fsColor = texture(texture0, vsTexCoord) + texture(texture1, vsTexCoord);
	
	//Ambient Light
	vec3 ambientFinal = CalculateAmbient(material);
	
	//Diffuse Light
	vec3 diffuseFinal = CalculateDiffuse(material, vsPosition, vsNormal, lightPos0);
	
	//Specular Light
	vec3 specularFinal = CalculateSpecular(material, vsPosition, vsNormal, lightPos0, cameraPos);

	//Attenuation

	//Final Light
	vec4 texColor = texture(material.diffuseTex, vsTexCoord);
	if(texColor.a < 0.1)
		discard;
	if(lightPos0.y<0.3)
	{
		ambientFinal = vec3(0.01f);
		diffuseFinal = vec3(0.1f);
		specularFinal = vec3(0.1f);
	}
	fsColor = texColor
	* (vec4(ambientFinal,1.f) + vec4(diffuseFinal,1.f) + vec4(specularFinal,1.f));
}