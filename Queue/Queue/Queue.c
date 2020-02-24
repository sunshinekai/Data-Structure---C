#include"Queue.h"

QueueNode* BuyQueueNode(QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->back = NULL;
}	// 初始化队列

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->back = NULL;
}	// 销毁队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);

	if (pq->back == NULL)
	{
		pq->front = pq->back = newnode;
	}
	else
	{
		pq->back->next = newnode;
		pq->back = newnode;
	}
}	// 队尾入队列
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->back = NULL;
	}
}	// 队头出队列
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->data;
}	// 获取队头元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->back->data;
}	// 获取队尾元素
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL ? 1 : 0;
}	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
size_t QueueSize(Queue* pq)
{
	assert(pq);
	size_t n = 0;
	QueueNode* cur = pq->front;

	while (cur)
	{
		++n;
		cur = cur->next;
	}

	return n;
}	// 获取队列中有效元素个数