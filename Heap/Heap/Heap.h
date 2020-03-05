#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	size_t size;
	size_t capacity;
}Heap;

void HeapCreate(Heap* hp, HPDataType* a, int n);	// 堆的构建
void HeapPrint(Heap* hp);	//堆的打印
void HeapDestory(Heap* hp);	// 堆的销毁
void HeapPush(Heap* hp, HPDataType x);	// 堆的插入
void HeapPop(Heap* hp);	// 堆的删除
HPDataType HeapTop(Heap* hp);	// 取堆顶的数据
int HeapSize(Heap* hp);	// 堆的数据个数
int HeapEmpty(Heap* hp);	// 堆的判空
void HeapSort(int* a, int n);	// 对数组进行堆排序