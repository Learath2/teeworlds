#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <engine/config.h>

extern CConfig *g_pConfig;
class CTestInfo
{
public:
	CTestInfo();
	void Filename(char *pBuffer, int BufferLength, const char *pSuffix);
	char m_aFilenamePrefix[64];
	char m_aFilename[64];
};
#endif // TEST_TEST_H
