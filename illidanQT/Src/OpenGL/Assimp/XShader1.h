#pragma once

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"

class XShader1 : protected QOpenGLFunctions_3_3_Core
{
public:
	GLuint m_Program;
public:
	XShader1();
	void SetUp(const char* pVertexShader, const char* pFragmentShader);
	void Use();
	void UnUse();
};
