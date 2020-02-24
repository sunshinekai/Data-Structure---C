#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
// ��ʽ�ṹ����ʾ����

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
}Queue;
// ���еĽṹ

void QueueInit(Queue* pq);	// ��ʼ������
void QueueDestory(Queue* pq);	// ���ٶ���
void QueuePush(Queue* pq, QDataType x);   // ��β�����
void QueuePop(Queue* pq);   // ��ͷ������
QDataType QueueFront(Queue* pq);   // ��ȡ��ͷԪ��
QDataType QueueBack(Queue* pq);   // ��ȡ��βԪ��
int QueueEmpty(Queue* pq);   // �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
size_t QueueSize(Queue* pq);   // ��ȡ��������ЧԪ�ظ���