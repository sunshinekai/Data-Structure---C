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

void SeqlistInit(Seqlist* ps);
void SeqlistDestory(Seqlist* ps);
void SeqlistCheckcapacity(Seqlist* ps);
void SeqlistPrint(Seqlist* ps);
void SeqlistPushBack(Seqlist* ps, SLDataType x);
void SeqlistPopBack(Seqlist* ps);
void SeqlistPushFront(Seqlist* ps, SLDataType x);
void SeqlistPopFront(Seqlist* ps);

int SeqListFind(Seqlist* ps, SLDataType x);
void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x);
void SeqListErase(Seqlist* ps, size_t pos);
void SeqListRmove(Seqlist* ps, SLDataType x);
void SeqListBubbleSort(Seqlist* ps);
int SeqListBinaryFind(Seqlist* ps, SLDataType x);