#include "XShader1.h"

#include "../Manager.h"

XShader1::XShader1()
{

}
void XShader1::SetUp(const char* pVertexShader, const char* pFragmentShader)
{
	initializeOpenGLFunctions();

	m_Program = XManager::GetRef().m_Tools->CompileProgram(pVertexShader, pFragmentShader);
}
void XShader1::Use()
{
	glUseProgram(m_Program);
}
void XShader1::UnUse()
{
	glUseProgram(0);
}