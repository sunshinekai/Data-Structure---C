#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// 单趟，将tmp插入[0,end]的有序区间，依旧保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}	// 插入排序

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			// 单趟排序，间距为gap的插入排序
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}

				a[end + gap] = tmp;
			}
		}
	}
}	// 希尔排序

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (end > begin)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}
		
		Swap(&a[begin], &a[mini]);

		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}	// 选择排序

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
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
}	//向下调整算法

void HeapSort(int* a, int n)
{
	//升序建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}	// 堆排序

void BubbleSort(int* a, int n)
{
	int exchange = 0;
	int end = n;
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}

		if (exchange == 0)
			break;

		--end;
	}
}	// 冒泡排序

// 快速排序递归实现

int GetMidIndex(int*a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);

	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;

		else if (a[begin] > a[end])
			return begin;

		else
			return end;
	}

	else
	{
		if (a[mid] > a[end])
			return mid;

		else if (a[begin] < a[end])
			return begin;

		else
			return end;
	}
}	//三数取中法

int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int key = begin;
	while (begin < end)
	{
		// end先走找小
		while (begin < end && a[end] >= a[key])
			--end;

		//begin再走找大
		while (begin < end && a[begin] <= a[key])
			++begin;

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[key], &a[begin]);
	return begin;
}	// 快速排序hoare版本

int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	// begin是第一个坑位
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;

		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
			++begin;

		a[end] = a[begin];
	}

	a[begin] = key;

	return begin;
}	// 快速排序挖坑法

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[end]);
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[++prev], &a[key]);

	return prev;
}	// 快速排序前后指针法

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyindex = PartSort3(a, left, right);
		// [0,keyindex-1] keyindex [keyindex,right]

		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
}	// 快速排序递归实现

void QuickSortNonR(int* a, int left, int right)
{
	
}	// 快速排序非递归实现

void MergeSort(int* a, int n);	// 归并排序递归实现
void MergeSortNonR(int* a, int n);	// 归并排序非递归实现
void CountSort(int* a, int n);	// 计数排序