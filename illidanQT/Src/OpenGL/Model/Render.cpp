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

	fbx = new XFbxLoader();
	fbx->Init();
	fbx->LoadFbxFile("./Resources/Model/skin_man.FBX");
}

void XRender::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void XRender::Render(XManager& xManager, int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	fbx->Render(width, height);
}