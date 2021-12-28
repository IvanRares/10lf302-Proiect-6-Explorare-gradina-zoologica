#pragma once
#include<iostream>
#include<vector>
#include"Shader.h"
#include"Texture.h"
#include"Material.h"
#include"Vertex.h"
#include"Primitives.h"
class Mesh
{
private:
	std::vector<Vertex> vertexArray;
	std::vector<GLuint> indexArray;
	//std::vector<Texture> textures;
	unsigned nrOfVertices, nrOfIndices;

	GLuint VAO, VBO, EBO;

	glm::vec3 position, rotation, scale;
	glm::mat4 ModelMatrix;
	void InitVAO();
	void UpdateUniforms(Shader* shader);
	void UpdateModelMatrix();
public:
	Mesh(Vertex* vertexArray, const unsigned& nrOfVertices, GLuint* indexArray, const unsigned& nrOfIndices, glm::vec3 position = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f));
	Mesh(Primitives* primitive, glm::vec3 position = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f));
	Mesh(const Mesh& obj);
	~Mesh();

	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::vec3& rotation);
	void SetScale(const glm::vec3& scale);
	void Move(const glm::vec3& position);
	void Rotate(const glm::vec3& rotation);
	void Scale(const glm::vec3& scale);

	void Update();
	void Render(Shader* shader);
};

