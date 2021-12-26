#pragma once
#include<GLM.hpp>
struct Vertex
{
	glm::vec3 position;
	glm::vec2 texcoord;
	glm::vec3 normal;
};

struct SpacePositions 
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};