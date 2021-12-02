#pragma once

#include <iostream>
#include<string>

#include<GL\glew.h>
#include<glfw3.h>
class Texture
{
private:
	GLuint id;
	int height, width;
	unsigned int type,rgbType;
public:
	Texture(const char* filename, GLenum type,GLenum rgbType);
	~Texture();
	GLuint GetID()const;
	void Bind(const GLint textureUnit);
	void Unbind();

	void loadFromFile(const char* filename);
};

