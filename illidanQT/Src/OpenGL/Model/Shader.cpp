#include "Shader.h"

#include <QMatrix4x4>

#include "../Manager.h"

XShader::XShader()
{
	m_nProgram = -1;
	m_nVAO = -1;
	m_nVBO = -1;
	m_nDiffuseTexture = -1;
}

XShader::~XShader()
{

}

void XShader::Init(const char* pVsShader, const char* pFsShader)
{	
	//Init OpenGL Functions
	initializeOpenGLFunctions();

	m_nProgram = XManager::GetRef().m_Tools->CompileProgram(pVsShader, pFsShader);
}

void XShader::Destroy()
{
	m_vAllVertices.clear();
	glDeleteTextures(1, &m_nDiffuseTexture);
	glDeleteBuffers(1, &m_nVBO);
	glDeleteVertexArrays(1, &m_nVAO);
	glDeleteProgram(m_nProgram);
}

void XShader::AddVertex(XVertexInfo vertex)
{
	m_vAllVertices.push_back(vertex);
}

void XShader::AddDiffuseTexture(const char* pDiffuseTexture)
{
	int w;
	int h;
	unsigned char* pImage = XLoadImage(pDiffuseTexture, w, h);

	glGenTextures(1, &m_nDiffuseTexture);
	glBindTexture(GL_TEXTURE_2D, m_nDiffuseTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pImage);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, 0);

	XFreeImage(pImage);
}

void XShader::Link()
{
	unsigned int size = m_vAllVertices.size();

	XVertexInfo* pBuffer = new XVertexInfo[size];
	for (int i = 0; i < size; ++i)
	{
		pBuffer[i] = m_vAllVertices[i];
	}

	glGenVertexArrays(1, &m_nVAO);
	glGenBuffers(1, &m_nVBO);

	glBindVertexArray(m_nVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_nVBO);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(XVertexInfo), pBuffer, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), (const void*)(sizeof(float) * 3));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(XVertexInfo), (const void*)(sizeof(float) * 6));

	glBindVertexArray(0);

	delete[] pBuffer;
}

void XShader::Render(int width, int height)
{
	glUseProgram(m_nProgram);

	QMatrix4x4 model;
	model.translate(0.0f, 0.0f, 0.0f);
	model.rotate(-180.0f, 0.0f, 1.0f, 0.0f);
	model.scale(0.8f);
	GLint uModelLoc = glGetUniformLocation(m_nProgram, "uModel");
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, model.data());

	XCamera* pCamera = XManager::GetRef().m_Camera;

	QMatrix4x4 view;
	view.lookAt(pCamera->m_Pos, pCamera->m_Pos + pCamera->m_Front, pCamera->m_Up);
	GLint uViewLoc = glGetUniformLocation(m_nProgram, "uView");
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, view.data());

	QMatrix4x4 projection;
	projection.perspective(pCamera->m_Fov, (float)width / height, pCamera->m_Near, pCamera->m_Far);
	GLint uProjectionLoc = glGetUniformLocation(m_nProgram, "uProjection");
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, projection.data());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_nDiffuseTexture);
	GLuint texLoc = glGetUniformLocation(m_nProgram, "tex");
	glUniform1i(texLoc, 0);

	glBindVertexArray(m_nVAO);
	glDrawArrays(GL_TRIANGLES, 0, m_vAllVertices.size());
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(0);

	GLenum err = glGetError();
	if (err != 0)
	{
		std::cout << "++++++++++++++++++++++++++++++++" << err << std::endl;
	}
}