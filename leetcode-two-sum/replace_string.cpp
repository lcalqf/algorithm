#include<stdio.h>
#include <string.h>

/************************************************************************/
/* 功能：实现字符串的查找和替换，所有被替换串出现的地方都用替换串替换
/* 参数：pSrc--指向源字符串
/*       pDst--指向替换完成后的字符串，并作为输出参数
/*       pOldString--指向被替换字符串
/*       pNewString--指向替换字符串
/************************************************************************/
void FindAndReplace(char* pSrc, char* pDst, char* pOldString, char* pNewString)
{
	char* pInput = pSrc, // 指向源字符串的游动指针
		* pOutput = pDst,// 指向目标字符串(即替换后的字符串)的游动指针
		* p = NULL;  // 指向查找到的字符串的位置的指针
	int nOldStringLen = strlen(pOldString);  // 被替换字符串的长度
	int nNewStringLen = strlen(pNewString); // 替换字符串的长度
	int nLen;

	// 查找被替换字符串在源字符串中第一次出现的位置
	p = strstr(pInput, pOldString);

	if (p) // 如果找到了
	{
		while (p)
		{
			// 计算被替换串前边字符串的长度. 
			nLen = (int)(p - pInput);

			// 将被替换字符串首次出现前的字符串复制到输出字符串中
			memcpy(pOutput, pInput, nLen);

			// 将替换串复制到输出串中
			memcpy(pOutput + nLen, pNewString, nNewStringLen);

			// 跳过被替换串的位置
			pInput = p + nLen;

			// 调整指向输出串的位置
			pOutput = pOutput + nLen + nNewStringLen;

			// 继续往下查找
			p = strstr(pInput, pOldString);
		}

		// 将剩余部分复制到输出串中
		strcpy(pOutput, pInput);
	}
	else // 如果被替换串不在源字符串中出现，则返回源字符串
	{
		strcpy(pDst, pSrc);
	}

}

int main()
{
	char src[] = "abcdesdesdrsdsdse";
	char dst[100];

	FindAndReplace(src, dst, "sd", "ILOVEYOU");
	printf("%s\n", dst);

	return 0;
}