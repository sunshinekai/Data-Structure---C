#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* _a;
	size_t _size;
	size_t _capacity;
}Seqlist;
// 顺序表的定义

void SeqlistInit(Seqlist* ps); // 顺序表初始化
void SeqlistDestory(Seqlist* ps); // 顺序表销毁
void SeqlistCheckcapacity(Seqlist* ps); // 检查空间，如果满了，进行增容
void SeqlistPrint(Seqlist* ps); // 顺序表打印
void SeqlistPushBack(Seqlist* ps, SLDataType x); // 顺序表尾插
void SeqlistPopBack(Seqlist* ps); // 顺序表尾删
void SeqlistPushFront(Seqlist* ps, SLDataType x); // 顺序表头插
void SeqlistPopFront(Seqlist* ps); // 顺序表头删

int SeqListFind(Seqlist* ps, SLDataType x); // 顺序表查找
void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x); // 顺序表在pos位置插入x
void SeqListErase(Seqlist* ps, size_t pos); // 顺序表删除pos位置的值
void SeqListRmove(Seqlist* ps, SLDataType x); // 顺序表删除数据x
void SeqListBubbleSort(Seqlist* ps);  // 顺序表的冒泡排序
int SeqListBinaryFind(Seqlist* ps, SLDataType x); // 顺序表二分查找