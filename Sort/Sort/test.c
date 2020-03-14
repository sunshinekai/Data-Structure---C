#include"Sort.h"

void TestInsertSort()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	PrintArray(a, n);
}

void TestShellSort()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	PrintArray(a, n);
}

void TestSelectSort()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	PrintArray(a, n);
}

void TestHeapSort()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	PrintArray(a, n);
}

void TestBubbleSort()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	PrintArray(a, n);
}

void TestPartSort1()
{
	int a[10] = { 4, 5, 8, 7, 9, 1, 6, 3, 0, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	PartSort1(a, 0, n - 1);
	PrintArray(a, n);
}
//void testop()
//{
//	srand((unsigned)time(NULL));
//	int* a1 = (int*)malloc(sizeof(int)*N);
//	int* a2 = (int*)malloc(sizeof(int)*N);
//	int* a3 = (int*)malloc(sizeof(int)*N);
//	int* a4 = (int*)malloc(sizeof(int)*N);
//	int* a5 = (int*)malloc(sizeof(int)*N);
//	int* a6 = (int*)malloc(sizeof(int)*N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//
//	}
//
//	int begin1 = clock();
//	InsertSort(a1, n);
//	int end1 = clock();
//
//	int begin2 = clock();
//	ShellSort(a2, n);
//	int end2 = clock();
//
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//}	// 测试排序的性能对比

	int main()
{
	TestPartSort1();
	return 0;
}