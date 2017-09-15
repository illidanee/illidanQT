#include "Render.h"

#include <QMatrix4x4>
#include "../Manager.h"


XRender::XRender()
{

}

XRender::~XRender()
{

}

void XRender::Init()
{
	//Init OpenGL Functions
	initializeOpenGLFunctions();

	//Init value
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	XVertexInfo* pVertexInfo = XManager::GetRef().m_FbxLoader->m_pVertexInfo;

	std::cout << XManager::GetRef().m_FbxLoader->m_PVertexSize;
	std::vector<std::vector<int>>& m_vIndices = XManager::GetRef().m_FbxLoader->m_vIndices;
	std::vector<XFbxLoader::Mat> m_vAllMats = XManager::GetRef().m_FbxLoader->m_vAllMats;

	size1 = m_vIndices[1].size();
	index1 = new unsigned int[size1];
	
	for (int i = 0; i <size1; ++i)
	{
		index1[i] = m_vIndices[1][i];
	}

	int w;
	int h;

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	char name1[256];
	XManager::GetRef().m_FbxLoader->GetTextureName("./Resources/Model/tauren.fbx", m_vAllMats[1].texture, name1);
	unsigned char* image1 = XLoadImage(name1, w, h);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image1);
	//XFreeImage(image1);
	glBindTexture(GL_TEXTURE_2D, 0);

	program = XManager::GetRef().m_Tools->CompileProgram("./Shader/Render.vs", "./Shader/Render.fs");

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo1);
	glGenVertexArrays(1, &vao1);

	glBindVertexArray(vao1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, XManager::GetRef().m_FbxLoader->m_PVertexSize, XManager::GetRef().m_FbxLoader->m_pVertexInfo, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size1, index1, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), (const GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), (const GLvoid*)(sizeof(float) * 3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), (const GLvoid*)(sizeof(float) * 6));

	glBindVertexArray(0);
}

void XRender::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void XRender::Render(XManager& xManager, int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(program);

	QMatrix4x4 model;
	GLuint modelLoc = glGetUniformLocation(program, "uModel");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());

	QMatrix4x4 view;
	view.lookAt(xManager.m_Camera->m_Pos, xManager.m_Camera->m_Pos + xManager.m_Camera->m_Front, xManager.m_Camera->m_Up);
	GLuint viewLoc = glGetUniformLocation(program, "uView");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.data());

	QMatrix4x4 projection;
	projection.perspective(xManager.m_Camera->m_Fov, (float)width / height, xManager.m_Camera->m_Near, xManager.m_Camera->m_Far);
	GLuint projectionLoc = glGetUniformLocation(program, "uProjection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection.data());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	GLuint textureLoc = glGetUniformLocation(program, "tex");
	glUniform1i(textureLoc, 0);

	glBindVertexArray(vao1);
	//glDrawElements(GL_TRIANGLES, size1 / 3, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, size1);
	glBindVertexArray(0);
	glUseProgram(0);
}