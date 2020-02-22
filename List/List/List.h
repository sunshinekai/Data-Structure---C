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
//˫������Ķ���

ListNode* BuyListNode(LTDataType x); // ��̬����һ���ڵ�
ListNode* ListCreateHead(); // ����ͷ�ڵ�
void ListPrint(ListNode* pHead); // ˫������Ĵ�ӡ
void ListDestory(ListNode* pHead); // ˫�����������
void ListPushPack(ListNode* pHead, LTDataType x); // ˫�������β��
void ListPopPack(ListNode* pHead); // ˫�������βɾ
void ListPushFront(ListNode* pHead, LTDataType x); // ˫�������ͷ��
void ListPopFront(ListNode* pHead); //˫�������ͷɾ
ListNode* ListFind(ListNode* pHead, LTDataType x); // ˫������Ĳ���
void ListInsert(ListNode* pos, LTDataType x); // ˫��������pos��ǰ����в���
void ListErase(ListNode* pos); // ˫������ɾ��posλ�õĽڵ�