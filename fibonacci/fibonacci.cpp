//��򵥵�һ��û���Ż�
/*

#include<iostream>
using namespace std;
int Fib(int i)
{
	if ((i == 0) || (i == 1))
	{
		return 1;
	}
	else
		return Fib(i - 1) + Fib(i - 2);
}
int main(int argc, const char * argv[])
{
	int n;
	cout << "�������������ֵ" << endl;
	cin >> n;
	int result = Fib(n - 1);
	cout << result << endl;
	cin >> n;
	return 0;
}
*/
//�޸İ�
//����2����϶�̬�滮�͵ݹ�
/*
��1�����save[n] != 0��˵��֮ǰ�Ѿ���������Ͳ��ü����ˣ��൱�ڼ��书�ܣ�ֱ�ӷ���save[n]�е�ֵ��
��2�����n == 1 || n == 0��Ϊ1��
��3������ǰ��Fabonacci��������ǰ�������ĺͣ�save[n] = f(n-1) + f(n-2);
		 
*/
#include <iostream>

int save[100];

int f(int n) {
	if (save[n] != 0) // �Ѽ����
		return save[n];
	if (n == 1 || n == 0) {
		save[n] = 1;
		return save[n];
	}
	save[n] = f(n - 1) + f(n - 2);
	return save[n];
}

int main(int argc, const char * argv[]) {
	char a = '1';
	int re = a;
	int num = atoi("123");
	int n;
	memset(save, 0, sizeof(save));

	while (std::cin >> n)
		std::cout << f(n) << std::endl;
	std::cin >> n;
	return 0;
}