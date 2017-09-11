#ifndef __SKYBOX_H__
#define __SKYBOX_H__

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"

class XManager;
class XSkybox : public QOpenGLFunctions_3_3_Core
{
public:
	XSkybox();
	~XSkybox();

	void Init();
	void Render(XManager& xManager, int width, int height);

private:
	std::vector<std::string> m_FaceTexture;

	GLuint m_Texture;

	GLuint m_Program;
	GLuint m_VAO;
	GLuint m_VBO;
};

#endif