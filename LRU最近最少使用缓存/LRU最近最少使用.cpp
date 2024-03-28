#include <iostream>
#include<unordered_map>
//��ʵlist�������˫���������Ǳ�����Ҫ�Լ�ʵ��˫������
#include <list>
using namespace  std;
//�Զ���˫������ṹ
//˫������Ĳ�����ɾ��ʱ�临�Ӷȶ���1�����ǲ�ѯ��Ҫ��ͷ��β�ı�����ʱ�临�Ӷ���O(n)
//����Ϊ��ʹget��ʱ�临�Ӷ�Ҳ�ﵽ1����Ҫ����һ����ѯʱ�临�Ӷ�ΪO(1)�Ľṹ�壬�����ҵ������еĽڵ�
struct DLinkedNode {
	int key, value;
	DLinkedNode* next;
	DLinkedNode* prev;
	//��������Ĺ��캯��
	DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
	DLinkedNode(int key, int value) :key(key), value(value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
	DLinkedNode* head;
	DLinkedNode*tail;
	int size_;
	int capacity_;
	//ͨ��key�����ҵ������е��ض��ڵ�
	unordered_map<int, DLinkedNode*> cache;

	//���캯����ʼ��ͷ��βָ�룬��ָ�������͵�ǰԪ�صĴ�С
	LRUCache(int capacity) {
		//ʹ��αͷ����αβ���ڵ�
		head = new DLinkedNode();
		tail = new DLinkedNode();

		head->next = tail;
		tail->prev = head;
		//ָ���û����������������ָ�û�������������Ԫ������
		//size ��Сָ��ǰ�������Ѿ������Ԫ������
		capacity_ = capacity;
		//��ʼ�����Ԫ�ظ���sizeΪ0
		size_ = 0;
	}
	int get(int key) {

	 unordered_map<int,DLinkedNode*>::iterator iter = cache.find(key);
	 if (iter != cache.end())
	 {
		 //����key ��Ӧ������ڵ�
		 DLinkedNode* pCurrent = iter->second;
		 //���ظ�����ڵ㱣���valueֵ
		 if (pCurrent)
		 {
			 //�Ѿ������ʵĽڵ㣬�ƶ�������ͷ��
			 moveToHead(iter->second);
			 return pCurrent->value;
		 }
		 return 0;
	 }

	}
	//����Ԫ�أ�����Ԫ��Ҳ�Ƿ�����
	//��һ�� ��Ԫ�ز��뵽map��
	//�ڶ�����Ԫ�ز��뵽������
	//����Ĺ����л�Ҫ�ж������Ƿ񳬹���ָ�������� capacity

	//���ȿ���ǰ�Ƿ���ӹ���Ԫ�أ����û����ӹ��򴴽��µ�����ڵ�
	//�����Ԫ�أ������ǰ�Ѿ���ӹ���Ԫ�أ���Ѹ��¸�Ԫ��
	void put(int key, int value)
	{
	  //�鿴ĳ��Ԫ���Ƿ���map���õ���count��
	  //��ʵcount��Ч�ʱ�find��Ч��Ҫ��һ��
	  if (!cache.count(key))
	  {
		  //�������map�в����ڸ�key����Ҫ���´����ڵ㲢����
		  DLinkedNode* node = new DLinkedNode(key, value);
		  //�Ѹýڵ���ӵ���ϣ����
		  cache[key] = node;
		  //��ӵ�˫�������ͷ�����²����Ԫ�طŵ������ͷ��
		  addToHead(node);
		  //���������е�Ԫ��
		  ++size_;
		  //�����ǰԪ���Ѿ��������������
		  if (size_ > capacity_)
		  {
			  //����������������ɾ������β���ڵ�
			  DLinkedNode* removed = removeTail();
			  //ɾ����β�ڵ��Ӧ�Ĺ�ϣ���е���
			  cache.erase(removed->key);
			  //��ֹ�ڴ�й©
			  delete removed;
			  --size_;
		  }
	  }
	  else //��ǰ��key�Ѿ����ڣ���ͨ����ϣ��λ�����޸�value�����ƶ���ͷ��
	  {
		  //����ͨ����ϣ���øýڵ㣬Ȼ�����޸ĸýڵ��е�ֵ
		  DLinkedNode* node = cache[key];
		  //�޸ĸýڵ��Ӧ��ֵ
		  node->value = value;
		  //�ýڵ㾭���������ˣ��ƶ���ͷ��
		  moveToHead(node);
	  }

	}
	//��ָ���ڵ�node�ƶ�������ͷ��
	//������ִ��
	//��һ���ȰѸýڵ�ɾ��
	//�ڶ����Ѹýڵ��ƶ�������ͷ��
	void moveToHead(DLinkedNode* node)
	{
		removeNode(node);
		addToHead(node);
	}
	//ɾ��ָ���ڵ�,������������ʱҪɾ��ָ���ڵ�
	void removeNode(DLinkedNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	//��ָ���ڵ�ŵ�����ͷ��
	//ע������������������ǰ���룬��ÿ�ζ��ǰ���Ԫ�ز��뵽ͷ��
	//ͬʱҲ��ζ������αָ��tail���Զ�����ƶ���
	void addToHead(DLinkedNode* node)
	{
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	//ɾ��β���ڵ�
	DLinkedNode* removeTail()
	{
		//����βָ��ǰ��һ��ָ�����Ҫɾ����������βָ��
		DLinkedNode* node = tail->prev;
		removeNode(node);
		//���ر�ɾ����ָ��
		return node;
	}
};
int main()
{
	return 0;
}