#pragma once

#include <iostream>
#include<string>

#include<GL\glew.h>
#include<glfw3.h>
#include <vector>
class Texture
{
private:
	GLuint id;
	int height, width;
	unsigned int type,rgbType;
public:
	Texture(const char* filename, GLenum type,GLenum rgbType);
	Texture(std::vector<std::string> filenames, GLenum type);
	~Texture();
	GLuint GetID()const;
	void Bind(const GLint textureUnit);
	void Unbind();

	void loadFromFile(std::vector<std::string> filename);
	void loadFromFile(const char* filename);
};

