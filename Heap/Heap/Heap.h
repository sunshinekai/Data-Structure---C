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

void HeapCreate(Heap* hp, HPDataType* a, int n);	// �ѵĹ���
void HeapPrint(Heap* hp);	//�ѵĴ�ӡ
void HeapDestory(Heap* hp);	// �ѵ�����
void HeapPush(Heap* hp, HPDataType x);	// �ѵĲ���
void HeapPop(Heap* hp);	// �ѵ�ɾ��
HPDataType HeapTop(Heap* hp);	// ȡ�Ѷ�������
int HeapSize(Heap* hp);	// �ѵ����ݸ���
int HeapEmpty(Heap* hp);	// �ѵ��п�
void HeapSort(int* a, int n);	// ��������ж�����