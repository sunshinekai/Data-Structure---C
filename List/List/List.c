#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}   // 动态申请一个节点

ListNode* ListCreateHead()
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}   //创建头节点

void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}   // 双向链表的销毁

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}   // 双向链表的打印

void ListPushPack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = pHead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
	//ListInsert(pHead, x);
}   // 双向链表的尾插

void ListPopPack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;

	tailprev->next = pHead;
	pHead->prev = tailprev;
	free(tail);
	//ListErase(pHead->prev);
}   // 双向链表的尾删


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* first = pHead->next;

	pHead->next = newnode;
	newnode->prev = pHead;
	first->prev = newnode;
	newnode->next = first;
	//ListInsert(pHead->next, x);
}   // 双向链表的头插

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* first = pHead->next;
	ListNode* firstnext = first->next;

	firstnext->prev = pHead;
	pHead->next = firstnext;
	free(first);
	//ListErase(pHead->next);
}   //双向链表的头删

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}   // 双向链表的查找

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	pos->prev = newnode;
	newnode->next = pos;
}   // 双向链表在pos的前面进行插入

void ListErase(ListNode* pos)
{ 
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	
	prev->next = next;
	next->prev = prev;
	free(pos);
}   // 双向链表删除pos位置的节点