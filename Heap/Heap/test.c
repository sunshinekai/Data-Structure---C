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

int main()
{
	TestHeap();
	return 0;
}