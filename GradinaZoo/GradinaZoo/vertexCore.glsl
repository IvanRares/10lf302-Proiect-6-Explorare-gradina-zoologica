#version 440

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec3 vertexTexCoord;
layout (location = 3) in vec3 vertexNormal;

out vec3 vsPosition;
out vec3 vsColor;
out vec2 vsTexCoord;
out vec3 vsNormal;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
	vsPosition = vec4(ModelMatrix * vec4(vertexPosition,1.f)).xyz;
	vsColor = vertexColor;
	vsTexCoord = vec2(vertexTexCoord.x, vertexTexCoord.y * -1.f);
	vsNormal = mat3(ModelMatrix) * vertexNormal;

	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(vertexPosition,1.f);
}