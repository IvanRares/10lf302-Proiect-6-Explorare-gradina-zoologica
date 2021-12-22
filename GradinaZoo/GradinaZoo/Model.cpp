#include "Model.h"

void Model::UpdateUniforms()
{
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(ProcessMesh(mesh, scene));
	}
	for (int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

Mesh* Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;
	Vertex tempVertex;
	glm::vec3 tempVec3;
	glm::vec2 tempVec2;
	aiFace face;
	aiMaterial* material;
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		tempVec3.x = mesh->mVertices[i].x;
		tempVec3.y = mesh->mVertices[i].y;
		tempVec3.z = mesh->mVertices[i].z;
		tempVertex.position = tempVec3;

		tempVec3.x = mesh->mNormals[i].x;
		tempVec3.y = mesh->mNormals[i].y;
		tempVec3.z = mesh->mNormals[i].z;
		tempVertex.normal = tempVec3;

		if (mesh->mTextureCoords[0])
		{
			tempVec2.x = mesh->mTextureCoords[0][i].x;
			tempVec2.y = mesh->mTextureCoords[0][i].y;
			tempVertex.texcoord = tempVec2;
		}
		else tempVertex.texcoord = glm::vec2(0.f, 0.f);
		vertices.push_back(tempVertex);
	}

	for (int i = 0; i < mesh->mNumFaces; i++)
	{
		face = mesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	/*if (mesh->mMaterialIndex >= 0)
	{
		material = scene->mMaterials[mesh->mMaterialIndex];
		vector<Texture> diffuse
	}*/
	return new Mesh(vertices.data(),vertices.size(),indices.data(),indices.size());
}

Model::Model(const char* path, Material* material, Texture* ovTexDif, Texture* ovTexSpec)
{
	this->material = material;
	this->overrideTextureDiffuse = ovTexDif;
	this->overrideTextureSpecular = ovTexSpec;
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cerr << "ERROR::MODEL::ASSIMP" << import.GetErrorString() << std::endl;
		return;
	}
	//directory
	ProcessNode(scene->mRootNode, scene);
}

Model::Model(glm::vec3 position, Material* material, Texture* ovTexDif, Texture* ovTexSpec, std::vector<Mesh*> meshes)
{
	this->position = position;
	this->material = material;
	overrideTextureDiffuse = ovTexDif;
	overrideTextureSpecular = ovTexSpec;
	for (auto* i : meshes)
	{
		this->meshes.push_back(new Mesh(*i));
	}

	for (auto& i : this->meshes)
	{
		i->Move(this->position);
		i->SetOrigin(this->position);
	}
}

Model::~Model()
{
	for (auto*& i : meshes)
	{
		delete i;
	}
}

void Model::Update()
{
}

void Model::Render(Shader* shader)
{
	UpdateUniforms();

	material->SendToShader(*shader);

	//Use a program
	shader->Use();

	for (auto& i : meshes)
	{
		//Activate texture
		overrideTextureDiffuse->Bind(0);
		overrideTextureSpecular->Bind(1);

		i->Render(shader);
	}
}
