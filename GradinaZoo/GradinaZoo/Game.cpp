#include "Game.h"
#include <random>
//Camera Game::camera = nullptr;
double Game::deltaTime = 0.0f;
double Game::lastFrame = 0.0f;
Camera* Game::camera = nullptr;

glm::vec3 cubeGrassPositions[] = {
	//stanga (spate-fata)
	// 1
	glm::vec3(-5.0f,0.0f,-5.0f),
	glm::vec3(-4.0f,0.0f,-5.0f),
	glm::vec3(-3.0f,0.0f,-5.0f),
	glm::vec3(-2.0f,0.0f,-5.0f),
	// 2
	glm::vec3(-5.0f,0.0f,-4.0f),
	glm::vec3(-4.0f,0.0f,-4.0f),
	glm::vec3(-3.0f,0.0f,-4.0f),
	glm::vec3(-2.0f,0.0f,-4.0f),
	// 3
	glm::vec3(-5.0f,0.0f,-3.0f),
	glm::vec3(-4.0f,0.0f,-3.0f),
	glm::vec3(-3.0f,0.0f,-3.0f),
	glm::vec3(-2.0f,0.0f,-3.0f),
	// 4
	glm::vec3(-5.0f,0.0f,-2.0f),
	glm::vec3(-4.0f,0.0f,-2.0f),
	glm::vec3(-3.0f,0.0f,-2.0f),
	glm::vec3(-2.0f,0.0f,-2.0f),
	// 5
	glm::vec3(-5.0f,0.0f,-1.0f),
	glm::vec3(-4.0f,0.0f,-1.0f),
	glm::vec3(-3.0f,0.0f,-1.0f),
	glm::vec3(-2.0f,0.0f,-1.0f),
	// 6
	glm::vec3(-5.0f,0.0f,0.0f),
	glm::vec3(-4.0f,0.0f,0.0f),
	glm::vec3(-3.0f,0.0f,0.0f),
	glm::vec3(-2.0f,0.0f,0.0f),
	// 7
	glm::vec3(-5.0f,0.0f,5.0f),
	glm::vec3(-4.0f,0.0f,5.0f),
	glm::vec3(-3.0f,0.0f,5.0f),
	glm::vec3(-2.0f,0.0f,5.0f),
	// 8
	glm::vec3(-5.0f,0.0f,4.0f),
	glm::vec3(-4.0f,0.0f,4.0f),
	glm::vec3(-3.0f,0.0f,4.0f),
	glm::vec3(-2.0f,0.0f,4.0f),
	// 9
	glm::vec3(-5.0f,0.0f,3.0f),
	glm::vec3(-4.0f,0.0f,3.0f),
	glm::vec3(-3.0f,0.0f,3.0f),
	glm::vec3(-2.0f,0.0f,3.0f),
	// 10
	glm::vec3(-5.0f,0.0f,2.0f),
	glm::vec3(-4.0f,0.0f,2.0f),
	glm::vec3(-3.0f,0.0f,2.0f),
	glm::vec3(-2.0f,0.0f,2.0f),
	// 11
	glm::vec3(-5.0f,0.0f,1.0f),
	glm::vec3(-4.0f,0.0f,1.0f),
	glm::vec3(-3.0f,0.0f,1.0f),
	glm::vec3(-2.0f,0.0f,1.0f),

	//dreapta
	// 1
	glm::vec3(4.0f,0.0f,-5.0f),
	glm::vec3(3.0f,0.0f,-5.0f),
	glm::vec3(2.0f,0.0f,-5.0f),
	glm::vec3(1.0f,0.0f,-5.0f),
	// 2
	glm::vec3(4.0f,0.0f,-4.0f),
	glm::vec3(3.0f,0.0f,-4.0f),
	glm::vec3(2.0f,0.0f,-4.0f),
	glm::vec3(1.0f,0.0f,-4.0f),
	// 3
	glm::vec3(4.0f,0.0f,-3.0f),
	glm::vec3(3.0f,0.0f,-3.0f),
	glm::vec3(2.0f,0.0f,-3.0f),
	glm::vec3(1.0f,0.0f,-3.0f),
	// 4
	glm::vec3(4.0f,0.0f,-2.0f),
	glm::vec3(3.0f,0.0f,-2.0f),
	glm::vec3(2.0f,0.0f,-2.0f),
	glm::vec3(1.0f,0.0f,-2.0f),
	// 5
	glm::vec3(4.0f,0.0f,-1.0f),
	glm::vec3(3.0f,0.0f,-1.0f),
	glm::vec3(2.0f,0.0f,-1.0f),
	glm::vec3(1.0f,0.0f,-1.0f),
	// 6
	glm::vec3(4.0f,0.0f,0.0f),
	glm::vec3(3.0f,0.0f,0.0f),
	glm::vec3(2.0f,0.0f,0.0f),
	glm::vec3(1.0f,0.0f,0.0f),
	// 7
	glm::vec3(4.0f,0.0f,5.0f),
	glm::vec3(3.0f,0.0f,5.0f),
	glm::vec3(2.0f,0.0f,5.0f),
	glm::vec3(1.0f,0.0f,5.0f),
	// 8
	glm::vec3(4.0f,0.0f,4.0f),
	glm::vec3(3.0f,0.0f,4.0f),
	glm::vec3(2.0f,0.0f,4.0f),
	glm::vec3(1.0f,0.0f,4.0f),
	// 9
	glm::vec3(4.0f,0.0f,3.0f),
	glm::vec3(3.0f,0.0f,3.0f),
	glm::vec3(2.0f,0.0f,3.0f),
	glm::vec3(1.0f,0.0f,3.0f),
	// 10
	glm::vec3(4.0f, 0.0f, 2.0f),
	glm::vec3(3.0f, 0.0f, 2.0f),
	glm::vec3(2.0f, 0.0f, 2.0f),
	glm::vec3(1.0f, 0.0f, 2.0f),
	// 11
	glm::vec3(4.0f, 0.0f, 1.0f),
	glm::vec3(3.0f, 0.0f, 1.0f),
	glm::vec3(2.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 1.0f)
};

glm::vec3 cubeBrickPerpendicularPositions[] =
{
	//stanga
	// 1
	glm::vec3(-5.0f,0.0f,-7.0f),
	glm::vec3(-4.0f,0.0f,-7.0f),
	glm::vec3(-3.0f,0.0f,-7.0f),
	glm::vec3(-2.0f,0.0f,-7.0f),
	//2
	glm::vec3(-5.0f,0.0f,-6.0f),
	glm::vec3(-4.0f,0.0f,-6.0f),
	glm::vec3(-3.0f,0.0f,-6.0f),
	glm::vec3(-2.0f,0.0f,-6.0f),
	//dreapta
	// 1
	glm::vec3(4.0f,0.0f,-7.0f),
	glm::vec3(3.0f,0.0f,-7.0f),
	glm::vec3(2.0f,0.0f,-7.0f),
	glm::vec3(1.0f,0.0f,-7.0f),
	// 2
	glm::vec3(4.0f,0.0f,-6.0f),
	glm::vec3(3.0f,0.0f,-6.0f),
	glm::vec3(2.0f,0.0f,-6.0f),
	glm::vec3(1.0f,0.0f,-6.0f)
};


glm::vec3 cubeBrickPositions[] = {

	glm::vec3(-1.0f,0.0f,-6.0f),
	glm::vec3(0.0f,0.0f,-6.0f),
	glm::vec3(-1.0f,0.0f,-7.0f),
	glm::vec3(0.0f,0.0f,-7.0f),


	glm::vec3(-1.0f,0.0f,-5.0f),
	glm::vec3(0.0f,0.0f,-5.0f),
	glm::vec3(-1.0f,0.0f,-4.0f),
	glm::vec3(0.0f,0.0f,-4.0f),
	glm::vec3(-1.0f,0.0f,-3.0f),
	glm::vec3(0.0f,0.0f,-3.0f),
	glm::vec3(-1.0f,0.0f,-2.0f),
	glm::vec3(0.0f,0.0f,-2.0f),
	glm::vec3(-1.0f,0.0f,-1.0f),
	glm::vec3(0.0f,0.0f,-1.0f),
	glm::vec3(-1.0f,0.0f,0.0f),
	glm::vec3(0.0f,0.0f,0.0f),
	glm::vec3(-1.0f,0.0f,5.0f),
	glm::vec3(0.0f,0.0f,5.0f),
	glm::vec3(-1.0f,0.0f,4.0f),
	glm::vec3(0.0f,0.0f,4.0f),
	glm::vec3(-1.0f,0.0f,3.0f),
	glm::vec3(0.0f,0.0f,3.0f),
	glm::vec3(-1.0f,0.0f,2.0f),
	glm::vec3(0.0f,0.0f,2.0f),
	glm::vec3(-1.0f,0.0f,1.0f),
	glm::vec3(0.0f,0.0f,1.0f)
};

glm::vec3 barsDoorPositions[] = {
	glm::vec3(0.5f,0.5f,1.0f),
	glm::vec3(-1.5f,0.5f,-2.0f)
};

glm::vec3 barsPositions[] = {

glm::vec3(0.5f,0.5f,-5.0f),
glm::vec3(0.5f,0.5f,-4.0f),
glm::vec3(0.5f,0.5f,-3.0f),
glm::vec3(0.5f,0.5f,-2.0f),
glm::vec3(0.5f,0.5f,-1.0f),
glm::vec3(0.5f,0.5f,0.0f),
glm::vec3(0.5f,0.5f,2.0f),
glm::vec3(0.5f,0.5f,3.0f),
glm::vec3(0.5f,0.5f,4.0f),
glm::vec3(0.5f,0.5f,5.0f),


glm::vec3(-1.5f,0.5f,-5.0f),
glm::vec3(-1.5f,0.5f,-4.0f),
glm::vec3(-1.5f,0.5f,-3.0f),
glm::vec3(-1.5f,0.5f,-1.0f),
glm::vec3(-1.5f,0.5f,0.0f),
glm::vec3(-1.5f,0.5f,1.0f),
glm::vec3(-1.5f,0.5f,2.0f),
glm::vec3(-1.5f,0.5f,3.0f),
glm::vec3(-1.5f,0.5f,4.0f),
glm::vec3(-1.5f,0.5f,5.0f)
};


glm::vec3 barsPerpendicularPositions[] = {

		glm::vec3(-5.0f,0.5f,-5.5f),
		glm::vec3(-4.0f,0.5f,-5.5f),
		glm::vec3(-3.0f,0.5f,-5.5f),
		glm::vec3(-2.0f,0.5f,-5.5f),
		glm::vec3(-5.0f,0.5f,-7.5f),
		glm::vec3(-4.0f,0.5f,-7.5f),
		glm::vec3(-3.0f,0.5f,-7.5f),
		glm::vec3(-2.0f,0.5f,-7.5f),

		glm::vec3(4.0f,0.5f,-5.5f),
		glm::vec3(3.0f,0.5f,-5.5f),
		glm::vec3(2.0f,0.5f,-5.5f),
		glm::vec3(1.0f,0.5f,-5.5f),
		glm::vec3(4.0f,0.5f,-7.5f),
		glm::vec3(3.0f,0.5f,-7.5f),
		glm::vec3(2.0f,0.5f,-7.5f),
		glm::vec3(1.0f,0.5f,-7.5f)
};

void Game::InitializeGLFW()
{
	//Init glfw
	if (glfwInit() == GLFW_FALSE)
	{
		std::cout << "ERROR::GLFW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}
}

void Game::InitializeWindow(const char* title, bool resizable)
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	window = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);

	if (window == nullptr)
	{
		std::cout << "ERROR::WINDOW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}

	glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
	glfwSetFramebufferSizeCallback(window, frameBufferResizeCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(window);
}

void Game::InitializeGLEW()
{
	//Init glew
	glewExperimental = GL_TRUE;

	//Error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::GLEW_INIT_FAILED" << std::endl;
		glfwTerminate();
	}
}

void Game::InitializeOpenGLOptions()
{
	//OpenGL options
	glEnable(GL_DEPTH_TEST);

	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);*/
	glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Game::InitializeMatrices()
{
	ViewMatrix = camera->GetViewMatrix();
	ProjectionMatrix = camera->GetProjectionMatrix();
}

void Game::InitializeShaders()
{
	shaders.push_back(new Shader("vertexCore.glsl", "fragmentCore.glsl"));
	shaders.push_back(new Shader("skybox.vs", "skybox.fs"));
	shaders.push_back(new Shader("depthMap.vs", "depthMap.fs"));
}

void Game::InitializeTextures()
{
	//Texture 0
	textures.push_back(new Texture(std::vector<std::string>{"Textures\\skybox\\right.jpg", "Textures\\skybox\\left.jpg", "Textures\\skybox\\top.jpg",
		"Textures\\skybox\\bottom.jpg", "Textures\\skybox\\front.jpg", "Textures\\skybox\\back.jpg"}, GL_TEXTURE_CUBE_MAP));

	//Texture 1
	textures.push_back(new Texture("Textures\\grass.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 2
	textures.push_back(new Texture("Textures\\Bricks.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 3
	textures.push_back(new Texture("Textures\\bars.png", GL_TEXTURE_2D, GL_RGBA));

	//Texture 4
	textures.push_back(new Texture("Textures\\BarsWtihDoor.png", GL_TEXTURE_2D, GL_RGBA));

	//Texture 5
	textures.push_back(new Texture("Models\\Bird\\12213_bird_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 6
	textures.push_back(new Texture("Models\\Tree2\\10445_Oak_Tree_v1_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 7
	textures.push_back(new Texture("Models\\Bench\\Bench_2K_Diffuse.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 8
	textures.push_back(new Texture("Models\\45_cottage_free_other\\Cottage_Clean_Base_Color.png", GL_TEXTURE_2D, GL_RGB));

	//Texture 8
	textures.push_back(new Texture("Textures\\grass3d.png", GL_TEXTURE_2D, GL_RGBA));
}

void Game::InitializeMaterials()
{
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 1, 1));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 2, 2));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 3, 3));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 4, 4));
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 5, 5));
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 6, 6));
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 7, 7));
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 8, 8));
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 9, 9));
}

void Game::InitializeSkybox()
{
	skybox = new SkyBox(textures[texSkybox]);
}

void Game::InitializeShadows()
{
	shadow = new Shadow();
}

void Game::InitializeModels()
{
	std::vector<Mesh*> meshes;
	QuadDown squareDown;
	Quad square;
	Model* tempModel;
	int numOfTiles = 4;

	for (unsigned int i = 0; i < sizeof(cubeGrassPositions) / sizeof(cubeGrassPositions[0]); i++)
	{
		meshes.push_back(new Mesh(&squareDown, cubeGrassPositions[i], glm::vec3(0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material0], textures[texGrass0], textures[texGrass0], meshes, texGrass0));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}


	for (unsigned int i = 0; i < sizeof(cubeBrickPositions) / sizeof(cubeBrickPositions[0]); i++) {
		meshes.push_back(new Mesh(&squareDown, cubeBrickPositions[i], glm::vec3(0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material1], textures[texBricks0], textures[texBricks0], meshes, texBricks0));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}


	for (unsigned int i = 0; i < sizeof(barsDoorPositions) / sizeof(barsDoorPositions[0]); i++) {
		meshes.push_back(new Mesh(&square, barsDoorPositions[i], glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material3], textures[texBars2], textures[texBars2], meshes, texBars2));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}


	for (unsigned int i = 0; i < sizeof(cubeBrickPerpendicularPositions) / sizeof(cubeBrickPerpendicularPositions[0]); i++) {
		meshes.push_back(new Mesh(&squareDown, cubeBrickPerpendicularPositions[i], glm::vec3(0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material1], textures[texBricks0], textures[texBricks0], meshes, texBricks0));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}

	for (unsigned int i = 0; i < sizeof(barsPositions) / sizeof(barsPositions[0]); i++) {
		meshes.push_back(new Mesh(&square, barsPositions[i], glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material2], textures[texBars1], textures[texBars1], meshes, texBars1));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}



	for (unsigned int i = 0; i < sizeof(barsPerpendicularPositions) / sizeof(barsPerpendicularPositions[0]); i++) {
		meshes.push_back(new Mesh(&square, barsPerpendicularPositions[i], glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material2], textures[texBars1], textures[texBars1], meshes, texBars1));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(12, 35);

	for (unsigned int i = 0; i < sizeof(cubeGrassPositions) / sizeof(cubeGrassPositions[0]); i++)
	{
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i], glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i], glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));

		double position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, position), glm::vec3(1.f), glm::vec3(0.5f)));
		/*meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, -position), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, -position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-position, 0.f, -position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -position), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, position), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, position), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, -position), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, -position), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(-0.35f, 0.f, -position), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -0.40f), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -0.40f), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, -0.40f), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));

		position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, 0.40f), glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, 0.40f), glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, cubeGrassPositions[i] + glm::vec3(+position, 0.f, 0.40f), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.5f)));*/
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material8], textures[texGrass1], textures[texGrass1], meshes, texGrass1));
	models.back()->Move(glm::vec3(0.f, 0.12f, 0.f));
	models.back()->Scale(glm::vec3(1.f, 0.5f, 1.f));

	for (auto*& i : meshes)
		delete i;
	meshes.clear();
	for (int i = 0; i < numOfTiles; i++)
	{
		tempModel = new Model(*models.back());
		tempModel->Move(glm::vec3(0.f, 0.f, -13.f));
		models.push_back(tempModel);
	}

	models.push_back(new Model("Models\\Bird\\12213_Bird_v1_l3.obj", materials[material4], textures[texBird], textures[texBird], texBird));
	models.back()->Move(glm::vec3(0.f, 3.f, 0.f));
	models.back()->SetScale(glm::vec3(0.01f));
	models.back()->SetRotation(glm::vec3(-90.f, 0.f, 0.f));

	models.push_back(new Model("Models\\Tree2\\10445_Oak_Tree_v1_max2010_iteration-1.obj", materials[material5], textures[texTree1], textures[texTree1], texTree1));
	models.back()->SetPosition(glm::vec3(1.0f, 0.0f, -5.0f));
	models.back()->SetScale(glm::vec3(0.005f));
	models.back()->SetRotation(glm::vec3(-90.f, 0.f, 0.f));
	models.back()->Move(glm::vec3(-1.4f, 0.f, 0.f));

	models.push_back(new Model("Models\\Bench\\Cgtuts_Wood_Bench_OBJ.obj", materials[material6], textures[texBench], textures[texBench], texBench));
	models.back()->SetScale(glm::vec3(0.002f));
	models.back()->SetRotation(glm::vec3(0.f, -90, 0.f));


	models.push_back(new Model("Models\\45_cottage_free_other\\Cottage_FREE.obj", materials[material7], textures[texBarrack], textures[texBarrack], texBarrack));
	models.back()->SetScale(glm::vec3(0.6f));
	models.back()->Move(glm::vec3(-0.58f, 0.f, 9.f));

}

void Game::InitializeLights()
{
	//Lights
	lights.push_back(new glm::vec3(-0.5f, 10.f, -26.f));
}

void Game::InitializeUniforms()
{
	//Init uniforms
	shaders[shaderCoreProgram]->Use();
	shaders[shaderCoreProgram]->SetMat4fv(ViewMatrix, "ViewMatrix");
	shaders[shaderCoreProgram]->SetMat4fv(ProjectionMatrix, "ProjectionMatrix");
	shaders[shaderCoreProgram]->SetVec3F(*lights[0], "lightPos0");
	shaders[shaderCoreProgram]->SetVec3F(camPosition, "cameraPos");
	//shaders[shaderCoreProgram]->Set1i(0, "material.diffuseTex");
	shaders[shaderCoreProgram]->Set1i(textures.size(), "shadowMap");

	shaders[shaderSkybox]->Use();
	shaders[shaderSkybox]->SetMat4fv(ViewMatrix, "view");
	shaders[shaderSkybox]->SetMat4fv(ProjectionMatrix, "projection");
	shaders[shaderSkybox]->Set1i(texSkybox, "skybox");
	shaders[shaderSkybox]->SetMat4fv(glm::mat4(1.f), "model");
}

void Game::UpdateUniforms()
{
	glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);

	float near_plane = 1.0f, far_plane = 7.5f;
	glm::mat4 lightProjection = glm::ortho(-6.0f, 4.0f, -60.0f, 5.0f, near_plane, far_plane);
	glm::mat4 lightView = glm::lookAt(*lights[0],
		glm::vec3(-0.5f,0.f,-10.f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 lightSpaceMatrix = glm::mat4(1.f);
	lightSpaceMatrix = lightProjection * lightView * lightSpaceMatrix;
	shaders[shaderCoreProgram]->Use();

	ProjectionMatrix = camera->GetProjectionMatrix();
	shaders[shaderCoreProgram]->SetMat4fv(ProjectionMatrix, "ProjectionMatrix");

	ViewMatrix = camera->GetViewMatrix();
	shaders[shaderCoreProgram]->SetMat4fv(ViewMatrix, "ViewMatrix");
	shaders[shaderCoreProgram]->SetMat4fv(lightSpaceMatrix, "lightSpaceMatrix");
	shaders[shaderCoreProgram]->SetVec3F(camera->GetPosition(), "cameraPos");

	shaders[shaderShadow]->Use();
	shaders[shaderShadow]->SetMat4fv(lightSpaceMatrix, "lightSpaceMatrix");
}

Game::Game(const char* title, const int width, const int height, bool resizable) :windowWidth(width), windowHeight(height)
{
	window = nullptr;
	framebufferWidth = 0;
	framebufferHeight = 0;
	camPosition = glm::vec3(1.58f, 0.9f, 6.5f);
	camera = new Camera(windowWidth, windowHeight, camPosition);

	InitializeGLFW();
	InitializeWindow(title, resizable);
	InitializeGLEW();
	InitializeOpenGLOptions();
	InitializeMatrices();
	InitializeShaders();
	InitializeShadows();
	InitializeTextures();
	InitializeSkybox();
	InitializeMaterials();
	InitializeModels();
	InitializeLights();
	InitializeUniforms();
}

Game::~Game()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	for (auto*& i : shaders)
		delete i;
	for (auto*& i : textures)
		delete i;
	for (auto*& i : materials)
		delete i;
	for (auto*& i : meshes)
		delete i;
	for (auto*& i : models)
		delete i;
	for (auto*& i : lights)
		delete i;
	delete camera;
	delete skybox;
	delete shadow;
}

int Game::GetWindowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Game::SetWindowShouldClose()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Game::Update()
{
	//Update input
	glfwPollEvents();
	UpdateInput(window);
}

void Game::Render()
{
	double currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	//Clear
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	UpdateUniforms();

	shadow->PrepareRender();
	RenderModels(shaders[shaderShadow]);

	glCullFace(GL_BACK);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_CULL_FACE);

	glViewport(0, 0, windowWidth, windowHeight);
	glClearColor(0.f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	skybox->Render(shaders[shaderSkybox], camera);

	RenderModels(shaders[shaderCoreProgram]);

	glfwSwapBuffers(window);
	glFlush();

	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Game::RenderModels(Shader* shader)
{
	shader->Use();
	for (auto& i : models)
	{
		i->Render(shaders[shaderCoreProgram]);
	}

	models[tree]->SetPosition(glm::vec3(2.5f, 0.f, 3.5f));
	models[tree]->Render(shaders[shaderCoreProgram]);

	models[tree]->SetPosition(glm::vec3(-3.5f, 0.f, 3.5f));
	models[tree]->Render(shaders[shaderCoreProgram]);


	models[bench]->SetRotation(glm::vec3(0.f, 90, 0.f));
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, 3.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -3.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -9.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -16.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -23.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -30.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -35.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -42.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -48.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(-1.2f, 0.f, -56.f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetRotation(glm::vec3(0.f, -90, 0.f));
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, 3.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -3.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -9.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -16.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -23.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -30.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -35.5f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -42.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -48.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	models[bench]->SetPosition(glm::vec3(0.2f, 0.f, -56.f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	/////
	models[bench]->SetRotation(glm::vec3(0.f, 0.f, 0.f));
	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -7.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -7.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -20.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -20.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -33.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -33.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -46.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -46.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -59.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -59.2f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetRotation(glm::vec3(0.f, 180.f, 0.f));
	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -5.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -5.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -18.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -18.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -31.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -31.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -44.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -44.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(2.5f, 0.f, -57.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);

	models[bench]->SetPosition(glm::vec3(-3.5f, 0.f, -57.8f));
	models[bench]->Render(shaders[shaderCoreProgram]);
	/////
	models[bird]->SetPosition(glm::vec3(-3.5f, 0.41f, 3.70f));
	models[bird]->Render(shaders[shaderCoreProgram]);

	models[bird]->SetPosition(glm::vec3(0.2f, 0.21f, 3.72f));
	models[bird]->SetRotation(glm::vec3(-90.f, 0.f, 120.f));
	models[bird]->Render(shaders[shaderCoreProgram]);

	models[bird]->SetPosition(glm::vec3(0.3f, 0.21f, 3.72f));
	models[bird]->SetRotation(glm::vec3(-90.f, 0.f, 70.f));
	models[bird]->Render(shaders[shaderCoreProgram]);
}

void Game::frameBufferResizeCallback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
	camera->Reshape(fbW, fbH);
}

void Game::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	camera->MouseControl((float)xpos, (float)ypos);
}

void Game::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera->ProcessMouseScroll((float)yoffset);
}

void Game::UpdateInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->ProcessKeyboard(FORWARD, (float)deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->ProcessKeyboard(BACKWARD, (float)deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->ProcessKeyboard(LEFT, (float)deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->ProcessKeyboard(RIGHT, (float)deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera->ProcessKeyboard(UP, (float)deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera->ProcessKeyboard(DOWN, (float)deltaTime);

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		camera->Reset(width, height);

	}
}
