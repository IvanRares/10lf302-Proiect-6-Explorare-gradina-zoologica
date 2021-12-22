#pragma once

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Material.h"
class Model
{
private:
	Material* material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	std::vector<Mesh*> meshes;
	glm::vec3 position;

	void UpdateUniforms();
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh* ProcessMesh(aiMesh* mesh, const aiScene* scene);
public:
	Model(const char* path,Material* material, Texture* ovTexDif, Texture* ovTexSpec);
	Model(glm::vec3 position,Material* material,Texture* ovTexDif,Texture* ovTexSpec,std::vector<Mesh*> meshes);
	~Model();

	void Update();
	void Render(Shader* shader);
};

