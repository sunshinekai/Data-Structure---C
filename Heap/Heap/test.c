#include"Heap.h"

void TestHeap()
{
	HPDataType a[10] = { 2, 1, 5, 3, 6, 4, 8, 9, 0, 7 };
	Heap hp;
	HeapCreate(&hp, a, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPush(&hp, -1);
	HeapPrint(&hp);

	HeapPush(&hp, 0);
	HeapPrint(&hp);

	printf("%d\n", HeapEmpty(&hp));
}

void TestTopK()
{
	size_t n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}

	a[5] = 1000000 + 1;
	a[1235] = 1000000 + 2;
	a[7] = 1000000 + 3;
	a[1523] = 1000000 + 4;
	a[666] = 1000000 + 5;
	a[1536] = 1000000 + 6;
	a[7890] = 1000000 + 7;
	a[2003] = 1000000 + 8;
	a[2020] = 1000000 + 9;
	a[221] = 1000000 + 10;

	Heap hp;
	HeapCreate(&hp, a, 10);
	for (size_t i = 10; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
}   //TopKŒ Ã‚

void TestHeapSort()
{
	HPDataType a[10] = { 2, 1, 5, 3, 6, 4, 8, 9, 0, 7 };
	size_t length = sizeof(a) / sizeof(a[0]);
	HeapSort(a, length);
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	TestHeapSort();
	return 0;
}