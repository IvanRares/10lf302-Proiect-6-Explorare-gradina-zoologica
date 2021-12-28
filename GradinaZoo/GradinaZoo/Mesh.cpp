#include "Mesh.h"

void Mesh::InitVAO()
{
	//Create VAO
	glCreateVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//GEN VBO AND BIND AND SEND DATA
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, nrOfVertices * sizeof(Vertex), vertexArray.data(), GL_STATIC_DRAW);

	//GEN EBO AND BIND AND SEND DATA
	if (nrOfIndices > 0)
	{
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, nrOfIndices * sizeof(GLuint), indexArray.data(), GL_STATIC_DRAW);
	}
	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Texcoord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(1);
	//Normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);

	//BIND VAO 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::UpdateUniforms(Shader* shader)
{
	shader->SetMat4fv(ModelMatrix, "ModelMatrix");
}

void Mesh::UpdateModelMatrix()
{
	ModelMatrix = glm::mat4(1.f);
	ModelMatrix = glm::translate(ModelMatrix, position);
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
	ModelMatrix = glm::scale(ModelMatrix, scale);
}

Mesh::Mesh(Vertex* vertexArray, const unsigned& nrOfVertices, GLuint* indexArray, const unsigned& nrOfIndices, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	this->nrOfIndices = nrOfIndices;
	this->nrOfVertices = nrOfVertices;

	this->vertexArray.resize(nrOfVertices);
	std::copy_n(vertexArray, nrOfVertices, this->vertexArray.begin());
	this->indexArray.resize(nrOfIndices);
	std::copy_n(indexArray, nrOfIndices, this->indexArray.begin());

	InitVAO();
	UpdateModelMatrix();
}

Mesh::Mesh(Primitives* primitive, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	this->nrOfIndices = primitive->GetNrOfIndices();
	this->nrOfVertices = primitive->GetNrOfVertices();

	vertexArray = std::vector<Vertex>(primitive->GetVertices(), primitive->GetVertices() + nrOfVertices);
	indexArray = std::vector<GLuint>(primitive->GetIndices(), primitive->GetIndices() + nrOfIndices);

	InitVAO();
	UpdateModelMatrix();
}

Mesh::Mesh(const Mesh& obj)
{
	this->position = obj.position;
	this->rotation = obj.rotation;
	this->scale = obj.scale;

	this->nrOfIndices = obj.nrOfIndices;
	this->nrOfVertices = obj.nrOfVertices;

	vertexArray = obj.vertexArray;
	indexArray = obj.indexArray;

	InitVAO();
	UpdateModelMatrix();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	if (nrOfIndices > 0)
		glDeleteBuffers(1, &EBO);
}

void Mesh::SetPosition(const glm::vec3& position)
{
	this->position = position;
}

void Mesh::SetRotation(const glm::vec3& rotation)
{
	this->rotation = rotation;
}

void Mesh::SetScale(const glm::vec3& scale)
{
	this->scale = scale;
}

void Mesh::Move(const glm::vec3& position)
{
	this->position += position;
}

void Mesh::Rotate(const glm::vec3& rotation)
{
	this->rotation += rotation;
}

void Mesh::Scale(const glm::vec3& scale)
{
	this->scale *= scale;
}

void Mesh::Update()
{
}

void Mesh::Render(Shader* shader)
{
	UpdateModelMatrix();
	UpdateUniforms(shader);

	//Bind vertex array object
	glBindVertexArray(this->VAO);

	if (nrOfIndices == 0)
	{
		glDrawArrays(GL_TRIANGLES, 0, nrOfVertices);
	}
	else
		glDrawElements(GL_TRIANGLES, nrOfIndices, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}
