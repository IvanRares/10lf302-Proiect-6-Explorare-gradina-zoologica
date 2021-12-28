#include "Game.h"
#include <random>
double Game::deltaTime = 0.0f;
double Game::lastFrame = 0.0f;
Camera* Game::camera = nullptr;

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

	textures.push_back(new Texture("Models\\camel\\10007_Camel_v03.jpg", GL_TEXTURE_2D, GL_RGB));

	textures.push_back(new Texture("Models\\bear\\Tibetan_bear_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\deer\\12961_White_TailedDeer_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\Kangaroo\\Kangaroo_diff.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\lion\\12273_Lion_Diffuse.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\monkey\\12958_Spider_Monkey_diff.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\Penguin\\Penguin_Diffuse_Color.png", GL_TEXTURE_2D, GL_RGBA));
	textures.push_back(new Texture("Models\\Sea_lion\\10041_sealion_v1_Diffuse.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\Sea_turtle\\10042_Sea_Turtle_V1_Diffuse.jpg", GL_TEXTURE_2D, GL_RGB));
	textures.push_back(new Texture("Models\\tiger\\Tiger_yellow.png", GL_TEXTURE_2D, GL_RGB));
}

void Game::InitializeMaterials()
{
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 1, 1)); //grass
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 2, 2)); //bricks
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 3, 3)); //bars1
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 4, 4)); //bars2
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 5, 5)); //bird
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 6, 6)); //tree1
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 7, 7)); //bench
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 8, 8)); //barrack
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 9, 9)); //grass3d
	////materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 10, 10)); //
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 10, 10)); //camel
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 11, 11)); //bear
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 12, 12)); //deer
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 13, 13)); //kangaroo
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 14, 14)); //lion
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 15, 15)); //monkey
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 16, 16)); //penguin
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 17, 17)); //sea lion
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 18, 18)); //sea turtle
	materials.push_back(new Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(0.5f), 19, 19)); //tiger
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
	std::vector<SpacePositions> positions;

	positions = GetCubeGrassPositions();
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		meshes.push_back(new Mesh(&squareDown, positions[i].position, glm::vec3(0.f), glm::vec3(1.f)));
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

	positions = GetCubeBricksPositions();
	for (unsigned int i = 0; i < positions.size(); i++) {
		meshes.push_back(new Mesh(&squareDown, positions[i].position, glm::vec3(0.f), glm::vec3(1.f)));
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

	positions = GetBarsDoorPositions();
	for (unsigned int i = 0; i < positions.size(); i++) {
		meshes.push_back(new Mesh(&square, positions[i].position, glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f)));
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

	positions = GetCubeBricksPerpendicularPositions();
	for (unsigned int i = 0; i < positions.size(); i++) {
		meshes.push_back(new Mesh(&squareDown, positions[i].position, glm::vec3(0.f), glm::vec3(1.f)));
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

	positions = GetBarsPositions();
	for (unsigned int i = 0; i < positions.size(); i++) {
		meshes.push_back(new Mesh(&square, positions[i].position, glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f)));
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

	positions = GetBarsPerpendicularPositions();
	for (unsigned int i = 0; i < positions.size(); i++) {
		meshes.push_back(new Mesh(&square, positions[i].position, glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f)));
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

	positions = GetCubeGrassPositions();
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		meshes.push_back(new Mesh(&square, positions[i].position, glm::vec3(1.f), glm::vec3(0.5f)));
		meshes.push_back(new Mesh(&square, positions[i].position, glm::vec3(0.f, 90.f, 0.f), glm::vec3(0.5f)));

		double position = (float)distribution(generator) / 100;
		meshes.push_back(new Mesh(&square, positions[i].position + glm::vec3(-position, 0.f, position), glm::vec3(1.f), glm::vec3(0.5f)));
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

	models.push_back(new Model("Models\\Tree2\\10445_Oak_Tree_v1_max2010_iteration-1.obj", materials[material5], textures[texTree1], textures[texTree1], texTree1));

	models.push_back(new Model("Models\\Bench\\Cgtuts_Wood_Bench_OBJ.obj", materials[material6], textures[texBench], textures[texBench], texBench));

	models.push_back(new Model("Models\\45_cottage_free_other\\Cottage_FREE.obj", materials[material7], textures[texBarrack], textures[texBarrack], texBarrack));
	models.back()->SetScale(glm::vec3(0.6f));
	models.back()->Move(glm::vec3(-0.58f, 0.f, 9.f));

	models.push_back(new Model("Models\\camel\\Camel.obj", materials[material9], textures[texCamel], textures[texCamel], texCamel));
	
	models.push_back(new Model("Models\\bear\\13576_Tibetan_Bear_v1_l3.obj", materials[material10], textures[texBear], textures[texBear], texBear));

	models.push_back(new Model("Models\\deer\\12961_White_Tailed_Deer_v1_l2.obj", materials[material11], textures[texDeer], textures[texDeer], texDeer));
	models.push_back(new Model("Models\\kangaroo\\12271_Kangaroo_v1_L3.obj", materials[material12], textures[texKangaroo], textures[texKangaroo], texKangaroo));
	models.push_back(new Model("Models\\lion\\12273_Lion_v1_l3.obj", materials[material13], textures[texLion], textures[texLion], texLion));
	models.push_back(new Model("Models\\monkey\\12958_Spider_Monkey_v1_l2.obj", materials[material14], textures[texMonkey], textures[texMonkey], texMonkey));
	models.push_back(new Model("Models\\Penguin\\PenguinBaseMesh.obj", materials[material15], textures[texPenguin], textures[texPenguin], texPenguin));
	models.push_back(new Model("Models\\Sea_lion\\10041_sealion_v1_L3.obj", materials[material16], textures[texSeaLion], textures[texSeaLion], texSeaLion));
	models.push_back(new Model("Models\\Sea_turtle\\10042_Sea_Turtle_V2_iterations-2.obj", materials[material17], textures[texSeaTurtle], textures[texSeaTurtle], texSeaTurtle));
	models.push_back(new Model("Models\\tiger\\uploads_files_893187_Tiger.obj", materials[material18], textures[texTiger], textures[texTiger], texTiger));
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
		glm::vec3(-0.5f, 0.f, -10.f),
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
	for (int i = 0; i < bird; i++)
	{
		models[i]->Render(shader);
	}
	models[cottage]->Render(shader);
	
	std::vector<SpacePositions> positions;
	positions = GetTreePositions();
	
	for (auto& i : positions)
	{
		models[tree]->SetPosition(i.position);
		models[tree]->SetRotation(i.rotation);
		models[tree]->SetScale(i.scale);
		models[tree]->Render(shader);
	}

	positions = GetBenchPositions();

	for (auto& i : positions)
	{
		models[bench]->SetPosition(i.position);
		models[bench]->SetRotation(i.rotation);
		models[bench]->SetScale(i.scale);
		models[bench]->Render(shader);
	}

	positions = GetBirdPositions();

	for (auto& i : positions)
	{
		models[bird]->SetPosition(i.position);
		models[bird]->SetRotation(i.rotation);
		models[bird]->SetScale(i.scale);
		models[bird]->Render(shader);
	}

	positions = GetCamelPositions();

	for (auto& i : positions)
	{
		models[camel]->SetPosition(i.position);
		models[camel]->SetRotation(i.rotation);
		models[camel]->SetScale(i.scale);
		models[camel]->Render(shader);
	}

	positions = GetBearPositions();

	for (auto& i : positions)
	{
		models[bear]->SetPosition(i.position);
		models[bear]->SetRotation(i.rotation);
		models[bear]->SetScale(i.scale);
		models[bear]->Render(shader);
	}

	positions = GetDeerPositions();

	for (auto& i : positions)
	{
		models[deer]->SetPosition(i.position);
		models[deer]->SetRotation(i.rotation);
		models[deer]->SetScale(i.scale);
		models[deer]->Render(shader);
	}

	positions = GetKangarooPositions();

	for (auto& i : positions)
	{
		models[kangaroo]->SetPosition(i.position);
		models[kangaroo]->SetRotation(i.rotation);
		models[kangaroo]->SetScale(i.scale);
		models[kangaroo]->Render(shader);
	}

	positions = GetLionPositions();

	for (auto& i : positions)
	{
		models[lion]->SetPosition(i.position);
		models[lion]->SetRotation(i.rotation);
		models[lion]->SetScale(i.scale);
		models[lion]->Render(shader);
	}

	positions = GetMonkeyPositions();

	for (auto& i : positions)
	{
		models[monkey]->SetPosition(i.position);
		models[monkey]->SetRotation(i.rotation);
		models[monkey]->SetScale(i.scale);
		models[monkey]->Render(shader);
	}

	positions = GetPenguinPositions();

	for (auto& i : positions)
	{
		models[penguin]->SetPosition(i.position);
		models[penguin]->SetRotation(i.rotation);
		models[penguin]->SetScale(i.scale);
		models[penguin]->Render(shader);
	}
	positions = GetSeaLionPositions();

	for (auto& i : positions)
	{
		models[seaLion]->SetPosition(i.position);
		models[seaLion]->SetRotation(i.rotation);
		models[seaLion]->SetScale(i.scale);
		models[seaLion]->Render(shader);
	}
	positions = GetSeaTurtlePositions();

	for (auto& i : positions)
	{
		models[seaTurtle]->SetPosition(i.position);
		models[seaTurtle]->SetRotation(i.rotation);
		models[seaTurtle]->SetScale(i.scale);
		models[seaTurtle]->Render(shader);
	}
	positions = GetTigerPositions();

	for (auto& i : positions)
	{
		models[tiger]->SetPosition(i.position);
		models[tiger]->SetRotation(i.rotation);
		models[tiger]->SetScale(i.scale);
		models[tiger]->Render(shader);
	}
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
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		camera->SetFreeCamera();

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		camera->Reset(width, height);

	}
}
