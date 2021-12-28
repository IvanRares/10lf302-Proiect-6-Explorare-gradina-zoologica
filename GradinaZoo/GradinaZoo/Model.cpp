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
	Vertex tempVertex;
	glm::vec3 tempVec3;
	glm::vec2 tempVec2;
	aiFace face;
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		tempVec3.x = mesh->mVertices[i].x;
		tempVec3.y = mesh->mVertices[i].y;
		tempVec3.z = mesh->mVertices[i].z;
		tempVertex.position = tempVec3;

		if (mesh->mNormals)
		{
			tempVec3.x = mesh->mNormals[i].x;
			tempVec3.y = mesh->mNormals[i].y;
			tempVec3.z = mesh->mNormals[i].z;
			tempVertex.normal = tempVec3;
		}
		else tempVertex.normal = glm::vec3(0.f, 0.f, 1.f);

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
	return new Mesh(vertices.data(),vertices.size(),indices.data(),indices.size());
}

Model::Model(const char* path, Material* material, Texture* ovTexDif, unsigned int textureId)
{
	this->material = material;
	this->overrideTextureDiffuse = ovTexDif;
	this->textureId = textureId;
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

Model::Model( Material* material, Texture* ovTexDif, std::vector<Mesh*> meshes, unsigned int textureId)
{
	this->material = material;
	this->textureId = textureId;
	overrideTextureDiffuse = ovTexDif;
	for (auto* i : meshes)
	{
		this->meshes.push_back(new Mesh(*i));
	}

	for (auto& i : this->meshes)
	{
		//i->Move(this->position);
		//i->SetOrigin(this->position);
		//i->Rotate(glm::vec3(180.f, 0.f, 0.f));
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

	//Activate texture
	overrideTextureDiffuse->Bind(textureId);

	for (auto& i : meshes)
	{

		i->Render(shader);
	}

	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Model::SetPosition(const glm::vec3& position)
{
	for (auto& i : meshes)
	{
		i->SetPosition(position);
	}
}

void Model::SetRotation(const glm::vec3& rotation)
{
	for (auto& i : meshes)
	{
		i->SetRotation(rotation);
	}
}

void Model::SetScale(const glm::vec3& scale)
{
	for (auto& i : meshes)
	{
		i->SetScale(scale);
	}
}

void Model::Move(const glm::vec3& position)
{
	for (auto& i : meshes)
	{
		i->Move(position);
	}
}

void Model::Rotate(const glm::vec3& rotation)
{
	for (auto& i : meshes)
	{
		i->Rotate(rotation);
	}
}

void Model::Scale(const glm::vec3& scale)
{
	for (auto& i : meshes)
	{
		i->Scale(scale);
	}
}

void Model::SetMaterialAndTextures(Material* material, Texture* ovTexDif,  unsigned int textureId)
{
	this->material = material;
	this->overrideTextureDiffuse = ovTexDif;
	this->textureId = textureId;
}

Model::Model(const Model& model)
{
	this->material = model.material;
	for (auto& i : model.meshes)
		this->meshes.push_back(new Mesh(*i));
	this->overrideTextureDiffuse = model.overrideTextureDiffuse;
	this->textureId = model.textureId;
}
