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
	glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	m_PVertexSize = XManager::GetRef().m_FbxLoader->m_PVertexSize;
	m_pVertexInfo = XManager::GetRef().m_FbxLoader->m_pVertexInfo;

	program = XManager::GetRef().m_Tools->CompileProgram("./Shader/Render.vs", "./Shader/Render.fs");

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_PVertexSize * sizeof(XVertexInfo), m_pVertexInfo, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), 0);

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
	model.translate(0.0f, -2.5f, 0.0f);
	model.rotate(90.0f, 0.0f, 1.0f, 0.0f);
	model.scale(0.05f);
	GLint uModelLoc = glGetUniformLocation(program, "uModel");
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, model.data());

	XCamera* pCamera = XManager::GetRef().m_Camera;

	QMatrix4x4 view;
	view.lookAt(pCamera->m_Pos, pCamera->m_Pos + pCamera->m_Front, pCamera->m_Up);
	GLint uViewLoc = glGetUniformLocation(program, "uView");
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, view.data());

	QMatrix4x4 projection;
	projection.perspective(pCamera->m_Fov, (float)width / height, pCamera->m_Near, pCamera->m_Far);
	GLint uProjectionLoc = glGetUniformLocation(program, "uProjection");
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, projection.data());

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, m_PVertexSize);
	glBindVertexArray(0);

	glUseProgram(0);
}