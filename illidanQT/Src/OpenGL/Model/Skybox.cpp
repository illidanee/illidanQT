#include "Skybox.h"

#include <QMatrix4x4>
#include "../Manager.h"


XSkybox::XSkybox()
{

}

XSkybox::~XSkybox()
{

}

void XSkybox::Init()
{
	//Init OpenGL Functions
	initializeOpenGLFunctions();

	//Cube Vertices
	GLfloat vertices[] =
	{
		// Positions          
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,

		-1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f
	};

	//Cube Map Resources
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_rt.tga");
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_lf.tga");
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_up.tga");
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_dn.tga");
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_bk.tga");
	m_FaceTexture.push_back("./Resources/Skybox/drakeq_ft.tga");

	//Cube Map
	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_Texture);

	unsigned char* pImage = nullptr;
	int width = 0;
	int height = 0;
	for (int i = 0; i < 6; ++i)
	{
		
		pImage = XLoadImage(m_FaceTexture[i].c_str(), width, height);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pImage);
		XFreeImage(pImage);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	//GPU Program

	
	m_Program = XManager::GetRef().m_Tools->CompileProgram("./Shader/Skybox.vs", "./Shader/Skybox.fs");

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (const GLvoid*)(0));

	glBindVertexArray(0);
}

void XSkybox::Render(XManager& xManager, int width, int height)
{
	glDepthFunc(GL_LEQUAL);

	glUseProgram(m_Program);

	QMatrix4x4 view;
	view.lookAt(xManager.m_Camera->m_Pos, xManager.m_Camera->m_Pos + xManager.m_Camera->m_Front, xManager.m_Camera->m_Up);
	QMatrix4x4 viewNew = QMatrix4x4(view.normalMatrix());
	GLuint viewLoc = glGetUniformLocation(m_Program, "uView");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewNew.data());

	QMatrix4x4 projection;
	projection.perspective(xManager.m_Camera->m_Fov, (float)width / height, xManager.m_Camera->m_Near, xManager.m_Camera->m_Far);
	GLuint projectionLoc = glGetUniformLocation(m_Program, "uProjection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection.data());
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_Texture);
	GLuint textureLoc = glGetUniformLocation(m_Program, "uSkybox");
	glUniform1i(textureLoc, 0);

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);

	glUseProgram(m_Program);

	glDepthFunc(GL_LESS);
}