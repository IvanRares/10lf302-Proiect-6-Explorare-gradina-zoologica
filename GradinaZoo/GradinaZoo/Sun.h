#pragma once
#include "Primitives.h"
#include "Shader.h"
class Sun
{
public:
	Sun() = default;
	Sun(glm::vec3 lightPos);
	void Render(Shader* shader,double currentFrame);
	glm::vec3 GetLightPos();
private:
	glm::vec3 lightPos;
	void InitVAO();
	GLuint VAO, VBO, EBO;
};

