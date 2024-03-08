#include <iostream>
#include <ratio>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;

int main() {
	auto begin = std::chrono::steady_clock::now();

	 
	std::chrono::milliseconds dura(300);
	std::this_thread::sleep_for(dura);
	auto end = std::chrono::steady_clock::now();
	auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout <<"cost:" << cost << std::endl;
	return 0;
	//定义一个毫秒级时间精度类型
	typedef chrono::duration<long long, std::milli>  mill_duration;
	//定义一个秒级时间精度类型
	typedef chrono::duration<long long>  second_duration;
	//定义以system_clock和毫秒精度为计量的时间点类型
	typedef chrono::time_point<chrono::system_clock, mill_duration> milll_test_point;

	//使用system_clock，和毫秒时间精度计量，初始化当前时间点
	milll_test_point  test_point1 = chrono::time_point_cast<mill_duration>(chrono::system_clock::now());
	//1970-01-01 00:00:00到当前时间一共经历了多少毫秒；
	std::cout << test_point1.time_since_epoch().count() << " mills since epoch" << std::endl;

	//test_point1转换秒为精度计量
	std::cout << chrono::time_point_cast<second_duration, chrono::system_clock>(test_point1).time_since_epoch().count()
		<< " seconds since epoch" << std::endl;

	//chrono时间转换为c兼容的time_t时间格式
	std::time_t tt;
	tt = chrono::system_clock::to_time_t(test_point1);
	//std::cout << "test_point1 is: " << ctime(&tt);
	return 0;
}
