#include "FbxLoader.h"

#define POLYGON_POINT_NUM 3  //三角形

XFbxLoader::XFbxLoader()
{
	m_pVertexInfo = 0;
}

XFbxLoader::~XFbxLoader()
{

}

void XFbxLoader::Init()
{
	m_Manager = FbxManager::Create();
	FbxIOSettings* pIoSettings = FbxIOSettings::Create(m_Manager, "FbxIOSetttings");
	m_Manager->SetIOSettings(pIoSettings);
	m_Importer = FbxImporter::Create(m_Manager, "FbxImporter");
}

void XFbxLoader::Destroy()
{
	m_Manager->Destroy();
}

void XFbxLoader::Reset()
{
	m_Name = "";

	m_PVertexSize = 0;
	if (m_pVertexInfo)
	{
		delete[] m_pVertexInfo;
		m_pVertexInfo = 0;
	}

	for (auto iter : m_vShaders)
	{
		iter->Destroy();
		delete iter;
	}
	m_vShaders.clear();
}

int XFbxLoader::LoadFbxFile(const char* pFbxFile)
{
	m_Name = pFbxFile;

	m_Importer->Initialize(pFbxFile, -1, m_Manager->GetIOSettings());
	FbxScene* pScene = FbxScene::Create(m_Manager, pFbxFile);
	bool res = m_Importer->Import(pScene);

	if (!res)
		return -1;

	FbxNode* pRootNode = pScene->GetRootNode();
	ProcessNode(pRootNode);

	for (auto shader : m_vShaders)
	{
		shader->Link();
	}

	pScene->Destroy();
	return 0;
}

void XFbxLoader::Render(int width, int height)
{
	for (auto shader : m_vShaders)
	{
		shader->Render(width, height);
	}
}

int XFbxLoader::ProcessMaterial(FbxNode* pNode)
{
	int nMaterialCount = pNode->GetMaterialCount();
	for (int i = 0; i < nMaterialCount; ++i)
	{
		FbxSurfaceMaterial* pSurfaceMaterial = pNode->GetMaterial(i);

		//diffuse
		FbxProperty oProperty = pSurfaceMaterial->FindProperty(FbxLayerElement::sTextureChannelNames[0]);
		if (oProperty.IsValid())
		{
			int nSrcCount = oProperty.GetSrcObjectCount<FbxTexture>();
			if (nSrcCount < 1)
				return -1;

			FbxTexture* oTexture = oProperty.GetSrcObject<FbxTexture>(0);
			if (!oTexture)
				return -2;
			
			XShader* shader = new XShader();
			shader->Init("./Shader/Render.vs", "./Shader/Render.fs");

			const char* pData = oTexture->GetName();

			char path[256];
			memset(path, 0, 256);
			GetTextureName(m_Name.c_str(), oTexture->GetName(), path);
			shader->AddDiffuseTexture(path);
			m_vShaders.push_back(shader);
		}
		else
		{
			return -3;
		}
	}

	return 0;
}

int XFbxLoader::ProcessMesh(FbxNode* pNode)
{
	FbxMesh* pMesh = pNode->GetMesh();
	if (!pMesh)
		return -1;

	int nControlPointsCount = pMesh->GetControlPointsCount();
	FbxVector4* pControlPoints = pMesh->GetControlPoints();

	int nPolygonCount = pMesh->GetPolygonCount();

	if (m_pVertexInfo)
	{
		delete[] m_pVertexInfo;
		m_pVertexInfo = 0;
	}

	m_PVertexSize = nPolygonCount * POLYGON_POINT_NUM;
	m_pVertexInfo = new XVertexInfo[m_PVertexSize];
	
	memset(m_pVertexInfo, 0, m_PVertexSize * sizeof(XVertexInfo));

	for (int i = 0; i < nPolygonCount; ++i)
	{
		int nPolygonSize = pMesh->GetPolygonSize(i);
		if (nPolygonSize != POLYGON_POINT_NUM)
		{
			return -2;
		}
		for (int j = 0; j < nPolygonSize; ++j)
		{
			//解析顶点数据
			int nVertexIndex = pMesh->GetPolygonVertex(i, j);
			FbxVector4 pos = pControlPoints[nVertexIndex];

			m_pVertexInfo[i * POLYGON_POINT_NUM + j].pos[0] = pos.mData[0];
			m_pVertexInfo[i * POLYGON_POINT_NUM + j].pos[1] = pos.mData[1];
			m_pVertexInfo[i * POLYGON_POINT_NUM + j].pos[2] = pos.mData[2];

			//解析法线数据
			FbxVector4 normal;
			if (pMesh->GetPolygonVertexNormal(i, j, normal))
			{
				m_pVertexInfo[i * POLYGON_POINT_NUM + j].normal[0] = normal.mData[0];
				m_pVertexInfo[i * POLYGON_POINT_NUM + j].normal[1] = normal.mData[1];
				m_pVertexInfo[i * POLYGON_POINT_NUM + j].normal[2] = normal.mData[2];
			}

			//解析UV数据
			FbxStringList oUVSetList;
			pMesh->GetUVSetNames(oUVSetList);
			if (oUVSetList.GetCount() > 0)
			{
				FbxVector2 uv;
				bool flag = true;
				if (pMesh->GetPolygonVertexUV(i, j, oUVSetList[0], uv, flag))
				{
					m_pVertexInfo[i * POLYGON_POINT_NUM + j].uv[0] = uv.mData[0];
					m_pVertexInfo[i * POLYGON_POINT_NUM + j].uv[1] = 1 - uv.mData[1];
				}
			}
		}

		ProcessMaterialIndex(pMesh, i);
	}

	return 0;
}

int XFbxLoader::ProcessNode(FbxNode* pNode)
{
	int nAttributeCount = pNode->GetNodeAttributeCount();
	for (int i = 0; i < nAttributeCount; ++i)
	{
		FbxNodeAttribute* pAttribute = pNode->GetNodeAttributeByIndex(i);

		if (!pAttribute)
			continue;

		FbxNodeAttribute::EType eType = pAttribute->GetAttributeType();
		switch (eType)
		{
		case FbxNodeAttribute::eMesh:
		{
			ProcessMaterial(pNode);
			ProcessMesh(pNode);
			break;
		}
		}
	}

	//处理子节点
	int nChildCount = pNode->GetChildCount();
	for (int i = 0; i < nChildCount; ++i)
	{
		FbxNode* pChild = pNode->GetChild(i);
		ProcessNode(pChild);
	}

	return 0;
}

int XFbxLoader::ProcessNormal(FbxMesh* pMesh)
{


	return 0;
}

int XFbxLoader::ProcessUV(FbxMesh* pMesh)
{

	return 0;
}

int XFbxLoader::ProcessMaterialIndex(FbxMesh* pMesh, int index)
{
	int nElementMaterialCount = pMesh->GetElementMaterialCount();
	if (nElementMaterialCount < 1)
		return -1;

	FbxGeometryElementMaterial* pGeometryElementMaterial = pMesh->GetElementMaterial(0);
	if (!pGeometryElementMaterial)
		return -2;

	FbxLayerElement::EMappingMode eMappingMode = pGeometryElementMaterial->GetMappingMode();
	FbxLayerElement::EReferenceMode eReferenceMode = pGeometryElementMaterial->GetReferenceMode();
	switch (eMappingMode)
	{
	case FbxLayerElement::eByPolygon:
	{
		switch (eReferenceMode)
		{
		case FbxLayerElement::eIndexToDirect:
			{
				int nMaterialIndex = pGeometryElementMaterial->GetIndexArray().GetAt(index);
				if (nMaterialIndex < m_vShaders.size())
				{
					m_vShaders[nMaterialIndex]->AddVertex(m_pVertexInfo[index * 3 + 0]);
					m_vShaders[nMaterialIndex]->AddVertex(m_pVertexInfo[index * 3 + 1]);
					m_vShaders[nMaterialIndex]->AddVertex(m_pVertexInfo[index * 3 + 2]);
				}
			}
		}
		break;
	}
	}
	return 0;
}

int XFbxLoader::GetTextureName(const char* pModelFile, const char* pFileName, char* pBuff)
{
	strcpy(pBuff, pModelFile);
	memset(pBuff + strlen(pBuff) - 3, 0, 3);
	strcat(pBuff, "fbm/");
	strcat(pBuff, pFileName);

	return 0;
}