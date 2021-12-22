#pragma once

#include<GL\glew.h>
#include<glfw3.h>

#include<vector>
#include "Vertex.h"

class Primitives
{
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
public:
	Primitives();
	~Primitives();

	void Set(const Vertex* vertices, const unsigned nrOfVertices, const GLuint* indices,const unsigned nrOfIndices);
	Vertex* GetVertices();
	GLuint* GetIndices();
	const unsigned GetNrOfVertices();
	const unsigned GetNrOfIndices();
};

class Triangle :public Primitives
{
public:
	Triangle();
};

class Quad :public Primitives
{
public:
	Quad();
};

class QuadDown :public Primitives
{
public:
	QuadDown();
};

class SkyboxCube
{
private:
	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;
public:
	SkyboxCube();
	~SkyboxCube();

	glm::vec3* GetVertices();
	GLuint* GetIndices();
	const unsigned GetNrOfVertices();
	const unsigned GetNrOfIndices();
};