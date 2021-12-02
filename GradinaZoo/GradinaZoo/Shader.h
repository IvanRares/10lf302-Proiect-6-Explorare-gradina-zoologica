#pragma once
#include <iostream>
#include<fstream>
#include<string>

#include<GL\glew.h>
#include<glfw3.h>


#include<GLM.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc\type_ptr.hpp>

class Shader
{
private:
	GLuint id;

	std::string LoadShaderSource(const char* filename);

	GLuint LoadShader(GLenum type, const char* filename);

	void LinkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);
public:
	Shader(const char* vertexFile, const char* fragmentFile, const char* geometryFile = "");

	~Shader();

	void Use();
	void Unuse();

	void SetVec3F(glm::fvec3 value, const GLchar* name);
	void SetVec2F(glm::fvec2 value, const GLchar* name);
	void SetVec1F(GLfloat value, const GLchar* name);
	void SetMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);
	void SetMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE);
	void Set1i(GLint value, const GLchar* name);
	void SetVec4f(glm::fvec4 value, const GLchar* name);
};

