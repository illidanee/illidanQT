#pragma once

#include <sstream>

#include <QOpenGLFunctions_3_3_Core>

#include "../Comm/Comm.h"
#include "XShader1.h"

using namespace std;

class XMesh : protected QOpenGLFunctions_3_3_Core
{
public:
	XMesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(XShader1 shader);
private:
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	GLuint VAO, VBO, EBO;
private:
	void SetupMesh();
};