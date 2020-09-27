#ifndef _DCLIST_H_
#define _DCLIST_H_
#include"Common.h"

//带头结点的双向循环链表
//定义节点
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;
typedef DCListNode*  DCList;
void DCListInit(DCList *phead);

void DCListPushBack(DCList *phead, ElemType x);
void  DCListShow(DCList phead);
void DCListPushFront(DCList *phead, ElemType x);
////////////////////////////////////////////////////
DCListNode * _Buynode(ElemType v = ElemType())
{
	DCListNode *_S = (DCListNode *)malloc(sizeof(DCListNode));
	assert(_S != NULL);
	_S->data = v;
	_S->next = _S->prev = _S;
	return _S;

}
void DCListInit(DCList *phead)
{
	*phead = _Buynode();
}

void DCListPushBack(DCList *phead, ElemType x)//尾插
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);
	DCListNode *head = *phead;
	s->prev = head->prev;
	s->next = head;
	s->prev->next = s;
	head->prev = s;
}
void  DCListShow(DCList phead)
{
	DCListNode *p = phead->next;
	while (p != phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
void DCListPushFront(DCList *phead, ElemType x)//头插
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);
	DCListNode *head = *phead;
	s->prev = head;
	s->next = head->next;
	s->prev->next = s;
	head->prev = s;
}
void DCListPopBack(DCList *phead)//尾删
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->next == head)
		return;
	DCListNode *p =(*phead)->prev;
	head->prev = p->prev;
	p->prev->next = head;
	free(p);

}
void DCListPopFront(DCList *phead) //头删
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	DCListNode *p= head->next;
	p->next->prev =p->prev;
	p->prev->next =p->next;
	free(p);

}
void DCListClear(DCList *phead)//清除（可以有两种）
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	DCListNode *p = head->prev;
	while (p != head)
	{
		head->prev = p->prev;
		p->prev->next = head;
		free(p);
		p = head->prev;
	}
}
DCListNode* DCListFind(DCList phead, ElemType key) //寻找
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead &&p->data != key)
		p = p->next;
	if (p->data == key)
		return p;
	else
		return NULL;

}
void DCListEraseByVal(DCList phead, ElemType key)//安置删除
{
	assert(phead != NULL);
	DCListNode *p = DCListFind(phead, key);
	if (p == NULL)
		return;
	else
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);

	}
}
void DCListInsertByVal(DCList phead, ElemType x)//按值插入
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead && x > p->data)
	{
		p = p->next;
	}
	DCListNode *s = _Buynode(x);
	s->prev = p->prev;
	s->next = p;
	s->prev->next = s;
	s->next->prev = s;
}
size_t DCListLength(DCList  phead)//长度
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	size_t size = 0;
	while (p != phead)
	{
		size++;
		p = p->next;

	}
	return size;
}
void DCListReverse(DCList phead)//倒置
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;
	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	//断开第一个节点和头结点
	p->next = phead;
	phead->prev = p;
	//进行头插
	while (q != phead)
	{
		p = q;
		q = q->next;
		p->prev = phead;
		p->next = phead->next;
		p->prev->next = p;
		p->next->prev = p;
	}

}
void DCListSort(DCList phead)//排序
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;
	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	p->next = phead;
	phead->prev = p;
	while (q != phead)
	{
		p = q;
		q = q->next;

		DCListNode *tmp = phead->next;
		while (tmp != phead && p->data>tmp->data)
			tmp = tmp->next;
		p->next = tmp;
		p->prev = tmp->prev;
		p->next->prev = p;
		p->prev->next = p;
	}
}
void SListEraseAll(DCList phead, ElemType x)//按值删除所有重复值
{

	assert(phead != NULL);
	DCListSort(phead);
	DCListNode *tmp = DCListFind(phead, x);
	DCListNode *p = tmp;
	DCListNode *q = p->next;
	while ((q != phead )&& (p->data == x))
	{
		p = q;
		q = q->next;
		//free(p);
	}
	
	if (q ==phead)
	{
		tmp->prev->next = phead;
		phead->prev = tmp->prev;

	}
	else{
		p->prev = tmp->prev;
		p->next = q;
		p->next->prev = p;
		p->prev->next = p;
	}
	


}
ElemType DCListFront(DCList phead)//表头值
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->next->data;
}
ElemType DCListBack(DCList phead)//表尾值
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->prev->data;
}
void DCListDestroy(DCList *phead)//摧毁
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;//预防野指针
}


#endif /* _DCLIST_H_ */




//void LinkQueueDE(LinkQueue *pq)
//{
//	assert(pq != NULL)
//		if (pq->head)
//	
//		LinkQueue*p = (*pq)->head;
//		p->head = p->link;
//		free(p);
//
//
//	
//}


//
//void SeqQueueEn(SeqQueue *psq, ElemType x)
//{
//
//	assert(psq !=NULL);
//	if (psq - rear >= psq->capacity
//		)
//
//	SeqQueue *p = (SeqQueue*)malloc(sizeof(SeqQueue));
//	assert(p != NULL);
//	 p->data=x;
//	psq->front->link =p;
//}
//void SeqQueueEn(SeqQueue *psq)
//{
//	assert(psq != NULL); 
//	SeqQueue *p = psq->front;
//	if (psq->front == psq->rear)
//	{
//		psq->front = psq->rear = NULL;
//	}
//	else
//	{
//		psq->head = p->next;
//		free(p);
//
//	} 
//
//
//}
//ElemType