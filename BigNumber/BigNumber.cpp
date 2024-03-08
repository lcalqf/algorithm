#include <iostream>
using namespace std;
#define  MAXSIZE 1000000000
int log=5;
char * BigNumberPlus(char * number1, char* number2)
{
	char* Sum = new char[MAXSIZE + 2];      //MAXSIZE 为宏定义 
	int len1 = strlen(number1);
	int len2 = strlen(number2);
	int maxLen = len1 > len2 ? len1 : len2;
	char* temp1 = new char[maxLen + 1];
	char* temp2 = new char[maxLen + 1];
	memset(temp1, '0', maxLen);               //初始化的过程已经补齐字符串
	temp1[maxLen] = '\0';
	memset(temp2, '0', maxLen);
	temp2[maxLen] = '\0';
	int nSum = 0;
	int isCarryBit = 0;
	int isOverflow = 0;
	int i = 0, j = 0;
	//////////////////////反转字符串
	for (i = len1 - 1; i >= 0; i--)
	{
		temp1[j++] = number1[i];
	}
	temp1[j] = '\0';
	j = 0;
	for (i = len2 - 1; i >= 0; i--)
	{
		temp2[j++] = number2[i];
	}
	//////////////////////字符串相加，从低位到高位
	for (i = 0; i < maxLen; i++)
	{
		nSum = temp1[i] - '0' + temp2[i] - '0' + isCarryBit;
		//////是否有进位
		if (nSum > 9)
		{
			if (i == maxLen - 1)
			{
				isOverflow = 1;    //是否溢出
			}
			isCarryBit = 1;
			Sum[i] = nSum - 10 + '0';
		}
		else
		{
			isCarryBit = 0;
			Sum[i] = '0' + nSum;
		}
	}
	if (isOverflow)
	{
		Sum[maxLen++] = '0'+isCarryBit;
	}
	Sum[maxLen] = '\0';
	///////////////打印
	for (i = maxLen - 1; i >= 0; i--)
	{
		cout << Sum[i];
	}
	cout << endl;

	delete[] temp1;
	delete[] temp2;
	return Sum;
}
void my_itoa(int i, char *string)
{
	int power = 0, j = 0;

	j = i;
	for (power = 1; j > 10; j /= 10)
		power *= 10;

	for (; power > 0; power /= 10)
	{
		*string++ = '0' + i / power;
		i %= power;
	}
	*string = '\0';
	printf("%s\n", string);
}
int main()
{
	int a = 587, b = 843;
	char a_1[4];
	char a_2[4];
	
	my_itoa(a, a_1);
	my_itoa(b, a_2);
	char* re=BigNumberPlus(a_1, a_2);//逆序
	return 0;
}