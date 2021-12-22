#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>


Texture::Texture(const char* filename, GLenum type, GLenum rgbType)
{
	this->type = type;
	this->rgbType = rgbType;
	loadFromFile(filename);
}

Texture::Texture(std::vector<std::string> filenames)
{
	loadFromFile(filenames);
}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

GLuint Texture::GetID() const
{
	return id;
}

void Texture::Bind(const GLint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(type, id);
}

void Texture::Unbind()
{
	glActiveTexture(0);
	glBindTexture(type, 0);
}

void Texture::loadFromFile(std::vector<std::string> filename)
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, id);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		unsigned char* data = stbi_load(filename[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap tex failed to load at path: " << filename[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glActiveTexture(0);
	glBindTexture(type, 0);
}

void Texture::loadFromFile(const char* filename)
{
	if (id)
	{
		glDeleteTextures(1, &id);
	}
	unsigned char* image = stbi_load(filename, &width, &height, NULL, 0);
	glGenTextures(1, &id);
	glBindTexture(type, id);

	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (image)
	{
		glTexImage2D(type, 0, rgbType, width, height, 0, rgbType, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(type);
	}
	else
	{
		std::cout << "ERROR::TEXTURE::TEXTURE_LOADING_FAILED: " << filename << std::endl;
	}
	//Unbind texture
	glActiveTexture(0);
	glBindTexture(type, 0);
	stbi_image_free(image);
}
