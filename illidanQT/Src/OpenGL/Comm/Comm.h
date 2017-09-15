#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <iostream>
#include <SOIL.h>

#define __BUFFER_SIZE__ 1204
#define __NAME_LEN__ 256

#define LOG(str) Log(__FILE__, __LINE__, str)
void Log(const char* pFile, unsigned int Line, const char* pStr);


char * LoadFile(const char* pFilePath);
unsigned char* XLoadImage(const char* pFileName, int& width, int& height);
void XFreeImage(unsigned char* pImage);


#endif