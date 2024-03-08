#include <iostream>
#include <future>
#include <chrono>
/*
如果promise所在线程不调用set_value()传值，
future所在线程调用get就会阻塞，哪怕set_value传个空值future所在线程也不会阻塞了。
*/
void Thread_Fun1(std::promise<void>& p)
{
	//为了突出效果，可以使线程休眠5s
	std::this_thread::sleep_for(std::chrono::seconds(5));

	int iVal = 233;
	std::cout << "传入数据(int)：" << iVal << "线程id:" << std::this_thread::get_id()<< std::endl;

	//传入数据iVal
	p.set_value();
}

void Thread_Fun2(std::future<void>& f)
{
	//阻塞函数，直到收到相关联的std::promise对象传入的数据
	 f.get();		//iVal = 233

	//std::cout << "收到数据(int)：" << iVal <<"线程id:"<< std::this_thread::get_id()<<std::endl;
	 std::cout << "收到数据...." << std::endl;
}

int main()
{
	double db = 30;
	float second = db / 20.f;
	float re = powf(10.0f, db / 20.0f);
	float result = isfinite((double)db);

	//声明一个std::promise对象pr1，其保存的值类型为int
	std::promise<void> pr1;
	//声明一个std::future对象fu1，并通过std::promise的get_future()函数与pr1绑定
	std::future<void> fu1 = pr1.get_future();

	//创建一个线程t1，将函数Thread_Fun1及对象pr1放在线程里面执行
	std::thread t1(Thread_Fun1, std::ref(pr1));
	//创建一个线程t2，将函数Thread_Fun2及对象fu1放在线程里面执行
	std::thread t2(Thread_Fun2, std::ref(fu1));

	//阻塞至线程结束
	t1.join();
	t2.join();

	return 1;
}

