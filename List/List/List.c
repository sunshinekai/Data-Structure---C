#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}   // ��̬����һ���ڵ�

ListNode* ListCreateHead()
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}   //����ͷ�ڵ�

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
}   // ˫�����������

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
}   // ˫������Ĵ�ӡ

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
}   // ˫�������β��

void ListPopPack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;

	tailprev->next = pHead;
	pHead->prev = tailprev;
	free(tail);
	//ListErase(pHead->prev);
}   // ˫�������βɾ


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
}   // ˫�������ͷ��

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* first = pHead->next;
	ListNode* firstnext = first->next;

	firstnext->prev = pHead;
	pHead->next = firstnext;
	free(first);
	//ListErase(pHead->next);
}   //˫�������ͷɾ

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
}   // ˫������Ĳ���

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	pos->prev = newnode;
	newnode->next = pos;
}   // ˫��������pos��ǰ����в���

void ListErase(ListNode* pos)
{ 
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	
	prev->next = next;
	next->prev = prev;
	free(pos);
}   // ˫������ɾ��posλ�õĽڵ�