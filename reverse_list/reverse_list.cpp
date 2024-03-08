//反转单向链表
#include <stdio.h>
#include<stdlib.h>
typedef struct  LIST_NODE
{
	int value;
	struct  LIST_NODE *pNext;
}node;
//反转单向链表
node * ReverList(node *pHead)
{
	if (pHead==NULL)
	{
		return nullptr;
	}
	node *pTemp,*pNew;
	node*pPre = NULL;
	pTemp = pHead;
	while (pTemp!=NULL)
	{
		pNew = pTemp;
		pTemp = pTemp->pNext;//保存下个节点
		pNew->pNext = pPre;
		pPre = pNew;

	}
	return pPre;
}

int main()
{
	node *pHead, *pNew,*pTemp;
	int i=0, ms=0;//ms用来存放节点的个数
	int x=0;

	pHead =(node*)malloc(sizeof(LIST_NODE));
	 
	pHead->value = 1;
	pHead->pNext = NULL;
	pTemp = pHead;//先构建单链表
	for (int i=2;i<6;i++)
	{
		 
		pNew = (node*)malloc(sizeof(LIST_NODE));
		pNew->value = i;
		pNew->pNext = NULL;
		pTemp->pNext = pNew;

		pTemp = pNew;
	}
	pTemp = pHead;
	for (pTemp; pTemp !=NULL; pTemp =pTemp->pNext)
	{
		printf("%d\n", pTemp->value);
	}
	printf("Reverse List....\n" );
	pTemp=ReverList(pHead);
	for (pTemp; pTemp != NULL; pTemp = pTemp->pNext)
	{
		printf("%d\n", pTemp->value);
	}
 
	return 0;

}








































