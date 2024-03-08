#include<stdio.h>
#include <string.h>

/************************************************************************/
/* ���ܣ�ʵ���ַ����Ĳ��Һ��滻�����б��滻�����ֵĵط������滻���滻
/* ������pSrc--ָ��Դ�ַ���
/*       pDst--ָ���滻��ɺ���ַ���������Ϊ�������
/*       pOldString--ָ���滻�ַ���
/*       pNewString--ָ���滻�ַ���
/************************************************************************/
void FindAndReplace(char* pSrc, char* pDst, char* pOldString, char* pNewString)
{
	char* pInput = pSrc, // ָ��Դ�ַ������ζ�ָ��
		* pOutput = pDst,// ָ��Ŀ���ַ���(���滻����ַ���)���ζ�ָ��
		* p = NULL;  // ָ����ҵ����ַ�����λ�õ�ָ��
	int nOldStringLen = strlen(pOldString);  // ���滻�ַ����ĳ���
	int nNewStringLen = strlen(pNewString); // �滻�ַ����ĳ���
	int nLen;

	// ���ұ��滻�ַ�����Դ�ַ����е�һ�γ��ֵ�λ��
	p = strstr(pInput, pOldString);

	if (p) // ����ҵ���
	{
		while (p)
		{
			// ���㱻�滻��ǰ���ַ����ĳ���. 
			nLen = (int)(p - pInput);

			// �����滻�ַ����״γ���ǰ���ַ������Ƶ�����ַ�����
			memcpy(pOutput, pInput, nLen);

			// ���滻�����Ƶ��������
			memcpy(pOutput + nLen, pNewString, nNewStringLen);

			// �������滻����λ��
			pInput = p + nLen;

			// ����ָ���������λ��
			pOutput = pOutput + nLen + nNewStringLen;

			// �������²���
			p = strstr(pInput, pOldString);
		}

		// ��ʣ�ಿ�ָ��Ƶ��������
		strcpy(pOutput, pInput);
	}
	else // ������滻������Դ�ַ����г��֣��򷵻�Դ�ַ���
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