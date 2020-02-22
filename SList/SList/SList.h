#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType dada;
	struct SListNode* next;
}SListNode;
// ������Ķ���

SListNode* BuySListNode(SLTDataType x); // ��̬����һ���ڵ�
void SListPrint(SListNode* plist); // �������ӡ
void SListPushBack(SListNode** pplist, SLTDataType x); // ������β��
void SListPushFront(SListNode** pplist, SLTDataType x); // �������ͷ��
void SListPopBack(SListNode** pplist); // �������βɾ
void SListPopFront(SListNode** pplist); // ������ͷɾ
SListNode* SListFind(SListNode* plist, SLTDataType x); // ���������
void SListInsertAfter(SListNode* pos,SLTDataType x); // ��������posλ��֮�����x
void SListEraseAfter(SListNode* pos); // ������ɾ��posλ��֮���ֵ
void SListDestory(SListNode** pplist); // �����������