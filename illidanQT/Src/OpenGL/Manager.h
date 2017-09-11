#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "./Comm/Comm.h"
#include "./Model/Tools.h"
#include "./Model/Camera.h"
#include "./Model/Skybox.h"
#include "./Model/Render.h"

class XManager
{
private:
	XManager();
	~XManager();

	static XManager g_XManager;

public:
	static XManager& GetRef();
	static XManager* GetPtr();
	void Init();

public:
	XTools* m_Tools;
	XCamera* m_Camera;
	XSkybox* m_Skybox;
	XRender* m_Render;
};

#endif