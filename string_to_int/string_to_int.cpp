/************************************************************************/
/* atoi()函数的源码实现
string转int的前提，你输入的串是一个个数字组成的串

　这个函数的主要功能是将一个字符串转化为一个数字，可能第一眼看上去，你会觉得这是一个很简单的函数，
 甚至是一个不需要多少行代码就可以实现的函数。其实这是一个看着很简单，但是实践起来还有些需要注意的地方。
 总的来说，有以下5种情况：

1--指针为NULL
2--空字符处理
3--正号与负号的处理
4--溢出处理
5--如果遇到异常字符怎么处理                                                                     */
/************************************************************************/
#include<iostream>  
#include<string>  
#include<limits>  
using namespace std;

bool Input = false;

/************************************************
/* 将数字字符串转换成对应的整数
/************************************************/
int strToInt(const char* str)
{
	Input = false;
	bool IsMinus = false;
	const char* digit = str;
	long result = 0;

	if (NULL == str)
	{
		std::cerr << "str is NULL" << std::endl;
	}

	else if (NULL != str)
	{
		//判断首字符是不是正负号  
		if (*digit == '+')
		{
			digit++;
		}
		else if (*digit == '-')
		{
			IsMinus = true;
			digit++;
		}

		//判断剩下的字符  
		while (*digit != '\0')
		{
			//字符处于0-9之间的有效字符  
			if (*digit >= '0' && *digit <= '9')
			{
				result = result * 10 + (*digit - '0');

				//溢出，即大于最大的正数，小于最小的负数  
				if ((result > numeric_limits<int>::max() && !IsMinus) || (-result < numeric_limits<int>::min() && IsMinus))
				{
					result = 0;
					break;
				}

				digit++;
			}

			//其他在0-9之外的非法字符  
			else
			{
				result = 0;
				break;
			}

		}

		//遍历到最后一个字符，说明是有效输入；检查正负号  
		if (*digit == '\0')
		{
			Input = true;
			if (IsMinus)
			{
				result = 0 - result;
			}
		}
	}

	return static_cast<int>(result);
}

int main()
{

	int a = strToInt("34567");
	getchar();
	return 0;
}

