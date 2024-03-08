#include <iostream>
#include <thread>
#include <future>
#include"blocking_queue.h"
int main()
{
	BlockingQueue<int>q;
	auto t1 = std::async(std::launch::async, [&q]() {
		for (int i=0;i<10;++i)
		{
			q.Put(i);
		}
	});
	auto t2 = std::async(std::launch::async, [&q]() {
		while (q.Size()) {
			std::cout << q.Take() << std::endl;
		}
	});

	auto t3 = std::async(std::launch::async, [&q]() {
		while (q.Size()) {
			std::cout << q.Take() << std::endl;
		}});


		t1.wait();
		t2.wait();
		t3.wait();
		return 0;
}
for (iter=m.begin();it!=m.end;)
{
	delete it->second;
	m.erase(iter++);
}
map<int, int>::iterator iter = i_map.find(3);
if (iter!=i_map.end())
{
	i_map.erase(iter);
}
map<int, int>::iterator iter;
for (iter=map.begin();iter!=map.end();)
{
	if (iter->first == 3)
	{
		iter->erase(iter++);
	}
	else
		iter++;

}
[caputer list](params list)mutable exception -> return type {function body}
unique_ptr<string>p1;
shared_ptr<int>p2;