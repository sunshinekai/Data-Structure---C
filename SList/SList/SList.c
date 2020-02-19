#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->dada = x;
	node->next = NULL;

	return node;
}   // ��̬����һ���ڵ�

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->dada);
		cur = cur->next;
	}
	printf("NULL\n");
}   // �������ӡ

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
}   // ������β��

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
}    // �������ͷ��

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
}   // �������βɾ

void SListPopFront(SListNode** pplist)
{
	//1.��
	// 2.һ��
	// 3.����������
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
}   // ������ͷɾ
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
}   // ���������
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->next;
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}   // ��������posλ��֮�����x
    // ��pos֮ǰ����Ҫ�������Σ��ұ����ͷ��ʼ�ҵ�pos��ǰһ������
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}   // ������ɾ��posλ��֮���ֵ
    // ������֮ǰɾ��Ҫ�������Σ��ұ����ͷ��ʼ�ҵ�pos
void SListDestory(SListNode** pplist)
{
	SListNode* cur;
	while (* pplist)
	{
		cur = *pplist;
		*pplist = cur->next;
		free(cur);
	}
}   // �����������