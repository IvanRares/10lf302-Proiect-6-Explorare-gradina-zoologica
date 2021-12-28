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
	std::vector<Mesh*> meshes;
	unsigned int textureId;

	void UpdateUniforms();
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh* ProcessMesh(aiMesh* mesh, const aiScene* scene);
public:
	Model(const char* path,Material* material, Texture* ovTexDif, unsigned int textureId);
	Model(Material* material,Texture* ovTexDif,std::vector<Mesh*> meshes, unsigned int textureId);
	~Model();

	void Update();
	void Render(Shader* shader);

	void SetPosition(const glm::vec3& position);

	void SetRotation(const glm::vec3& rotation);

	void SetScale(const glm::vec3& scale);

	void Move(const glm::vec3& position);

	void Rotate(const glm::vec3& rotation);

	void Scale(const glm::vec3& scale);

	void SetMaterialAndTextures(Material* material, Texture* ovTexDif, unsigned int textureId);

	Model(const Model &model);
};

