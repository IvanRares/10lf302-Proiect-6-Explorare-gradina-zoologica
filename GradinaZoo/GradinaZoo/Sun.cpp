#include "Sun.h"

Sun::Sun(glm::vec3 lightPos)
{
	this->lightPos = lightPos;
	InitVAO();
}

void Sun::Render(Shader* shader, double currentFrame)
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glDepthFunc(GL_LEQUAL);

	lightPos.z = glm::sin(currentFrame)*0.001f;
	lightPos.y = glm::cos(currentFrame) * 0.001f;

	shader->Use();
	glm::mat4 model = glm::translate(glm::mat4(1.0), lightPos);
	model = glm::scale(model, glm::vec3(0.5f));
	//shader->SetMat4fv(model, "model");
	//shader->SetMat4fv(glm::mat4(1.f), "model");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);

	glDepthFunc(GL_LESS);
	glDisable(GL_CULL_FACE);
	glActiveTexture(0);
}

glm::vec3 Sun::GetLightPos()
{
	return lightPos;
}

void Sun::InitVAO()
{
	SkyboxCube cube;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, cube.GetNrOfVertices() * sizeof(glm::vec3), cube.GetVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.GetNrOfIndices() * sizeof(GLuint), cube.GetIndices(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
