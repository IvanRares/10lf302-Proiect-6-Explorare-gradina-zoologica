#include "Shader.h"

std::string Shader::LoadShaderSource(const char* filename)
{
	std::string temp = "";
	std::string src = "";

	std::ifstream inFile;

	//vertex
	inFile.open(filename);

	if (inFile.is_open())
	{
		while (std::getline(inFile, temp))
			src += temp + "\n";
	}
	else
	{
		std::cout << "ERROR::SHADER::COULD_NOT_OPEN_FILE: " << filename << std::endl;
	}

	inFile.close();

	return src;
}

GLuint Shader::LoadShader(GLenum type, const char* filename)
{
	char infoLog[512];
	GLint succes;

	GLuint shader = glCreateShader(type);
	std::string strSrc = LoadShaderSource(filename);
	const GLchar* src = strSrc.c_str();
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &succes);
	if (!succes)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COULD_NOT_COMPILE_SHADER: " << filename << std::endl;
		std::cout << infoLog << std::endl;
	}
	return shader;
}

void Shader::LinkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader)
{
	char infoLog[512];
	GLint succes;

	id = glCreateProgram();

	glAttachShader(id, vertexShader);

	if (geometryShader)
	{
		glAttachShader(id, geometryShader);
	}

	glAttachShader(id, fragmentShader);

	glLinkProgram(id);

	glGetProgramiv(id, GL_LINK_STATUS, &succes);
	if (!succes)
	{
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::LOADSHADERS::COULD_NOT_LINK_SHADERS" << std::endl;
		std::cout << infoLog << std::endl;
	}


	glUseProgram(0);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* geometryFile)
{
	GLuint vertexShader = 0;
	GLuint geometryShader = 0;
	GLuint fragmentShader = 0;

	vertexShader = LoadShader(GL_VERTEX_SHADER, vertexFile);
	if (geometryFile != "")
	{
		geometryShader = LoadShader(GL_GEOMETRY_SHADER, geometryFile);
	}
	fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fragmentFile);

	LinkProgram(vertexShader, geometryShader, fragmentShader);

	//End
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(geometryShader);
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

void Shader::Use()
{
	glUseProgram(id);
}

void Shader::Unuse()
{
	glUseProgram(0);
}

void Shader::SetVec3F(glm::fvec3 value, const GLchar* name)
{
	glUniform3fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
}

void Shader::SetVec2F(glm::fvec2 value, const GLchar* name)
{
	glUniform2fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
}

void Shader::SetVec1F(GLfloat value, const GLchar* name)
{
	glUniform1f(glGetUniformLocation(id, name), value);
}

void Shader::SetMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose)
{
	glUniformMatrix4fv(glGetUniformLocation(id, name), 1, transpose, glm::value_ptr(value));
}

void Shader::SetMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose)
{
	glUniformMatrix3fv(glGetUniformLocation(id, name), 1, transpose, glm::value_ptr(value));
}

void Shader::Set1i(GLint value, const GLchar* name)
{
	glUniform1i(glGetUniformLocation(id, name), value);
}

void Shader::SetVec4f(glm::fvec4 value, const GLchar* name)
{
	glUniform4fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
}

