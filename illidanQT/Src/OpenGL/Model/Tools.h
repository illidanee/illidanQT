#ifndef __XTOOLS_H__
#define __XTOOLS_H__

#include <QOpenGLFunctions_3_3_Core>
#include "../Comm/Comm.h"

class XTools : protected QOpenGLFunctions_3_3_Core
{
public:
	XTools();
	~XTools();

	void Init();

private:
	GLuint CompileShader(GLenum sType, const char* pFilePath);

public:
	GLuint CompileProgram(const char* pVsShader, const char* pFsShader);
};

#endif
