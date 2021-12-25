#version 440 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 vertexTexCoord;
layout (location = 2) in vec3 vertexNormal;

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} vs_out;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 lightSpaceMatrix;

void main()
{
    vs_out.FragPos = vec3(ModelMatrix * vec4(vertexPosition, 1.0));
    vs_out.Normal = transpose(inverse(mat3(ModelMatrix))) * vertexNormal;
    vs_out.TexCoords = vec2(vertexTexCoord.x,vertexTexCoord.y * -1.0);
    vs_out.FragPosLightSpace = lightSpaceMatrix * ModelMatrix * vec4(vertexPosition, 1.0);

    gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(vertexPosition, 1.0);
}