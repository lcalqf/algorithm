////��ת�ַ����еĵ���˳�򣬵������е���ĸ����ת
////�������롰I am a student.�����������student.a am I�� ��
//#include <stdio.h>
//void Reserver(char *pBegin, char *pEnd)
//{
//	if (pBegin==NULL||pEnd==NULL)
//	{
//		return;
//	}
//	while (pBegin < pEnd)
//	{
//		char pTemp = *pBegin;
//		*pBegin = *pEnd;
//		*pEnd = pTemp;
//		pBegin++;
//		pEnd--;
//	}
//}
//char * ReverseString(char*pWord)
//{
//	if (!pWord)
//	{
//		return NULL;
//	}
//	char *pBegin = pWord;
//	char *pEnd = pWord;
//	while (*pEnd != '\0')
//	{
//		pEnd++;
//	}
//	pEnd--;//ָ���ַ�����β��
//	//��ת�����ַ���
//	Reserver(pBegin, pEnd);
//	pBegin =pEnd = pWord;
//	while (*pBegin!='\0')
//	{
//		if (*pEnd==' '||*pEnd=='\0')//pEnd��ʱָ�򵥴ʺ���Ŀո�
//		{
//			char *pTemp = pEnd;
//			Reserver(pBegin, pEnd);
//			pBegin = pEnd=pTemp++;
//			continue;
//		}
//		else
//		{
//			pEnd++;
//		}
//	}
//	return pWord;
//}
//int main()
//{
//	
//	char *pWord = "I am a student.";
//	pWord=ReverseString(pWord);
//
//	return 0;
//}

#include<stdio.h>
#include <string.h>
#include <iostream>
#include<string>
using namespace std;
#define MAXN 1000  
//��ת�ַ���
char* ReverseString(char *pWord)
{
	if (pWord==nullptr)
	{
		return nullptr;
	}
	else
	{
		char*pBegin, *pEnd;
		pBegin = pEnd = pWord;
		while (*pEnd!='\0')
		{
			pEnd++;
		}
		pEnd--;//ָ���ַ�����β��
		while (pBegin<pEnd)
		{
			char pTemp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = pTemp;
			pBegin++;
			pEnd--;
			
		}
	}
	return pWord;
}
void Reverse(char *pBegin, char*pEnd)
{
	if (pBegin==NULL||pEnd==NULL)
	{
		return;
	}
	while (pBegin < pEnd)
	{
		char pTemp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = pTemp;
		pBegin++;
		pEnd--;
	}
}
char *ReserverSentence(char *pWord)
{
	if (pWord== NULL)
	{
		return NULL;
	}
	char *pBegin = pWord;
	char*pEnd = pWord;
	while (*pEnd!='\0')
	{
		pEnd++;
	}
	pEnd--;
	Reverse(pBegin, pEnd);
	pBegin = pEnd = pWord;
	while (*pBegin!='\0')
	{
		if (*pBegin==' ')
		{
			pBegin++;
			pEnd++;
			continue;
		}
		else if (*pEnd==' '||*pEnd=='\0')
		{
			//����
			Reverse(pBegin, --pEnd);//��ʱpEnd ָ�򵥴ʺ����һ���ַ������Ե���ǰ�ƶ�һ��
			 ++pEnd;
			 pBegin = pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pWord;
}

string reverseString(string s)
{
	string ret;
	if (s.empty()) return ret;
	string::const_iterator tail = s.cend();
	do
	{
		tail--;
		ret.push_back(*tail);
	} while (tail != s.cbegin());
	return ret;
}
int main()
{
	char pWord[]= "I am a student";
	char *result= ReserverSentence(pWord);
	printf("%s\n", result);
	getchar();
	return 0;
}