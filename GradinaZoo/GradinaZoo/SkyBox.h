#pragma once
#include <string>
#include <vector>
#include "Texture.h"
#include "Primitives.h"
#include "Shader.h"
#include "Camera.h"

class SkyBox
{
public:
	SkyBox(Texture *texture);
	~SkyBox();
	
	void Update(Shader* shader, Camera* camera);
	void Render(Shader* shader,Camera* camera);
	void Bind();

	int width, height, nrChannels;
	unsigned char* data;


private:
	GLuint VAO, VBO, EBO;
	void InitVAO();
	Texture* texture;

};

