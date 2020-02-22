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
// 单链表的定义

SListNode* BuySListNode(SLTDataType x); // 动态申请一个节点
void SListPrint(SListNode* plist); // 单链表打印
void SListPushBack(SListNode** pplist, SLTDataType x); // 单链表尾插
void SListPushFront(SListNode** pplist, SLTDataType x); // 单链表的头插
void SListPopBack(SListNode** pplist); // 单链表的尾删
void SListPopFront(SListNode** pplist); // 单链表头删
SListNode* SListFind(SListNode* plist, SLTDataType x); // 单链表查找
void SListInsertAfter(SListNode* pos,SLTDataType x); // 单链表在pos位置之后插入x
void SListEraseAfter(SListNode* pos); // 单链表删除pos位置之后的值
void SListDestory(SListNode** pplist); // 单链表的销毁