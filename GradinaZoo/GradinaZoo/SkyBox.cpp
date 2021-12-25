#include "SkyBox.h"
#include <GL/glew.h>
#include <stb_image.h>
#include <iostream>

SkyBox::SkyBox(Texture* texture)
{
	this->texture = texture;
	InitVAO();
}

SkyBox::~SkyBox()
{
	//delete texture;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void SkyBox::Update(Shader* shader, Camera* camera)
{
	glm::mat4 view = view = glm::mat4(glm::mat3(camera->GetViewMatrix()));
	glm::mat4 projection = camera->GetProjectionMatrix();
	shader->SetMat4fv(view, "view");
	shader->SetMat4fv(projection, "projection");
}

void SkyBox::Render(Shader* shader, Camera* camera)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glDepthFunc(GL_LEQUAL);


	shader->Use();
	Update(shader, camera);

	glBindVertexArray(VAO);
	Bind();

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glDepthFunc(GL_LESS);
	glDisable(GL_CULL_FACE);
}

void SkyBox::Bind()
{
	texture->Bind(0);
}

void SkyBox::InitVAO()
{
	SkyboxCube cube;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, cube.GetNrOfVertices()*sizeof(glm::vec3), cube.GetVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.GetNrOfIndices() * sizeof(GLuint), cube.GetIndices(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
