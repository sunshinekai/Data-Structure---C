#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->dada = x;
	node->next = NULL;

	return node;
}   // 动态申请一个节点

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->dada);
		cur = cur->next;
	}
	printf("NULL\n");
}   // 单链表打印

void SListPushBack(SListNode** pplist, SLTDataType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
			tail = tail->next;

		tail->next = newnode;
	}
}   // 单链表尾插

void SListPushFront(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}    // 单链表的头插

void SListPopBack(SListNode** pplist)
{
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}   // 单链表的尾删

void SListPopFront(SListNode** pplist)
{
	//1.空
	// 2.一个
	// 3.两个及以上
	SListNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = first->next;
		free(first);
		*pplist = next;
	}
}   // 单链表头删
SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->dada == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}   // 单链表查找
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->next;
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}   // 单链表在pos位置之后插入x
    // 在pos之前插入要遍历两次，且必须从头开始找到pos的前一个数据
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}   // 单链表删除pos位置之后的值
    // 在数据之前删除要遍历两次，且必须从头开始找到pos
void SListDestory(SListNode** pplist)
{
	SListNode* cur;
	while (* pplist)
	{
		cur = *pplist;
		*pplist = cur->next;
		free(cur);
	}
}   // 单链表的销毁