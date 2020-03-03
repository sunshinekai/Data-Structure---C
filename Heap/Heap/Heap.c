#include"Heap.h"

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//选出较小的孩子
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}	//向下调整

void AdjustUp(HPDataType* a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}   //向上调整

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->a, a, sizeof(HPDataType)*n);
	hp->size = n;
	hp->capacity = n;

	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
}	// 堆的构建

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (size_t i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}   //堆的打印

void HeapDestory(Heap* hp)   // 堆的销毁
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->a = (HPDataType*)realloc(hp->a, sizeof(HPDataType)* hp->capacity);
	}

	hp->a[hp->size] = x;
	hp->size++;

	//向上调整
	AdjustUp(hp->a, hp->size, hp->size - 1);
}   // 堆的插入

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	--hp->size;
	AdjustDown(hp->a, hp->size, 0);
}   // 堆的删除

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}	// 取堆顶的数据

int HeapSize(Heap* hp)   // 堆的数据个数
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0 ? 1 : 0;
}   // 堆的判空

//void HeapSort(int* a, int n)
//{
//	//升序大堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n;
//	Swap(a[0], a[end]);
//	AdjustDown(a, end, 0);
//}   // 对数组进行堆排序