#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void InsertSort(int* a, int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		//���ˣ���tmp����[0,end]���������䣬���ɱ�������
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