//��ת��������
#include <stdio.h>
#include<stdlib.h>
typedef struct  LIST_NODE
{
	int value;
	struct  LIST_NODE *pNext;
}node;
//��ת��������
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
		pTemp = pTemp->pNext;//�����¸��ڵ�
		pNew->pNext = pPre;
		pPre = pNew;

	}
	return pPre;
}

int main()
{
	node *pHead, *pNew,*pTemp;
	int i=0, ms=0;//ms������Žڵ�ĸ���
	int x=0;

	pHead =(node*)malloc(sizeof(LIST_NODE));
	 
	pHead->value = 1;
	pHead->pNext = NULL;
	pTemp = pHead;//�ȹ���������
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








































