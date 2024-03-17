//阻塞队列
//条件变量codition_variable的
//https://www.jianshu.com/p/c1dfa1d40f53
#include <condition_variable>
#include <list>
#include <assert.h>
template<typename T>
class BlockingQueue
{
public:
	BlockingQueue() :_mutex(), _condvar(), _queue()
	{

	}
	void Put(const T &task)
	{
		{
			std::lock_guard<std::mutex>lock(_mutex);
			_queue.push_back(task);
		}
		_condvar.notify_all();
	}
	T Take()0
	{
		std::unique_lock<std::mutex>lock(_mutex);
		//等待时线程挂起不占时间片
		_condvar.wait(lock, [this] {return !_queue.empty(); });
		assert(!_queue.empty());
		T front(_queue.front());
		_queue.pop_front();
		return front;
	}
	size_t Size() const
	{
		std::lock_guard<std::mutex>lock(_mutex);
		return _queue.size();
	}
private:
	BlockingQueue(const BlockingQueue&rhs);
	BlockingQueue&operator = (const BlockingQueue&rhs);
private:
	mutable std::mutex _mutex;
	std::condition_variable _condvar;
	std::list<T> _queue;
};