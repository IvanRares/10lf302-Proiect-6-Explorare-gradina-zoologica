#include "Game.h"
//Camera Game::camera = nullptr;
double Game::deltaTime = 0.0f;
double Game::lastFrame = 0.0f;
Camera* Game::camera = nullptr;

glm::vec3 cubeGrassPositions[] = {
		glm::vec3(-5.0f,0.0f,-5.0f),
		glm::vec3(-4.0f,0.0f,-5.0f),
		glm::vec3(-3.0f,0.0f,-5.0f),
		glm::vec3(-2.0f,0.0f,-5.0f),
		glm::vec3(4.0f,0.0f,-5.0f),
		glm::vec3(3.0f,0.0f,-5.0f),
		glm::vec3(2.0f,0.0f,-5.0f),
		glm::vec3(1.0f,0.0f,-5.0f),

		glm::vec3(-5.0f,0.0f,-4.0f),
		glm::vec3(-4.0f,0.0f,-4.0f),
		glm::vec3(-3.0f,0.0f,-4.0f),
		glm::vec3(-2.0f,0.0f,-4.0f),
		glm::vec3(4.0f,0.0f,-4.0f),
		glm::vec3(3.0f,0.0f,-4.0f),
		glm::vec3(2.0f,0.0f,-4.0f),
		glm::vec3(1.0f,0.0f,-4.0f),

		glm::vec3(-5.0f,0.0f,-3.0f),
		glm::vec3(-4.0f,0.0f,-3.0f),
		glm::vec3(-3.0f,0.0f,-3.0f),
		glm::vec3(-2.0f,0.0f,-3.0f),
		glm::vec3(4.0f,0.0f,-3.0f),
		glm::vec3(3.0f,0.0f,-3.0f),
		glm::vec3(2.0f,0.0f,-3.0f),
		glm::vec3(1.0f,0.0f,-3.0f),

		glm::vec3(-5.0f,0.0f,-2.0f),
		glm::vec3(-4.0f,0.0f,-2.0f),
		glm::vec3(-3.0f,0.0f,-2.0f),
		glm::vec3(-2.0f,0.0f,-2.0f),
		glm::vec3(4.0f,0.0f,-2.0f),
		glm::vec3(3.0f,0.0f,-2.0f),
		glm::vec3(2.0f,0.0f,-2.0f),
		glm::vec3(1.0f,0.0f,-2.0f),

		glm::vec3(-5.0f,0.0f,-1.0f),
		glm::vec3(-4.0f,0.0f,-1.0f),
		glm::vec3(-3.0f,0.0f,-1.0f),
		glm::vec3(-2.0f,0.0f,-1.0f),
		glm::vec3(4.0f,0.0f,-1.0f),
		glm::vec3(3.0f,0.0f,-1.0f),
		glm::vec3(2.0f,0.0f,-1.0f),
		glm::vec3(1.0f,0.0f,-1.0f),

		glm::vec3(-5.0f,0.0f,0.0f),
		glm::vec3(-4.0f,0.0f,0.0f),
		glm::vec3(-3.0f,0.0f,0.0f),
		glm::vec3(-2.0f,0.0f,0.0f),
		glm::vec3(4.0f,0.0f,0.0f),
		glm::vec3(3.0f,0.0f,0.0f),
		glm::vec3(2.0f,0.0f,0.0f),
		glm::vec3(1.0f,0.0f,0.0f),

		glm::vec3(-5.0f,0.0f,5.0f),
		glm::vec3(-4.0f,0.0f,5.0f),
		glm::vec3(-3.0f,0.0f,5.0f),
		glm::vec3(-2.0f,0.0f,5.0f),
		glm::vec3(4.0f,0.0f,5.0f),
		glm::vec3(3.0f,0.0f,5.0f),
		glm::vec3(2.0f,0.0f,5.0f),
		glm::vec3(1.0f,0.0f,5.0f),

		glm::vec3(-5.0f,0.0f,4.0f),
		glm::vec3(-4.0f,0.0f,4.0f),
		glm::vec3(-3.0f,0.0f,4.0f),
		glm::vec3(-2.0f,0.0f,4.0f),
		glm::vec3(4.0f,0.0f,4.0f),
		glm::vec3(3.0f,0.0f,4.0f),
		glm::vec3(2.0f,0.0f,4.0f),
		glm::vec3(1.0f,0.0f,4.0f),

		glm::vec3(-5.0f,0.0f,3.0f),
		glm::vec3(-4.0f,0.0f,3.0f),
		glm::vec3(-3.0f,0.0f,3.0f),
		glm::vec3(-2.0f,0.0f,3.0f),
		glm::vec3(4.0f,0.0f,3.0f),
		glm::vec3(3.0f,0.0f,3.0f),
		glm::vec3(2.0f,0.0f,3.0f),
		glm::vec3(1.0f,0.0f,3.0f),

		glm::vec3(-5.0f,0.0f,2.0f),
		glm::vec3(-4.0f,0.0f,2.0f),
		glm::vec3(-3.0f,0.0f,2.0f),
		glm::vec3(-2.0f,0.0f,2.0f),
		glm::vec3(4.0f,0.0f,2.0f),
		glm::vec3(3.0f,0.0f,2.0f),
		glm::vec3(2.0f,0.0f,2.0f),
		glm::vec3(1.0f,0.0f,2.0f),

		glm::vec3(-5.0f,0.0f,1.0f),
		glm::vec3(-4.0f,0.0f,1.0f),
		glm::vec3(-3.0f,0.0f,1.0f),
		glm::vec3(-2.0f,0.0f,1.0f),
		glm::vec3(4.0f,0.0f,1.0f),
		glm::vec3(3.0f,0.0f,1.0f),
		glm::vec3(2.0f,0.0f,1.0f),
		glm::vec3(1.0f, 0.0f, 1.0f),
};

glm::vec3 cubeBrickPositions[] = {
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
	   glm::vec3(0.0f,0.0f,1.0f),

};

glm::vec3 barsDoorPositions[] = {
	glm::vec3(0.5f,0.5f,1.0f),
	glm::vec3(-1.5f,0.5f,-2.0f),
	// x y z

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
glm::vec3(-1.5f,0.5f,5.0f),

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
}

void Game::InitializeTextures()
{
	//Texture 0
	textures.push_back(new Texture("Textures\\grass.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 1
	textures.push_back(new Texture("Textures\\Bricks.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 2
	textures.push_back(new Texture("Textures\\bars.png", GL_TEXTURE_2D, GL_RGBA));

	//Texture 3
	textures.push_back(new Texture("Textures\\BarsWtihDoor.png", GL_TEXTURE_2D, GL_RGBA));

	//Texture 4
	textures.push_back(new Texture("Models\\Bird\\12213_bird_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));

	//Texture 5
	textures.push_back(new Texture("Models\\Tree2\\10445_Oak_Tree_v1_diffuse.jpg", GL_TEXTURE_2D, GL_RGB));

}

void Game::InitializeMaterials()
{
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 0, 0));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 1, 1));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 2, 2));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 3, 3));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 4, 4));
	materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(2.f), 5, 5));
}

void Game::InitializeObjectModels()
{
	//std::vector<Vertex> mesh = loadObj("Models\\Bird\\12213_Bird_v1_l3.obj");
}

void Game::InitializeModels()
{


	std::vector<Mesh*> meshes;
	
	models.push_back(new Model("Models\\Tree2\\10445_Oak_Tree_v1_max2010_iteration-1.obj", materials[material5], textures[texTree1], textures[texTree1], texTree1));
	models.back()->SetPosition(glm::vec3(1.0f, 0.0f, -5.0f));
	models.back()->SetScale(glm::vec3(0.005f));
	models.back()->SetRotation(glm::vec3(-90.f, 0.f, 0.f));
	models.back()->Move(glm::vec3(-1.4f, 0.f, 0.f));

	
	QuadDown squareDown;
	Quad square;
	for (unsigned int i = 0; i < sizeof(cubeGrassPositions) / sizeof(cubeGrassPositions[0]); i++) 
	{
		meshes.push_back(new Mesh(&squareDown, cubeGrassPositions[i], glm::vec3(0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material0], textures[texGrass0], textures[texGrass0], meshes,texGrass0));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();

	for (unsigned int i = 0; i < sizeof(cubeBrickPositions) / sizeof(cubeBrickPositions[0]); i++) {
		meshes.push_back(new Mesh(&squareDown, cubeBrickPositions[i], glm::vec3(0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material1], textures[texBricks0], textures[texBricks0], meshes, texBricks0));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();

	for (unsigned int i = 0; i < 2; i++) {
		meshes.push_back(new Mesh(&square, barsDoorPositions[i], glm::vec3(0.f,90.f,0.f), glm::vec3(1.f)));
	}
	models.push_back(new Model(glm::vec3(0.f), materials[material3], textures[texBars2], textures[texBars2], meshes, texBars2));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();

	for (unsigned int i = 2; i < sizeof(barsDoorPositions) / sizeof(barsDoorPositions[0]); i++) {
		meshes.push_back(new Mesh(&square, barsDoorPositions[i], glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f)));
		}
	models.push_back(new Model(glm::vec3(0.f), materials[material2], textures[texBars1], textures[texBars1], meshes, texBars1));
	for (auto*& i : meshes)
		delete i;
	meshes.clear();




	models.push_back(new Model("Models\\Bird\\12213_Bird_v1_l3.obj", materials[material4], textures[texBird], textures[texBird],texBird));
	models.back()->Move(glm::vec3(0.f,3.f,0.f));
	models.back()->SetScale(glm::vec3(0.01f));
	models.back()->SetRotation(glm::vec3(-90.f,0.f,0.f));


	

}

void Game::InitializeLights()
{
	//Lights
	lights.push_back(new glm::vec3(0.f, 5.f, 0.f));
}

void Game::InitializeUniforms()
{
	//Init uniforms
	shaders[shaderCoreProgram]->SetMat4fv(ViewMatrix, "ViewMatrix");
	shaders[shaderCoreProgram]->SetMat4fv(ProjectionMatrix, "ProjectionMatrix");

	shaders[shaderCoreProgram]->SetVec3F(*lights[0], "lightPos0");
	shaders[shaderCoreProgram]->SetVec3F(camPosition, "cameraPos");
}

void Game::UpdateUniforms(const int& materialID)
{
	//Update uniforms
	materials[materialID]->SendToShader(*shaders[shaderCoreProgram]);

	//Update framebuffer size and projection matrix
	glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);

	ProjectionMatrix = camera->GetProjectionMatrix();
	shaders[shaderCoreProgram]->SetMat4fv(ProjectionMatrix, "ProjectionMatrix");

	ViewMatrix = camera->GetViewMatrix();
	shaders[shaderCoreProgram]->SetMat4fv(ViewMatrix, "ViewMatrix");
}

Game::Game(const char* title, const int width, const int height, bool resizable) :windowWidth(width), windowHeight(height)
{
	window = nullptr;
	framebufferWidth = 0;
	framebufferHeight = 0;
	camPosition = glm::vec3(0.5f, 0.5f, 10.f);
	camera = new Camera(windowWidth, windowHeight, camPosition);

	InitializeGLFW();
	InitializeWindow(title, resizable);
	InitializeGLEW();
	InitializeOpenGLOptions();
	InitializeMatrices();
	InitializeShaders();
	InitializeTextures();
	InitializeMaterials();
	InitializeObjectModels();
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	UpdateUniforms(material0);

	//Use a program
	shaders[shaderCoreProgram]->Use();


	for (auto& i : models)
	{
		i->Render(shaders[shaderCoreProgram]);
	}
	/*models.back()->Move(glm::vec3(glm::sin(currentFrame)*0.1f,0.f, glm::cos(currentFrame) * 0.1f));
	models.back()->Rotate(glm::vec3(0.f, 0.f, 1.f));*/
	glfwSwapBuffers(window);
	glFlush();

	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
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
