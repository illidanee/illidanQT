#ifndef __RENDER_H__
#define __RENDER_H__

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"

class XManager;
class XRender : public QOpenGLFunctions_3_3_Core
{
public:
	XRender();
	~XRender();

	void Init();
	void Resize(int width, int height);
	void Render(XManager& xManager, int width, int height);

private:
	unsigned* index1;
	int size1;
	GLuint program;
	GLuint vbo;
	GLuint vao1;
	GLuint ebo1;
	GLuint texture1;

};

#endif