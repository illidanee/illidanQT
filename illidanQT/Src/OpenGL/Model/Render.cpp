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
	glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);

	GLfloat vertices[] = {
		-0.7f, -0.5f, 0.0f,
		-0.3f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	program = XManager::GetRef().m_Tools->CompileProgram("./Shader/Render.vs", "./Shader/Render.fs");
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (const GLvoid*)0);
	
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

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}