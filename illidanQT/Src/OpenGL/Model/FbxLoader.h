#ifndef __FBXLOADER_H__
#define __FBXLOADER_H__


/****************************************************************************************************************
 *    date    : 2017/09/14 14:33
 *
 *    author  : Smile
 *    Contact : smile@illidan.org
 *
 *    brief   : ����Fbx�ļ����ݡ�
 *
 ****************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

#define FBXSDK_SHARED
#include <fbxsdk.h>

#include "VertexInfo.h"

#include "Shader.h"

class XFbxLoader
{
public:
	XFbxLoader();
	~XFbxLoader();

	void Init();
	void Destroy();
	void Reset();
	int LoadFbxFile(const char* pFbxFile);
	void Render(int width, int height);

	int GetTextureName(const char* pModelFile, const char* pFileName, char* pBuff);

private:
	int ProcessMaterial(FbxNode* pNode);
	int ProcessMesh(FbxNode* pNode);
	int ProcessNode(FbxNode* pNode);

	int ProcessNormal(FbxMesh* pMesh);
	int ProcessUV(FbxMesh* pMesh);
	int ProcessMaterialIndex(FbxMesh* pMesh, int index);

	

private:
	std::string m_Name;
	FbxManager* m_Manager;
	FbxImporter* m_Importer;

public:
	int m_PVertexSize;
	XVertexInfo* m_pVertexInfo;

	std::vector<XShader*> m_vShaders;
};


#endif


