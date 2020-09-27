#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct SListNode
#pragma warning (disable:4996)
#define ElemType int
{
	ElemType data;
	struct SListNode *next;
}SListNode;
typedef SListNode* SList;
void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	SListNode *p = *phead;
	if (p == NULL)
		*phead = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}
void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
void SListRdu(SList phead)
{
	assert(phead != NULL);
	SListNode*p = phead;
	SListNode*q = p->next;
	while ((q != NULL) && (p->data != q->data))
	{
		p = q;
		q = q->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
			p = p->next;
			q = p->next;

		}
	}
}
void SListShow(SList phead)
{

	SListNode *p = phead;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
int main()
{
	SList list;
	SListInit(&list);
	SListNode *p = NULL;
	int item;

	printf("请输入要插入的数据<以-1结束>:");
	while (scanf("%d", &item), item != -1)
	{
		SListPushBack(&list, item);
	}
	SListShow(list);
	SListRdu(list);
	SListShow(list);
	system("pause");
	return 0;

}
