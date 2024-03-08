////反转字符串中的单词顺序，但单词中的字母不翻转
////例如输入“I am a student.”，则输出“student.a am I” 。
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
//	pEnd--;//指向字符串的尾部
//	//翻转整个字符串
//	Reserver(pBegin, pEnd);
//	pBegin =pEnd = pWord;
//	while (*pBegin!='\0')
//	{
//		if (*pEnd==' '||*pEnd=='\0')//pEnd此时指向单词后面的空格
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
//翻转字符串
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
		pEnd--;//指向字符串的尾部
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
			//交换
			Reverse(pBegin, --pEnd);//此时pEnd 指向单词后面的一个字符，所以得向前移动一个
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