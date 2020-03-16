#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 100000

//插入\希尔\选择\归并\冒泡\快速\堆排序\计数排序实现

void PrintArray(int* a, int n);	//排序数组的打印
void InsertSort(int* a, int n);	// 插入排序
void ShellSort(int* a, int n);	// 希尔排序
void SelectSort(int* a, int n);	// 选择排序
void AdjustDown(int* a, int n, int root);	//向下调整算法
void HeapSort(int* a, int n);	// 堆排序
void BubbleSort(int* a, int n);	// 冒泡排序

// 快速排序递归实现
int PartSort1(int* a, int begin, int end);	// 快速排序hoare版本
int PartSort2(int* a, int begin, int end);	// 快速排序挖坑法
int PartSort3(int* a, int begin, int end);	// 快速排序前后指针法
void QuickSort(int* a, int left, int right);

void QuickSortNonR(int* a, int left, int right);	// 快速排序非递归实现

void MergeSort(int* a, int n);	// 归并排序递归实现
void MergeSortNonR(int* a, int n);	// 归并排序非递归实现
void CountSort(int* a, int n);	// 计数排序