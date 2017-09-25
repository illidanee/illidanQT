#pragma once

#include <QOpenGLFunctions_3_3_Core>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "XShader1.h"
#include "XMesh.h"

#include "../Comm/Comm.h"

using namespace std;
class XModel : protected QOpenGLFunctions_3_3_Core
{
public:
	XModel();
	void SetUp(const char* pFilePath, XShader1 shader);
	void Draw();

private:
	vector<XMesh> m_Meshes;
	string m_Dir;
	vector<Texture> m_TextureHasLoad;
	XShader1 m_Shader;
	MatrixLocation m_MatrixLocation;
	DirLightLocation m_DirLightLocation;
	GLuint m_ShininessLocation;
	GLuint m_ViewPositionLocation;
private:
	void LoadModel(const char* pFilePath);
	void ProcessNode(aiNode* pNode, const aiScene* pScene);
	XMesh ProcessMesh(aiMesh* pMesh, const aiScene* pScene);
	vector<Texture> LoadMaterialTexture(aiMaterial* pMaterial, aiTextureType textureType, string typeName);
};