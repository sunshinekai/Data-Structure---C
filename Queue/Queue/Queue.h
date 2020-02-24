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
// 链式结构：表示队列

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
}Queue;
// 队列的结构

void QueueInit(Queue* pq);	// 初始化队列
void QueueDestory(Queue* pq);	// 销毁队列
void QueuePush(Queue* pq, QDataType x);   // 队尾入队列
void QueuePop(Queue* pq);   // 队头出队列
QDataType QueueFront(Queue* pq);   // 获取队头元素
QDataType QueueBack(Queue* pq);   // 获取队尾元素
int QueueEmpty(Queue* pq);   // 检测队列是否为空，如果为空返回非零结果，如果非空返回0
size_t QueueSize(Queue* pq);   // 获取队列中有效元素个数