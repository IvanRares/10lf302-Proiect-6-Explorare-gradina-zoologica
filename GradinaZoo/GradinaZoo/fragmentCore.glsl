#version 440 core

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
};

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;

out vec4 fsColor;

uniform Material material;
uniform sampler2D shadowMap;

uniform vec3 lightPos0;
uniform vec3 cameraPos;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightDir = normalize(lightPos0 - fs_in.FragPos);

    float bias = max(0.05 * (1.0 - dot(normal,lightDir)),0.005);
    //float bias = 0.001;
    //float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
     float shadow = 0.0;
     vec2 texelSize = 1.0 / textureSize(shadowMap,0);
     for(int x = -1;x<=1;++x)
     {
        for(int y = -1;y<=1;++y)
        {
            float pcfDepth = texture(shadowMap,projCoords.xy + vec2(x,y)*texelSize).r;
            shadow+=currentDepth - bias >pcfDepth ? 1.0:0.0;
        }
     }
     shadow/=9.0;
    if(projCoords.z>1.0)
        return 0.0;
     
    return shadow;
}

void main()
{
	vec4 texColor = texture(material.diffuseTex, fs_in.TexCoords);
	vec3 color = texture(material.diffuseTex, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightColor = vec3(1.0);
    // ambient
   vec3 ambient = material.ambient * color;
   //vec3 ambient = 0.3 * color;
    // diffuse
    vec3 lightDir = normalize(lightPos0 - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.0);
   vec3 diffuse = diff * material.diffuse;
  // vec3 diffuse = diff * lightColor;
    // specular
    vec3 viewDir = normalize(cameraPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
   vec3 specular = spec * material.specular;  
    //vec3 specular = spec * lightColor;    
    // calculate shadow
    float shadow = ShadowCalculation(fs_in.FragPosLightSpace);  
    vec3 lighting = (ambient +   (diffuse + specular)) * color; 
    if (texColor.a < 0.1)
        discard;
	fsColor = vec4(lighting,texColor.a);
    //fsColor = vec4(1.0,0.0,0.0,1.0);
}