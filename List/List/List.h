#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;   
//双向链表的定义

ListNode* BuyListNode(LTDataType x); // 动态申请一个节点
ListNode* ListCreateHead(); // 创建头节点
void ListPrint(ListNode* pHead); // 双向链表的打印
void ListDestory(ListNode* pHead); // 双向链表的销毁
void ListPushPack(ListNode* pHead, LTDataType x); // 双向链表的尾插
void ListPopPack(ListNode* pHead); // 双向链表的尾删
void ListPushFront(ListNode* pHead, LTDataType x); // 双向链表的头插
void ListPopFront(ListNode* pHead); //双向链表的头删
ListNode* ListFind(ListNode* pHead, LTDataType x); // 双向链表的查找
void ListInsert(ListNode* pos, LTDataType x); // 双向链表在pos的前面进行插入
void ListErase(ListNode* pos); // 双向链表删除pos位置的节点