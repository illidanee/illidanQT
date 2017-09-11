#include "camera.h"

#include <QtMath>


XCamera::XCamera()
{

}

XCamera::~XCamera()
{

}

void XCamera::Init()
{
	m_Fov = 45.0f;
	m_Near = 0.1f;
	m_Far = 1000.0f;

	m_Pos = { 0.0f, 0.0f, 0.0f };
	m_Front = { 0.0f, 0.0f, -1.0f };
	m_Up = { 0.0f, 1.0f, 0.0f };

	m_RightButtonDown = false;
	m_LastX = -1;
	m_LastY = -1;
	m_Sensitivity = 0.2f;
	m_Pitch = 0;
	m_Yaw = -90;

	memset(m_State, 0, sizeof(m_State));
	m_Speed = 0.00002f;

	m_Timer.start();
}

void XCamera::OnRightButtonDown(int x, int y)
{
	m_RightButtonDown = true;
	m_LastX = x;
	m_LastY = y;
}


void XCamera::OnRightButtonUp(int x, int y)
{
	m_RightButtonDown = false;
}

void XCamera::OnMouseMove(int x, int y)
{
	if (m_RightButtonDown)
	{
		float offsetX = (x - m_LastX) * m_Sensitivity;
		float offsetY = (m_LastY - y) * m_Sensitivity;
		m_Pitch += offsetY;
		m_Yaw += offsetX;
		if (m_Pitch > 89.0f)
			m_Pitch = 89.0f;
		if (m_Pitch < -89.0f)
			m_Pitch = -89.0f;

		m_Front.setX(qCos(qDegreesToRadians(m_Pitch)) * qCos(qDegreesToRadians(m_Yaw)));
		m_Front.setY(qSin(qDegreesToRadians(m_Pitch)));
		m_Front.setZ(qCos(qDegreesToRadians(m_Pitch)) * qSin(qDegreesToRadians(m_Yaw)));
		m_Front.normalize();

		m_LastX = x;
		m_LastY = y;
	}
}

void XCamera::OnZoomIn()
{
	m_Fov -= 1.0f;
	if (m_Fov < 10.0f)
		m_Fov = 10.0f;
}

void XCamera::OnZoomOut()
{
	m_Fov += 1.0f;
	if (m_Fov > 45.0f)
		m_Fov = 45.0f;
}

void XCamera::OnKeyDown(int key)
{
	switch (key)
	{
	case Qt::Key_W:
	case Qt::Key_S:
	case Qt::Key_A:
	case Qt::Key_D:
		m_State[key] = true;
		break;
	}
}

void XCamera::OnKeyUp(int key)
{
	switch (key)
	{
	case Qt::Key_W:
	case Qt::Key_S:
	case Qt::Key_A:
	case Qt::Key_D:
		m_State[key] = false;
		break;
	}
}

void XCamera::OnUpdate()
{
	float offset = m_Speed * m_Timer.elapsed();

	if (m_State[Qt::Key_W])
	{
		m_Pos += offset * m_Front;
	}

	if (m_State[Qt::Key_S])
	{
		m_Pos -= offset * m_Front;
	}

	if (m_State[Qt::Key_A])
	{
		m_Pos -= offset * QVector3D::crossProduct(m_Front, m_Up).normalized();
	}

	if (m_State[Qt::Key_D])
	{
		m_Pos += offset * QVector3D::crossProduct(m_Front, m_Up).normalized();
	}
}

