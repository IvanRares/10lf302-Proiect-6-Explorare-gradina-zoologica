#pragma once
#include "libs.h"

enum shaderEnums {
	shaderCoreProgram = 0,
	shaderSkybox
};

enum textureEnum {
	texSkybox = 0,
	texGrass0,
	texBricks0,
	texBars1,
	texBars2,
	texBird,
	texTree1,
	texBench
};

enum materialEnum {
	material0 = 0,
	material1,
	material2,
	material3,
	material4,
	material5,
	material6
};


class Game
{
private:
	GLFWwindow* window;
	const int windowWidth, windowHeight;
	int framebufferWidth, framebufferHeight;
	glm::mat4 ViewMatrix, ProjectionMatrix;
	glm::vec3 camPosition;;
	std::vector<Shader*> shaders;
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	std::vector<Mesh*> meshes;
	std::vector<Model*> models;
	std::vector<glm::vec3*> lights;
	SkyBox* skybox;

	void InitializeGLFW();
	void InitializeWindow(const char* title, bool resizable);
	void InitializeGLEW();
	void InitializeOpenGLOptions();
	void InitializeMatrices();
	void InitializeShaders();
	void InitializeTextures();
	void InitializeSkybox();
	void InitializeMaterials();
	void InitializeModels();
	void InitializeLights();
	void InitializeUniforms();

	void UpdateUniforms();
public:
	static Camera* camera;
	static double deltaTime, lastFrame;

	Game(const char* title, const int width, const int height, bool resizable);
	~Game();

	int GetWindowShouldClose();

	void SetWindowShouldClose();

	void Update();
	void Render();

	static void frameBufferResizeCallback(GLFWwindow* window, int fbW, int fbH);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void UpdateInput(GLFWwindow* window);
};

