#include"Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d\n", QueueSize(&q));

	printf("%d\n", QueueBack(&q));

	while (QueueEmpty(&q) == 0)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestory(&q);
}

int main()
{
	TestQueue();
}