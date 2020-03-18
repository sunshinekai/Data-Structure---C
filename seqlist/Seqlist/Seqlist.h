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
// ˳���Ķ���

void SeqlistInit(Seqlist* ps); // ˳����ʼ��
void SeqlistDestory(Seqlist* ps); // ˳�������
void SeqlistCheckcapacity(Seqlist* ps); // ���ռ䣬������ˣ���������
void SeqlistPrint(Seqlist* ps); // ˳����ӡ
void SeqlistPushBack(Seqlist* ps, SLDataType x); // ˳���β��
void SeqlistPopBack(Seqlist* ps); // ˳���βɾ
void SeqlistPushFront(Seqlist* ps, SLDataType x); // ˳���ͷ��
void SeqlistPopFront(Seqlist* ps); // ˳���ͷɾ

int SeqListFind(Seqlist* ps, SLDataType x); // ˳������
void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x); // ˳�����posλ�ò���x
void SeqListErase(Seqlist* ps, size_t pos); // ˳���ɾ��posλ�õ�ֵ
void SeqListRmove(Seqlist* ps, SLDataType x); // ˳���ɾ������x
void SeqListBubbleSort(Seqlist* ps);  // ˳����ð������
int SeqListBinaryFind(Seqlist* ps, SLDataType x); // ˳�����ֲ���