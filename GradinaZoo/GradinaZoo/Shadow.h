#pragma once
#include "Texture.h"
#include<GL\glew.h>
#include<glfw3.h>

#include<GLM.hpp>

#include<gtc\matrix_transform.hpp>
#include "Shader.h"
#include "Model.h"

class Shadow
{
public:
	Shadow();
	void PrepareRender();
private:
	//Texture* texture;
	GLuint FBO, depthMap;
	const unsigned shadowWidth = 512, shadowHeight = 512;
	void InitFBO();
};

