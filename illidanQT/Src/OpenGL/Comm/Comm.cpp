#include "Comm.h"

void Log(const char* pFile, unsigned int Line, const char* pStr)
{
	std::cout << "Error : [" << pFile << ":" << Line << "] = " << pStr << std::endl;
}

char * LoadFile(const char* pFilePath)
{
	FILE*pFile = fopen(pFilePath, "rb");
	if (!pFile)
	{
		LOG("Open file failed.");
		return NULL;
	}
	fseek(pFile, 0, SEEK_END);
	int nLen = ftell(pFile);
	if (nLen == 0)
	{
		LOG("File Lenght equal to 0.");
		fclose(pFile);
		return NULL;
	}
	char* pBuffer = new char[nLen + 1];
	rewind(pFile);
	fread(pBuffer, nLen, 1, pFile);
	pBuffer[nLen] = '\0';
	fclose(pFile);
	return pBuffer;
}


unsigned char* XLoadImage(const char* pFileName, int& width, int& height)
{
	int channal;
	return SOIL_load_image(pFileName, &width, &height, &channal, SOIL_LOAD_RGBA);
}

void XFreeImage(unsigned char* pImage)
{
	SOIL_free_image_data(pImage);
}