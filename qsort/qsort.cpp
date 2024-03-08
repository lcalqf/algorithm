//#include <stdio.h>
//int qsort(int a[], int len)
//{
//	int length = len;
//	int i = 0;
//	int j = len - 1;
//	int temp=a[0];
//	if (len>1)//����С��ʱ���ñȽ��ˣ���Ȼ��������ѭ��
//	{
//		while (i != j)
//		{
//			int temp = a[i];
//			for (j; i < j; j--)
//			{
//				if (a[j] < temp)
//				{
//					a[i] = a[j];
//					break;
//				}
//			}
//			for (i; i < j; i++)
//			{
//				if (a[i] > temp)
//				{
//					a[j] = a[i];
//					
//					break;
//				}
//			}
//			a[i] = temp;
//		}
//		qsort(a, i);
//		qsort(a + i + 1, len - i - 1);
//	}
//	
//	
//	return 0;
//}
//int main()
//{
//	int array[] = { 4,7,2,6,1,9,5,8,10 };
//	int len = sizeof(array) / sizeof(array[0]);
//	int re = qsort(array, len);
//	for (int i=0;i<len;i++)
//	{
//		printf("%d\n", array[i]);
//	}
//	getchar();
//	return 0;
//}


/*****************************************************
File name��Quicksort
Author��Zhengqijun    Version:1.0    Date: 2016/11/04
Description: ��������п�������
Funcion List: ʵ�ֿ��������㷨
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <winsock2.h>
using namespace std;
#define BUF_SIZE 10

/**************************************************
*��������display
*���ã���ӡ����Ԫ��
*������array - ��ӡ�����飬maxlen - ����Ԫ�ظ���
*����ֵ����
**************************************************/
void display(int array[], int maxlen)
{
	int i;

	for (i = 0; i < maxlen; i++)
	{
		printf("%-3d", array[i]);
	}
	printf("\n");

	return;
}

/********************************
*��������swap
*���ã�������������ֵ
*������������������
*����ֵ����
********************************/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

//��������  ��׼ֵ��λ��һֱû�б�
void quick_sort_2(int s[], int left, int rigth)
{
	static int index = 1;
	if (left < rigth)
	{
	
		int i = left, j = rigth, x = s[left];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		//�˳�ʱ��i����j����x�������С�  ��һ�α�����󣬴�ʱi=j���ѻ�׼ֵ�ŵ���λ�á�
		s[i] = x;
// 		cout << "�� :" << index << "��while���" << endl;
// 		index++;
// 		display(s, r+1);
// 		cout << endl;
		quick_sort_2(s, left, i - 1); // �ݹ����   
		quick_sort_2(s, i + 1, rigth);
	}
}
#pragma comment(lib,"ws2_32.lib")
// ������
int main()
{
// 	in_addr in_addr_;
// 	in_addr_.S_un.S_addr = 2886748295;
// 	std::string ip_str = inet_ntoa(in_addr_);
	//strcpy(addr, ipaddr);

	 
// 	char* s("12");
// 	char sum[10];
// 	sum[0] =  '0'+1;
// 	printf("%s", s);
// 	int n;
//	int array[BUF_SIZE] = { 12,85,25,16,34,23,49,95,17,61 };
	int array[8] = { 9,3,7,4,1,13,5,10 };
	int maxlen = 8;

	printf("����ǰ������\n");
	display(array, maxlen);

	quick_sort_2(array,  0, maxlen-1 );  // ��������

	printf("����������\n");
	display(array, maxlen);
	getchar();
	return 0;
}