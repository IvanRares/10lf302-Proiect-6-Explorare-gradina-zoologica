#pragma once

#include<GL\glew.h>
#include<glfw3.h>

#include<vector>
#include "Vertex.h"

static std::vector<SpacePositions> GetCubeGrassPositions() {
	return {
		{glm::vec3(-5.0f,0.0f,-5.0f), glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,-5.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,-5.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,-5.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,-4.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,-4.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,-4.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,-4.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,-3.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,-3.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,-3.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,-3.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,-2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,-2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,-2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,-2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,-1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,-1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,-1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,-1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,0.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,0.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,0.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,0.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-5.0f,0.0f,1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-4.0f,0.0f,1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-3.0f,0.0f,1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(-2.0f,0.0f,1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,-5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,-5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,-5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,-5.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,-4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,-4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,-4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,-4.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,-3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,-3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,-3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,-3.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,-2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,-2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,-2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,-2.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,-1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,-1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,-1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,-1.0f),   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,0.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,0.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,0.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,0.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,5.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,5.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,5.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,5.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,4.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,4.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,4.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,4.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f,0.0f,3.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f,0.0f,3.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f,0.0f,3.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f,0.0f,3.0f),	   glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f, 0.0f, 2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f, 0.0f, 2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f, 0.0f, 2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f, 0.0f, 2.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(4.0f, 0.0f, 1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(3.0f, 0.0f, 1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(2.0f, 0.0f, 1.0f),  glm::vec3(0.f),glm::vec3(0.f) },
	{glm::vec3(1.0f, 0.0f, 1.0f),   glm::vec3(0.f),glm::vec3(0.f) }
	};
}

static std::vector<SpacePositions> GetCubeBricksPerpendicularPositions() {
	return{
	{glm::vec3(-5.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-4.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-3.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-2.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-5.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-4.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-3.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-2.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(4.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(3.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(2.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(1.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(4.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(3.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(2.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(1.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)}
	};
}

static std::vector<SpacePositions> GetCubeBricksPositions() {
	return{
	{glm::vec3(-1.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,0.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,0.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,5.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,4.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,3.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,2.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.0f,0.0f,1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.0f,0.0f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)}
	};
}

static std::vector<SpacePositions> GetBarsDoorPositions() {
	return{
	{glm::vec3(0.5f,0.5f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)}
	};
}

static std::vector<SpacePositions> GetBarsPositions() {
	return{
	{glm::vec3(0.5f,0.5f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,0.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,2.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,3.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,4.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(0.5f,0.5f,5.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,0.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-1.5f,0.5f,5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,0.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-5.5f,0.5f,5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,0.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,2.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,3.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,4.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(4.5f,0.5f,5.0f),		glm::vec3(0.f),		glm::vec3(0.f)}
	};
};

static std::vector<SpacePositions> GetBarsPerpendicularPositions() {
	return{
		{glm::vec3(-5.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-4.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-3.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-2.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-5.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-4.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-3.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-2.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(4.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(3.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(2.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(1.0f,0.5f,-5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(4.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(3.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(2.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(1.0f,0.5f,-7.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-5.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-4.2f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(3.2f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(4.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(0.f)}
	};
}

static std::vector<SpacePositions> GetTreePositions() {
	return{
	{glm::vec3(2.5f, 0.f, 3.5f),glm::vec3(-90.f, 0.f, 0.f),glm::vec3(0.005f)},
	{glm::vec3(-3.5f, 0.f, 3.5f),glm::vec3(-90.f, 0.f, 0.f),glm::vec3(0.005f)}
	};
}

static std::vector<SpacePositions> GetBenchPositions() {
	return{
	{glm::vec3(-1.2f, 0.f, 3.5f),glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -3.5f),glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -9.f),glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -16.5f),glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -23.f), glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -30.f), glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -35.5f),glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -42.f), glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -48.f), glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-1.2f, 0.f, -56.f), glm::vec3(0.f, 90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, 3.5f),glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -3.5f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -9.f),  glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -16.5f),glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -23.f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -30.f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -35.5f),glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -42.f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -48.f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(0.2f, 0.f, -56.f), glm::vec3(0.f, -90, 0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -7.2f),	glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -7.2f),  glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -20.2f),  glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -20.2f), glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -33.2f),  glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -33.2f), glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -46.2f),  glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -46.2f), glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -59.2f),  glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -59.2f), glm::vec3(0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -5.8f),glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -5.8f), glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -18.8f), glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -18.8f),glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -31.8f), glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -31.8f),glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -44.8f), glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -44.8f),glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(2.5f, 0.f, -57.8f), glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	{glm::vec3(-3.5f, 0.f, -57.8f),glm::vec3(0.f, 180.f, 0.f),glm::vec3(0.002f)},
	};
}

static std::vector<SpacePositions> GetBirdPositions() {
	return {
	{glm::vec3(-3.5f, 0.41f, 3.70f),glm::vec3(-90.f, 0.f, 70.f),glm::vec3(0.01f)},
	{glm::vec3(0.2f, 0.21f, 3.72f),glm::vec3(-90.f, 0.f, 120.f),glm::vec3(0.01f)},
	{glm::vec3(0.3f, 0.21f, 3.72f),glm::vec3(-90.f, 0.f, 70.f),glm::vec3(0.01f)}
	};
}