#include <iostream>
#include <future>
#include <chrono>
/*
���promise�����̲߳�����set_value()��ֵ��
future�����̵߳���get�ͻ�����������set_value������ֵfuture�����߳�Ҳ���������ˡ�
*/
void Thread_Fun1(std::promise<void>& p)
{
	//Ϊ��ͻ��Ч��������ʹ�߳�����5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	int iVal = 233;
	std::cout << "��������(int)��" << iVal << "�߳�id:" << std::this_thread::get_id()<< std::endl;

	//��������iVal
	p.set_value();
}

void Thread_Fun2(std::future<void>& f)
{
	//����������ֱ���յ��������std::promise�����������
	 f.get();		//iVal = 233

	//std::cout << "�յ�����(int)��" << iVal <<"�߳�id:"<< std::this_thread::get_id()<<std::endl;
	 std::cout << "�յ�����...." << std::endl;
}

int main()
{
	double db = 30;
	float second = db / 20.f;
	float re = powf(10.0f, db / 20.0f);
	float result = isfinite((double)db);

	//����һ��std::promise����pr1���䱣���ֵ����Ϊint
	std::promise<void> pr1;
	//����һ��std::future����fu1����ͨ��std::promise��get_future()������pr1��
	std::future<void> fu1 = pr1.get_future();

	//����һ���߳�t1��������Thread_Fun1������pr1�����߳�����ִ��
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//����һ���߳�t2��������Thread_Fun2������fu1�����߳�����ִ��
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//�������߳̽���
	t1.join();
	t2.join();

	return 1;
}

