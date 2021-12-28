#pragma once
#include "libs.h"

enum shaderEnums {
	shaderCoreProgram = 0,
	shaderSkybox,
	shaderShadow
};

enum textureEnum {
	texSkybox = 0,
	texGrass0,
	texBricks0,
	texBars1,
	texBars2,
	texBird,
	texTree1,
	texBench,
	texBarrack,
	texGrass1,
	texCamel,
	texBear,
	texDeer,
	texKangaroo,
	texLion,
	texMonkey,
	texPenguin,
	texSeaLion,
	texSeaTurtle,
	texTiger,
	texShop1,
	texShop2,
	texIce,
	texJungle,
	texSand,
	texSavannah,
	texShop3,
	texTrashCan,
	texHedge
};

enum materialEnum {
	material0 = 0,
	material1,
	material2,
	material3,
	material4,
	material5,
	material6,
	material7,
	material8,
	material9,
	material10,
	material11,
	material12,
	material13,
	material14,
	material15,
	material16,
	material17,
	material18,
	material19,
	material20,
	material21,
	material22,
	material23,
	material24,
	material25,
	material26,
	material27
};

enum modelEnum {
	Grass=0,
	Brick=5,
	barsDoor=10,
	BrickPerpendicular=15,
	bars=20,
	barsPerpendicular=25,
	grass3d=30,
	bird=33,
	tree,
	bench,
	cottage,
	camel,
	bear,
	deer,
	kangaroo,
	lion,
	monkey,
	penguin,
	seaLion,
	seaTurtle,
	tiger,
	shop1,
	shop2,
	shop3,
	trashcan,
	hedge,
	movableBear,
	movablePenguin,
	movableKangaroo,
	movableMonkey
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
	Shadow* shadow;

	void InitializeGLFW();
	void InitializeWindow(const char* title, bool resizable);
	void InitializeGLEW();
	void InitializeOpenGLOptions();
	void InitializeMatrices();
	void InitializeShaders();
	void InitializeTextures();
	void InitializeSkybox();
	void InitializeShadows();
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
	void RenderModels(Shader* shader);

	void RenderMovablePenguin(Shader* shader);
	void RenderMovableBear(Shader* shader);
	void RenderMovableKangaroo(Shader* shader);
	void RenderMovableMonkey(Shader* shader);

	static void frameBufferResizeCallback(GLFWwindow* window, int fbW, int fbH);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void UpdateInput(GLFWwindow* window);
};

