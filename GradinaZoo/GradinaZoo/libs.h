#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<vector>

#include<GL\glew.h>
#include<glfw3.h>


#include<GLM.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
#include"Mesh.h"
#include"Camera.h"
#include "Model.h"
#include "SkyBox.h"
#include "Shadow.h"
#include "SpacePositions.h"

#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "assimp-vc142-mtd.lib")