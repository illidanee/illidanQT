#include "Manager.h"


XManager XManager::g_XManager;

XManager::XManager()
{

}

XManager::~XManager()
{

}

XManager& XManager::GetRef()
{
	return g_XManager;
}

XManager* XManager::GetPtr()
{
	return &g_XManager;
}

void XManager::Init()
{
	//¿ªÆô¿ØÖÆÌ¨
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);


	m_Tools = new XTools();
	m_Tools->Init();

	m_Camera = new XCamera();
	m_Camera->Init();

	m_Skybox = new XSkybox();
	m_Skybox->Init();

	m_Render = new XRender();
	m_Render->Init();
}