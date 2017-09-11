#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QTime>


class XCamera
{
public:
	XCamera();
	~XCamera();

	void Init();

	void OnRightButtonDown(int x, int y);
	void OnRightButtonUp(int x, int y);
	void OnMouseMove(int x, int y);
	void OnZoomIn();
	void OnZoomOut();

	void OnKeyDown(int key);
	void OnKeyUp(int key);
	void OnUpdate();


public:
	float m_Fov;
	float m_Near;
	float m_Far;

	QVector3D m_Pos;
	QVector3D m_Front;
	QVector3D m_Up;


private:
	bool m_RightButtonDown;
	int m_LastX;
	int m_LastY;
	float m_Sensitivity;
	float m_Pitch;
	float m_Yaw;

	bool m_State[256];
	float m_Speed;

	QTime m_Timer;
};

#endif // CAMERA_H
