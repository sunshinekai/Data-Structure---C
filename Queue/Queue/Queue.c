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
}	// ��ʼ������

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
}	// ���ٶ���
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
}	// ��β�����
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
}	// ��ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->data;
}	// ��ȡ��ͷԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->back->data;
}	// ��ȡ��βԪ��
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL ? 1 : 0;
}	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
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
}	// ��ȡ��������ЧԪ�ظ���