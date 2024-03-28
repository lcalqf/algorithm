#include <iostream>
#include<unordered_map>
//其实list本身就是双向链表，但是本题需要自己实现双向链表
#include <list>
using namespace  std;
//自定义双向链表结构
//双向链表的插入与删除时间复杂度都是1，但是查询需要从头到尾的遍历，时间复杂度是O(n)
//所以为了使get的时间复杂度也达到1，需要借助一个查询时间复杂度为O(1)的结构体，快速找到链表中的节点
struct DLinkedNode {
	int key, value;
	DLinkedNode* next;
	DLinkedNode* prev;
	//定义链表的构造函数
	DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
	DLinkedNode(int key, int value) :key(key), value(value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
	DLinkedNode* head;
	DLinkedNode*tail;
	int size_;
	int capacity_;
	//通过key快速找到链表中的特定节点
	unordered_map<int, DLinkedNode*> cache;

	//构造函数初始化头阵、尾指针，并指定容量和当前元素的大小
	LRUCache(int capacity) {
		//使用伪头部和伪尾部节点
		head = new DLinkedNode();
		tail = new DLinkedNode();

		head->next = tail;
		tail->prev = head;
		//指定该缓存的容量，容量是指该缓存最大可以填充的元素数量
		//size 大小指当前缓存中已经插入的元素数量
		capacity_ = capacity;
		//初始插入的元素个数size为0
		size_ = 0;
	}
	int get(int key) {

	 unordered_map<int,DLinkedNode*>::iterator iter = cache.find(key);
	 if (iter != cache.end())
	 {
		 //返回key 对应的链表节点
		 DLinkedNode* pCurrent = iter->second;
		 //返回该链表节点保存的value值
		 if (pCurrent)
		 {
			 //把经常访问的节点，移动到链表头部
			 moveToHead(iter->second);
			 return pCurrent->value;
		 }
		 return 0;
	 }

	}
	//插入元素，插入元素也是分两步
	//第一步 把元素插入到map中
	//第二步把元素插入到链表中
	//插入的过程中还要判断链表是否超过了指定的容量 capacity

	//首先看以前是否添加过该元素，如果没有添加过则创建新的链表节点
	//插入该元素，如果以前已经添加过该元素，则把更新该元素
	void put(int key, int value)
	{
	  //查看某个元素是否在map中用的是count，
	  //其实count的效率比find的效率要低一点
	  if (!cache.count(key))
	  {
		  //如果缓存map中不存在该key，需要重新创建节点并插入
		  DLinkedNode* node = new DLinkedNode(key, value);
		  //把该节点添加到哈希表中
		  cache[key] = node;
		  //添加到双向链表的头部；新插入的元素放到链表的头部
		  addToHead(node);
		  //增加链表中的元素
		  ++size_;
		  //如果当前元素已经超过缓存的容量
		  if (size_ > capacity_)
		  {
			  //超过缓存容量后，先删除链表尾部节点
			  DLinkedNode* removed = removeTail();
			  //删除该尾节点对应的哈希表中的项
			  cache.erase(removed->key);
			  //防止内存泄漏
			  delete removed;
			  --size_;
		  }
	  }
	  else //以前该key已经存在，先通过哈希表定位，再修改value，并移动到头部
	  {
		  //首先通过哈希表获得该节点，然后再修改该节点中的值
		  DLinkedNode* node = cache[key];
		  //修改该节点对应的值
		  node->value = value;
		  //该节点经常被访问了，移动到头部
		  moveToHead(node);
	  }

	}
	//把指定节点node移动到链表头部
	//分两步执行
	//第一步先把该节点删除
	//第二部把该节点移动到链表头部
	void moveToHead(DLinkedNode* node)
	{
		removeNode(node);
		addToHead(node);
	}
	//删除指定节点,超过容器容量时要删除指定节点
	void removeNode(DLinkedNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	//把指定节点放到链表头部
	//注意这个插入操作，是向前插入，即每次都是把新元素插入到头上
	//同时也意味着虚拟伪指针tail是自动向后移动的
	void addToHead(DLinkedNode* node)
	{
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	//删除尾部节点
	DLinkedNode* removeTail()
	{
		//虚拟尾指针前面一个指针就是要删除的真正的尾指针
		DLinkedNode* node = tail->prev;
		removeNode(node);
		//返回被删除的指针
		return node;
	}
};
int main()
{
	return 0;
}