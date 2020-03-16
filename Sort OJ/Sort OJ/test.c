/*
����һ���������� nums�����������������С�
���ӣ�https://leetcode-cn.com/problems/sort-an-array/
*/

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
		// ���ˣ���tmp����[0,end]���������䣬���ɱ�������
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
}	// ��������

/*
1.	// ϣ������
 void ShellSort(int* a, int n)
 {
 	int gap = n;
 	while (gap > 1)
 	{
 		gap = gap / 3 + 1;
 		for (int i = 0; i < n - gap; i++)
 		{
 			// �������򣬼��Ϊgap�Ĳ�������
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
 }
 */


/*
2.	// ������
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
 }	//���µ����㷨

 void HeapSort(int* a, int n)
 {
     	    //���򽨴��
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
 }
*/


/*
3.	// ��������ݹ�3��˼��ʵ��
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
}	//����ȡ�з�

int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int key = begin;
	while (begin < end)
	{
		// end������С
		while (begin < end && a[end] >= a[key])
			--end;

		//begin�����Ҵ�
		while (begin < end && a[begin] <= a[key])
			++begin;

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[key], &a[begin]);
	return begin;
}	// ��������hoare�汾

int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	// begin�ǵ�һ����λ
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
}	// ���������ڿӷ�

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
}	// ��������ǰ��ָ�뷨

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
		int keyindex = PartSort2(a, left, right);
		// [0,keyindex-1] keyindex [keyindex,right]

		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
}	// ��������ݹ�ʵ��
*/


/*
4.	// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	// [begin, mid][mid + 1, end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//�鲢

	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];

		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	// ������ԭ����
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);

}
*/


/*
5.	// �鲢����ǵݹ�ʵ��
void merge(int* a, int left, int mid, int right, int* tmp)
{
	// [left, mid]
	// [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];

		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}


void mergePass(int *arr, int k, int n, int *temp)
{
	int i = 0;
	//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
	while (i < n - 2 * k + 1)
	{
		merge(arr, i, i + k - 1, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	//�ϲ�����[i, n - 1]�������벿��[i, i + k - 1]�Լ�����һ���������Ұ벿��[i + k, n - 1]
	if (i < n - k)
	{
		merge(arr, i, i + k - 1, n - 1, temp);
	}
}	// k������ʾÿ��k��Ԫ�ع鲢

void MergeSortNonR(int *a, int n)
{
	int k = 1;
	int *temp = (int *)malloc(sizeof(int)* n);
	while (k < n)
	{
		mergePass(a, k, n, temp);
		k *= 2;
	}
	free(temp);
}
*/

int* sortArray(int* nums, int numsSize, int* returnSize)
{
	MergeSortNonR(nums, numsSize);
	*returnSize = numsSize;
	return nums;
}