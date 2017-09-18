#ifndef __RENDER_H__
#define __RENDER_H__

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"
#include "FbxLoader.h"


class XManager;
class XVertexInfo;
class XRender : public QOpenGLFunctions_3_3_Core
{
public:
	XRender();
	~XRender();

	void Init();
	void ResetFile(const char* pFileName);
	void Resize(int width, int height);
	void Render(XManager& xManager, int width, int height);

private:
	//int m_PVertexSize;
	//XVertexInfo* m_pVertexInfo;

	//GLuint program;
	//GLuint vbo;
	//GLuint vao;
	XFbxLoader* fbx;
};

#endif