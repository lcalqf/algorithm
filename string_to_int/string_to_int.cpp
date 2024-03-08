/************************************************************************/
/* atoi()������Դ��ʵ��
stringתint��ǰ�ᣬ������Ĵ���һ����������ɵĴ�

�������������Ҫ�����ǽ�һ���ַ���ת��Ϊһ�����֣����ܵ�һ�ۿ���ȥ������������һ���ܼ򵥵ĺ�����
 ������һ������Ҫ�����д���Ϳ���ʵ�ֵĺ�������ʵ����һ�����źܼ򵥣�����ʵ����������Щ��Ҫע��ĵط���
 �ܵ���˵��������5�������

1--ָ��ΪNULL
2--���ַ�����
3--�����븺�ŵĴ���
4--�������
5--��������쳣�ַ���ô����                                                                     */
/************************************************************************/
#include<iostream>  
#include<string>  
#include<limits>  
using namespace std;

bool Input = false;

/************************************************
/* �������ַ���ת���ɶ�Ӧ������
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
		//�ж����ַ��ǲ���������  
		if (*digit == '+')
		{
			digit++;
		}
		else if (*digit == '-')
		{
			IsMinus = true;
			digit++;
		}

		//�ж�ʣ�µ��ַ�  
		while (*digit != '\0')
		{
			//�ַ�����0-9֮�����Ч�ַ�  
			if (*digit >= '0' && *digit <= '9')
			{
				result = result * 10 + (*digit - '0');

				//���������������������С����С�ĸ���  
				if ((result > numeric_limits<int>::max() && !IsMinus) || (-result < numeric_limits<int>::min() && IsMinus))
				{
					result = 0;
					break;
				}

				digit++;
			}

			//������0-9֮��ķǷ��ַ�  
			else
			{
				result = 0;
				break;
			}

		}

		//���������һ���ַ���˵������Ч���룻���������  
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

