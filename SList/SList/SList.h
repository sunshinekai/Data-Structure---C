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

SListNode* BuySListNode(SLTDataType x);
void SListPrint(SListNode* plist);
void SListPushBack(SListNode** pplist, SLTDataType x);
void SListPushFront(SListNode** pplist, SLTDataType x);
void SListPopBack(SListNode** pplist);
void SListPopFront(SListNode** pplist);
SListNode* SListFind(SListNode* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos,SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListDestory(SListNode** pplist);