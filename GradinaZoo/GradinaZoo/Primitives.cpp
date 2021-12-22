#include "Primitives.h"

Primitives::Primitives()
{
}

Primitives::~Primitives()
{
}

void Primitives::Set(const Vertex* vertices, const unsigned nrOfVertices, const GLuint* indices, const unsigned nrOfIndices)
{
	for (int i = 0; i < nrOfVertices; i++)
		this->vertices.push_back(vertices[i]);
	for (int i = 0; i < nrOfIndices; i++)
		this->indices.push_back(indices[i]);
}

Vertex* Primitives::GetVertices()
{
	return vertices.data();
}

GLuint* Primitives::GetIndices()
{
	return indices.data();
}

const unsigned Primitives::GetNrOfVertices()
{
	return vertices.size();
}

const unsigned Primitives::GetNrOfIndices()
{
	return indices.size();
}

Triangle::Triangle() :Primitives()
{
	Vertex vertices[] =
	{
		glm::vec3(-0.5f, 0.5f, 0.f),		glm::vec2(0.f,1.f),		glm::vec3(0.f,0.f,1.f),
		glm::vec3(-0.5f,-0.5f,0.f),			glm::vec2(0.f,0.f),		glm::vec3(0.f,0.f,1.f),
		glm::vec3(0.5f, -0.5f, 0.f),		glm::vec2(1.f,0.f),		glm::vec3(0.f,0.f,1.f),
	};
	unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

	GLuint indices[] =
	{
		0,1,2,
	};
	unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
	Set(vertices, nrOfVertices, indices, nrOfIndices);
}

Quad::Quad() :Primitives()
{
	Vertex vertices[] =
	{
		glm::vec3(-0.5f, 0.5f, 0.f),		glm::vec2(0.f,1.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(-0.5f,-0.5f,0.f),			glm::vec2(0.f,0.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(0.5f, -0.5f, 0.f),		glm::vec2(1.f,0.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(0.5f,0.5f,0.f),			glm::vec2(1.f,1.f),		glm::vec3(0.f,1.f,0.f),
	};
	unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

	GLuint indices[] =
	{
		0,1,2,
		0,2,3
	};
	unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
	Set(vertices, nrOfVertices, indices, nrOfIndices);
}

QuadDown::QuadDown() :Primitives()
{
	Vertex vertices[] =
	{
		glm::vec3(-0.5f, 0.f, 0.5f),		glm::vec2(0.f,1.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(-0.5f,0.f,-0.5f),			glm::vec2(0.f,0.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(0.5f, 0.f, -0.5f),		glm::vec2(1.f,0.f),		glm::vec3(0.f,1.f,0.f),
		glm::vec3(0.5f,0.f,0.5f),			glm::vec2(1.f,1.f),		glm::vec3(0.f,1.f,0.f),
	};
	unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

	GLuint indices[] =
	{
		0,1,2,
		0,2,3
	};
	unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
	Set(vertices, nrOfVertices, indices, nrOfIndices);
}
