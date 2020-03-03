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
		//ѡ����С�ĺ���
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
}	//���µ���

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
}   //���ϵ���

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->a, a, sizeof(HPDataType)*n);
	hp->size = n;
	hp->capacity = n;

	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}
}	// �ѵĹ���

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (size_t i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}   //�ѵĴ�ӡ

void HeapDestory(Heap* hp)   // �ѵ�����
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

	//���ϵ���
	AdjustUp(hp->a, hp->size, hp->size - 1);
}   // �ѵĲ���

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	--hp->size;
	AdjustDown(hp->a, hp->size, 0);
}   // �ѵ�ɾ��

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}	// ȡ�Ѷ�������

int HeapSize(Heap* hp)   // �ѵ����ݸ���
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0 ? 1 : 0;
}   // �ѵ��п�

//void HeapSort(int* a, int n)
//{
//	//������
//	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n;
//	Swap(a[0], a[end]);
//	AdjustDown(a, end, 0);
//}   // ��������ж�����