#ifndef __SHADER_H__
#define __SHADER_H__


/****************************************************************************************************************
 *    date    : 2017/09/15 14:38
 *
 *    author  : Smile
 *    Contact : smile@illidan.org
 *
 *    brief   : ≥ÈœÛShader∂‘œÛ
 *
 ****************************************************************************************************************/

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"
#include "VertexInfo.h"

class XShader : public QOpenGLFunctions_3_3_Core
{
public:
	XShader();
	~XShader();

	void Init(const char* pVsShader, const char* pFsShader);
	void Destroy();
	void AddVertex(XVertexInfo vertex);
	void AddDiffuseTexture(const char* pDiffuseTexture);
	void Link();
	void Render(int width, int height);

private:
	std::vector<XVertexInfo> m_vAllVertices;

	GLuint m_nProgram;
	GLuint m_nVAO;
	GLuint m_nVBO;
	GLuint m_nDiffuseTexture;
};


#endif


