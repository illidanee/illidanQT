
#include "XModel.h"

#include <QMatrix4x4>

#include "../Manager.h"

XModel::XModel()
{
	
}
void XModel::SetUp(const char* pFilePath, XShader1 shader)
{
	initializeOpenGLFunctions();

	LoadModel(pFilePath);
	m_Shader = shader;
	m_MatrixLocation.model = glGetUniformLocation(m_Shader.m_Program, "model");
	m_MatrixLocation.view = glGetUniformLocation(m_Shader.m_Program, "view");
	m_MatrixLocation.projection = glGetUniformLocation(m_Shader.m_Program, "projection");
}
void XModel::Draw()
{
	m_Shader.Use();

	QMatrix4x4 model;
	model.translate(0.0f, 0.0f, 0.0f);
	model.rotate(-180.0f, 0.0f, 1.0f, 0.0f);
	model.scale(0.8f);
	GLint uModelLoc = glGetUniformLocation(m_Shader.m_Program, "uModel");
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, model.data());

	XCamera* pCamera = XManager::GetRef().m_Camera;

	QMatrix4x4 view;
	view.lookAt(pCamera->m_Pos, pCamera->m_Pos + pCamera->m_Front, pCamera->m_Up);
	GLint uViewLoc = glGetUniformLocation(m_Shader.m_Program, "uView");
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, view.data());

	QMatrix4x4 projection;
	projection.perspective(pCamera->m_Fov, (float)1280.0f / 800, pCamera->m_Near, pCamera->m_Far);
	GLint uProjectionLoc = glGetUniformLocation(m_Shader.m_Program, "uProjection");
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, projection.data());

	for (unsigned int i = 0; i < m_Meshes.size(); ++i)
	{
		m_Meshes[i].Draw(m_Shader);
	}
	m_Shader.UnUse();
}
void XModel::LoadModel(const char* pFilePath)
{
	Assimp::Importer importer;
	const aiScene* pScene = importer.ReadFile(pFilePath, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
	if (!pScene || pScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !pScene->mRootNode)
	{
		std::cout << "Error : Load model file failed! - " << importer.GetErrorString() << std::endl;
		return;
	}
	string str = pFilePath;
	m_Dir = str.substr(0, str.find_last_of('/'));
	ProcessNode(pScene->mRootNode, pScene);
}
void XModel::ProcessNode(aiNode* pNode, const aiScene* pScene)
{
	for (unsigned int i = 0; i < pNode->mNumMeshes; ++i)
	{
		aiMesh* pMesh = pScene->mMeshes[pNode->mMeshes[i]];
		m_Meshes.push_back(ProcessMesh(pMesh, pScene));
	}

	for (unsigned int i = 0; i < pNode->mNumChildren; ++i)
	{
		aiNode* pChild = pNode->mChildren[i];
		ProcessNode(pChild, pScene);
	}
}
XMesh XModel::ProcessMesh(aiMesh* pMesh, const aiScene* pScene)
{
	//¶¥µã
	vector<Vertex> vertices;
	for (unsigned int i = 0; i < pMesh->mNumVertices; ++i)
	{
		Vertex vertex;
		aiVector3D position = pMesh->mVertices[i];
		vertex.Position[0] = position.x;
		vertex.Position[1] = position.y;
		vertex.Position[2] = position.z;
		aiVector3D normal = pMesh->mNormals[i];
		vertex.Normal[0] = normal.x;
		vertex.Normal[1] = normal.y;
		vertex.Normal[2] = normal.z;
		if (pMesh->mTextureCoords[0])
		{
			aiVector3D texCoord = pMesh->mTextureCoords[0][i];
			vertex.TexCoords[0] = texCoord.x;
			vertex.TexCoords[1] = texCoord.y;
		}
		else
		{
			vertex.TexCoords[0] = 0;
			vertex.TexCoords[1] = 0;
		}
		vertices.push_back(vertex);
	}
	//Ë÷Òý
	vector<unsigned int> indices;
	for (unsigned int i = 0; i < pMesh->mNumFaces; ++i)
	{
		aiFace face = pMesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j)
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	//A mesh does use only a single material.
	vector<Texture> textures;
	if (pMesh->mMaterialIndex > 0)
	{
		aiMaterial* pMaterial = pScene->mMaterials[pMesh->mMaterialIndex];
		vector<Texture> diffuseMaps = LoadMaterialTexture(pMaterial, aiTextureType_DIFFUSE, "texture_diffuse");
		vector<Texture> specularMaps = LoadMaterialTexture(pMaterial, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}
	return XMesh(vertices, indices, textures);
}
vector<Texture> XModel::LoadMaterialTexture(aiMaterial* pMaterial, aiTextureType textureType, string typeName)
{
	vector<Texture> textures;
	for (unsigned int i = 0; i < pMaterial->GetTextureCount(textureType); ++i)
	{
		aiString str;
		pMaterial->GetTexture(textureType, i, &str);
		bool bSkip = false;
		for (unsigned int j = 0; j < m_TextureHasLoad.size(); ++j)
		{
			if (strcmp(m_TextureHasLoad[j].path.c_str(), str.C_Str()) == 0)
			{
				textures.push_back(m_TextureHasLoad[j]);
				bSkip = true;
				break;
			}
		}
		if (!bSkip)
		{
			string allPath = m_Dir;
			allPath += '/';
			allPath += str.C_Str();
			Texture texture;
			texture.id = XManager::GetRef().m_Tools->CreateTexture2D(allPath.c_str());
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
		}
	}
	return textures;
}