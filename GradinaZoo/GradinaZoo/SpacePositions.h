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
	{glm::vec3(1.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-7.0f),	 glm::vec3(0.f),	glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-6.0f),	 glm::vec3(0.f),	glm::vec3(0.f)}
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
	{glm::vec3(0.0f,0.0f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,5.0f),	    glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,4.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,3.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,2.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,5.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,4.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,3.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,2.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,1.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,0.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,0.0f),		glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,0.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,0.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(6.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(5.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-6.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-6.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-7.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-5.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-4.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-3.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-2.0f),	glm::vec3(0.f),		glm::vec3(0.f)},
	{glm::vec3(-7.0f,0.0f,-1.0f),	glm::vec3(0.f),		glm::vec3(0.f)}
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
		{glm::vec3(-5.f,0.5f,5.5f),		glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(-4.2f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(3.2f,0.5f,5.5f),		glm::vec3(0.f),		glm::vec3(0.f)},
		{glm::vec3(4.f,0.5f,5.5f),		glm::vec3(0.f),		glm::vec3(0.f)}
	};
}

static std::vector<SpacePositions> GetTreePositions() {
	return{
	{glm::vec3(2.5f, 0.f, 3.5f),glm::vec3(-90.f, 0.f, 0.f),glm::vec3(0.005f)},
	{glm::vec3(-3.5f, 0.f, 3.5f),glm::vec3(-90.f, 0.f, 0.f),glm::vec3(0.005f)},
	{glm::vec3(-5.175f, 0.f, -0.647f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(0.003f)},
	{glm::vec3(3.975f, 0.f, -0.947f),glm::vec3(-90.f, 0.f, +35.f),glm::vec3(0.005f)},
	{glm::vec3(-3.175f, 0.f, -3.647f),glm::vec3(-90.f, 0.f, 65.f),glm::vec3(0.013f)},
	{glm::vec3(1.975f, 0.f, -3.947f),glm::vec3(-90.f, 0.f, +35.f),glm::vec3(0.003f)},
	{glm::vec3(-5.10392f, 0.f, -23.8644f),glm::vec3(-90.f, 0.f, -65.f),glm::vec3(0.007f)},
	{glm::vec3(2.05981f, 0.f, -27.7223f),glm::vec3(-90.f, 0.f, -65.f),glm::vec3(0.02f)},
	{glm::vec3(-3.25985f, 0.f, -30.0341f),glm::vec3(-90.f, 0.f, 115.f),glm::vec3(0.015f)},
	{glm::vec3(3.58082f, 0.f, -54.549f),glm::vec3(-90.f, 0.f, -140.f),glm::vec3(0.028f)},
	{glm::vec3(-4.5f, 0.f, -56.549f),glm::vec3(-90.f, 0.f, 140.f),glm::vec3(0.015f)},
	{glm::vec3(-3.f, 0.f, -48.549f),glm::vec3(-90.f, 0.f, 90.f),glm::vec3(0.011f)}
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

static std::vector<SpacePositions> GetCamelPositions() {
	return{
		{glm::vec3(-2.87647f, 0.f, -9.052f),glm::vec3(-90.f, 0.f, 60.f),glm::vec3(0.0017f)},
		{glm::vec3(-3.05808f, 0.f, -13.3399f),glm::vec3(-90.f, 0.f, 95.f),glm::vec3(0.001f)},
		{glm::vec3(-2.05808f, 0.f, -14.3399f),glm::vec3(-90.f, 0.f, 10.f),glm::vec3(0.0012f)},
		{glm::vec3(-3.05808f, 0.f, -12.3399f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(0.0016f)},
		{glm::vec3(-2.08846f, 0.f, -9.99188f),glm::vec3(-90.f, 0.f, 65.f),glm::vec3(0.0007f)}
	};
}

static std::vector<SpacePositions> GetBearPositions() {
	return{
		{glm::vec3(-2.64299f, 0.f, -1.62042f),glm::vec3(-90.f, 0.f, 60.f),glm::vec3(0.0122f)},
		{glm::vec3(-3.05808f, 0.f, -2.3399f),glm::vec3(-90.f, 0.f, 95.f),glm::vec3(0.0127f)},
		{glm::vec3(-2.08846f, 0.f, 1.99188f),glm::vec3(-90.f, 0.f, 65.f),glm::vec3(0.0125f)},
		{glm::vec3(-2.03846f, 0.f, 0.99188f),glm::vec3(-90.f, 0.f, 35.f),glm::vec3(0.007f)}
	};
}

static std::vector<SpacePositions> GetDeerPositions() {
	return{
		{glm::vec3(1.44107f, 0.f, 3.84712f),glm::vec3(-90.f, 0.f, 200.f),glm::vec3(0.0122f)},
		{glm::vec3(1.95808f, 0.f, -2.3399f),glm::vec3(-90.f, 0.f, 170.f),glm::vec3(0.0127f)},
		{glm::vec3(2.08846f, 0.f, 1.99188f),glm::vec3(-90.f, 0.f, 165.f),glm::vec3(0.0125f)},
		{glm::vec3(2.83846f, 0.f, 0.99188f),glm::vec3(-90.f, 0.f, 100.f),glm::vec3(0.007f)},
		{glm::vec3(2.03846f, 0.f, 1.5f),glm::vec3(-90.f, 0.f, 150.f),glm::vec3(0.007f)}
	};
}

static std::vector<SpacePositions> GetKangarooPositions() {
	return{
		{glm::vec3(1.5f, 0.f, - 21.f),glm::vec3(-90.f, 0.f, 210.f),glm::vec3(0.004f)},
		{glm::vec3(2.5f, 0.f, - 22.f),glm::vec3(-90.f, 0.f, 180.f),glm::vec3(0.002f)},
		{glm::vec3(3.5f, 0.f, - 23.f),glm::vec3(-90.f, 0.f, 10.f),glm::vec3(0.002f)},
		{glm::vec3(1.f, 0.f, - 24.f),glm::vec3(-90.f, 0.f, 150.f),glm::vec3(0.002f)},
		{glm::vec3(1.25f, 0.f, - 25.f),glm::vec3(-90.f, 0.f, 240.f),glm::vec3(0.004f)},
	}; 
}

static std::vector<SpacePositions> GetLionPositions() {
	return{
		{glm::vec3(4.0f, 0.f, -48.3943f),glm::vec3(-90.f, 0.f, 95.f),glm::vec3(0.005f)},
		{glm::vec3(2.7f, 0.f, -49.3943f),glm::vec3(-90.f, 0.f,65.f),glm::vec3(0.0038f)},
		{glm::vec3(1.f, 0.f, -51.3943),glm::vec3(-90.f, 0.f, -80.f),glm::vec3(0.002f)},
		{glm::vec3(2.1f, 0.f, -54.3943f),glm::vec3(-90.f, 0.f, -70.f),glm::vec3(0.006f)},
		{glm::vec3(3.f, 2.2f, - 55.4f),glm::vec3(-90.f, 20.f, -70.f),glm::vec3(0.0035f)},
	};
}

static std::vector<SpacePositions> GetMonkeyPositions() {
	return{
		{glm::vec3(-3.61088f, 1.31056f, -30.192f),glm::vec3(-120.f, 0.f, -80.f),glm::vec3(0.009f)},
		{glm::vec3(-2.67748f, 0.f, -26.7762f),glm::vec3(-90.f, 0.f, 95.f),glm::vec3(0.005f)},
		{glm::vec3(-2.8685f, 0.f, -22.7438f),glm::vec3(-90.f, 0.f, 10.f),glm::vec3(0.006f)},
		{glm::vec3(-3.03727f, 0.772899f, -29.8107f),glm::vec3(0.f, 30.f, 180.f),glm::vec3(0.006f)},
		{glm::vec3(-3.46937f, 0.f, -21.0213f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(0.007f)},
		{glm::vec3(-4.87157f, 0.f, -22.3631f),glm::vec3(-90.f, 0.f, 65.f),glm::vec3(0.004f)},
		{glm::vec3(-1.91032f, 0.f, -25.1719f),glm::vec3(-90.f, 0.f, 65.f),glm::vec3(0.007f)}
	};
}

static std::vector<SpacePositions> GetPenguinPositions() {
	return{
		{glm::vec3(-3.083368f, 0.f, -40.0953f),glm::vec3(0.f, 25.f, 0.f),glm::vec3(0.6f)},
		{glm::vec3(-2.67748f, 0.f, -36.7762f),glm::vec3(0.f, 55.f, 0.f),glm::vec3(0.5f)},
		{glm::vec3(-2.8685f, 0.f, -38.7438f),glm::vec3(0.f, 80.f, 0.f),glm::vec3(0.2f)},
		{glm::vec3(-3.03727f, 0.02f, -41.8107f),glm::vec3(70.f, 0.f, 0.f),glm::vec3(0.3f)},
		{glm::vec3(-3.46937f, 0.f, -42.0213f),glm::vec3(0.f, 99.f, 0.f),glm::vec3(0.6f)},
		{glm::vec3(-4.87157f, 0.f, -43.3631f),glm::vec3(0.f, 123.f, 0.f),glm::vec3(0.2f)},
		{glm::vec3(-1.91032f, 0.f, -39.1719f),glm::vec3(0.f, 35.f, 0.f),glm::vec3(0.3f)}
	};
}

static std::vector<SpacePositions> GetSeaLionPositions() {
	return{
		{glm::vec3(3.083368f, 0.f, -40.0953f),glm::vec3(-90.f, 0.f, 134.f),glm::vec3(0.006f)},
		{glm::vec3(1.67748f, 0.f, -36.7762f),glm::vec3(-90.f, 0.f, 0.f),glm::vec3(0.005f)},
		{glm::vec3(2.8685f, 0.f, -38.7438f),glm::vec3(-90.f, 0.f, -80.f),glm::vec3(0.002f)},
		{glm::vec3(3.03727f, 0.02f, -41.8107f),glm::vec3(-90.f, 0.f, -50.f),glm::vec3(0.003f)},
		{glm::vec3(1.46937f, 0.f, -42.0213f),glm::vec3(-90.f, 0.f, -94.f),glm::vec3(0.006f)},
		{glm::vec3(3.87157f, 0.f, -43.3631f),glm::vec3(-90.f, 0.f, 90.f),glm::vec3(0.002f)},
		{glm::vec3(2.91032f, 0.f, -39.1719f),glm::vec3(-90.f, 0.f, -46.f),glm::vec3(0.003f)}
	};
}

static std::vector<SpacePositions> GetSeaTurtlePositions() {
	return{
		{glm::vec3(2.87647f, 0.f, -9.052f),glm::vec3(-90.f, 0.f, 60.f),glm::vec3(0.009f)},
		{glm::vec3(3.05808f, 0.f, -13.3399f),glm::vec3(-90.f, 0.f, -123.f),glm::vec3(0.005f)},
		{glm::vec3(2.05808f, 0.f, -14.3399f),glm::vec3(-90.f, 0.f, 117.f),glm::vec3(0.004f)},
		{glm::vec3(3.05808f, 0.f, -12.3399f),glm::vec3(-90.f, 0.f, -41.f),glm::vec3(0.004f)},
		{glm::vec3(2.08846f, 0.f, -15.99188f),glm::vec3(-90.f, 0.f, 67.f),glm::vec3(0.006f)},
		{glm::vec3(2.f,		 0.f, -16.052f),glm::vec3(-90.f, 0.f, -60.f),glm::vec3(0.007f)},
		{glm::vec3(3.,		 0.f, -17.3399f),glm::vec3(-90.f, 0.f, -94.f),glm::vec3(0.008f)},
		{glm::vec3(1.95808f, 0.f, -15.3399f),glm::vec3(-90.f, 0.f,-134.f),glm::vec3(0.005f)},
		{glm::vec3(1.45808f, 0.f, -11.3399f),glm::vec3(-90.f, 0.f, -178.f),glm::vec3(0.007f)},
		{glm::vec3(3.38846f, 0.f, -9.99188f),glm::vec3(-90.f, 0.f, -58.f),glm::vec3(0.004f)}
	};
}

static std::vector<SpacePositions> GetTigerPositions() {
	return{
		{glm::vec3(-3.0f, 0.f, -50.3943f),glm::vec3(0.f, 150.f, 0.f),glm::vec3(0.15f)},
		{glm::vec3(-2.7f, 0.f, -53.3943f),glm::vec3(0.f, 25.f, 0.f),glm::vec3(0.15f)},
		{glm::vec3(-3.f, 0.f, -51.3943),glm::vec3(0.f, 120.f, 0.f),glm::vec3(0.1f)},
		{glm::vec3(-3.1f, 0.f, -52.3943f),glm::vec3(0.f, 70.f, 0.f),glm::vec3(0.1f)},
	};
}

static std::vector<SpacePositions> GetTrashcanPositions() {
	return{
		{glm::vec3(0.4f,0.05f,-5.6f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-5.6f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-7.4f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-7.4f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-18.6f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-18.6f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-20.4f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-20.4f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-31.6f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-31.6f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-33.4f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-33.4f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-44.6f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-44.6f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-46.4f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-46.4f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(0.4f,0.05f,-57.6f),glm::vec3(-90.f, 0.f, 45.f),glm::vec3(1.f)},
		{glm::vec3(-1.4f,0.05f,-57.6f),glm::vec3(-90.f, 0.f, -45.f),glm::vec3(1.f)}
	};
}
static std::vector<SpacePositions> GetShopPositions() {
	return{
		{glm::vec3(7.35f, 0.f, -8.f),glm::vec3(-90.f, 0.f, -90.f),glm::vec3(0.0048f)},
		{glm::vec3(-8.35f, 0.0f, -44.f),glm::vec3(-90.f, 0.f, 90.f),glm::vec3(0.0048f)}
	};
}

static std::vector<SpacePositions> GetHedgePositions() {
	return{
	{glm::vec3(-7.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-6.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-5.f,0.5f,5.51f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-4.2f,0.5f,5.51f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-3.9f,0.5f,6.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-3.9f,0.5f,7.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,5.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,4.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,3.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,2.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,1.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,0.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-1.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-2.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-3.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-4.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-5.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-6.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-7.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-8.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-9.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-10.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-11.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-12.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-13.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-14.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-15.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-16.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-17.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-18.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-19.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-20.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-21.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-22.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-23.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-24.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-25.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-26.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-27.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-28.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-29.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-30.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-31.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-32.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-33.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-34.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-35.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-36.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-37.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-38.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-39.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-40.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-41.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-42.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-43.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-44.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-45.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-46.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-47.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-48.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-49.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-50.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-51.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-52.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-53.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-54.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-55.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-56.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-57.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-58.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(-7.5f,0.5f,-59.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},

	{glm::vec3(6.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(5.f,0.5f,5.5f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(4.f,0.5f,5.51f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(3.2f,0.5f,5.51f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(3.f,0.5f,6.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(3.f,0.5f,7.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,5.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,4.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,3.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,2.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,1.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,0.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-1.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-2.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-3.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-4.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-5.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-6.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-7.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-8.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-9.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-10.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-11.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-12.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-13.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-14.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-15.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-16.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-17.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-18.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-19.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-20.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-21.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-22.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-23.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-24.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-25.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-26.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-27.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-28.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-29.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-30.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-31.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-32.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-33.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-34.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-35.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-36.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-37.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-38.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-39.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-40.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-41.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-42.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-43.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-44.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-45.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-46.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-47.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-48.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-49.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-50.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-51.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-52.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-53.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-54.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-55.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-56.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-57.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-58.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},
	{glm::vec3(6.5f,0.5f,-59.f),	glm::vec3(-90.f),		glm::vec3(1.f,1.3f,1.f)},

	{ glm::vec3(6.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(5.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(4.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(3.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(2.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(1.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(0.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-1.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-2.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-3.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-4.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-5.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-6.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) },
	{ glm::vec3(-7.f,0.5f,-59.45f),	glm::vec3(0.f),		glm::vec3(1.f,1.3f,1.f) }

	};
}