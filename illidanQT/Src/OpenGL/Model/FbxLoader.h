#ifndef __FBXLOADER_H__
#define __FBXLOADER_H__


/****************************************************************************************************************
 *    date    : 2017/09/14 14:33
 *
 *    author  : Smile
 *    Contact : smile@illidan.org
 *
 *    brief   : 解析Fbx文件数据。
 *
 ****************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

#define FBXSDK_SHARED
#include <fbxsdk.h>

#include "VertexInfo.h"



class XFbxLoader
{
public:
	XFbxLoader();
	~XFbxLoader();

	void Init();
	int LoadFbxFile(const char* pFbxFile);

	int GetTextureName(const char* pModelFile, const char* pFileName, char* pBuff);

private:
	int ProcessMaterial(FbxNode* pNode);
	int ProcessMesh(FbxNode* pNode);
	int ProcessNode(FbxNode* pNode);

	int ProcessNormal(FbxMesh* pMesh);
	int ProcessUV(FbxMesh* pMesh);
	int ProcessMaterialIndex(FbxMesh* pMesh, int index);

	

private:
	FbxManager* m_Manager;
	FbxImporter* m_Importer;

public:
	int m_PVertexSize;
	XVertexInfo* m_pVertexInfo;

	struct Mat
	{
		int type;
		char texture[256];
	};
	std::vector<Mat> m_vAllMats;
	std::unordered_map<int, int> m_uMatsIndex;
	std::vector<std::vector<int>> m_vIndices;
};


#endif


