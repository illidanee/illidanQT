#include "Tools.h"



XTools::XTools()
{

}

XTools::~XTools()
{

}

void XTools::Init()
{
	//³õÊ¼»¯OpenGLº¯Êý
	initializeOpenGLFunctions();
}

GLuint XTools::CompileShader(GLenum sType, const char* pFilePath)
{
	GLuint shader = glCreateShader(sType);
	if (!shader)
	{
		LOG("Create shader failed.");
		return 0;
	}
	char* pShaderCode = LoadFile(pFilePath);
	if (!pShaderCode)
	{
		LOG("LoadFile failed.");
		glDeleteShader(shader);
		return 0;
	}
	glShaderSource(shader, 1, &pShaderCode, 0);
	glCompileShader(shader);
	GLint ret;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &ret);
	if (ret == GL_FALSE)
	{
		GLsizei lenth;
		GLchar logBuffer[__BUFFER_SIZE__] = {};
		glGetShaderInfoLog(shader, __BUFFER_SIZE__, &lenth, logBuffer);
		LOG(logBuffer);
		delete[] pShaderCode;
		glDeleteShader(shader);
		return 0;
	}
	delete[] pShaderCode;
	return shader;
}

GLuint XTools::CompileProgram(const char* pVsShader, const char* pFsShader)
{
	GLuint program = glCreateProgram();
	if (!program)
	{
		LOG("Create program failed.");
		return 0;
	}
	GLuint vsShader = CompileShader(GL_VERTEX_SHADER, pVsShader);
	if (!vsShader)
	{
		LOG("Compile vs shader failed.");
		glDeleteProgram(program);
		return 0;
	}
	GLuint fsShader = CompileShader(GL_FRAGMENT_SHADER, pFsShader);
	if (!fsShader)
	{
		LOG("Compile fs shader failed.");
		glDeleteShader(vsShader);
		glDeleteProgram(program);
		return 0;
	}
	glAttachShader(program, vsShader);
	glAttachShader(program, fsShader);
	glLinkProgram(program);

	GLint ret;
	glGetProgramiv(program, GL_LINK_STATUS, &ret);
	if (ret == FALSE)
	{
		GLsizei lenth;
		GLchar logBuffer[__BUFFER_SIZE__] = {};
		glGetProgramInfoLog(program, __BUFFER_SIZE__, &lenth, logBuffer);
		LOG(logBuffer);
		glDeleteShader(vsShader);
		glDeleteShader(fsShader);
		glDeleteProgram(program);
		return 0;
	}

	glDetachShader(program, vsShader);
	glDetachShader(program, fsShader);
	glDeleteShader(vsShader);
	glDeleteShader(fsShader);

	return program;
}