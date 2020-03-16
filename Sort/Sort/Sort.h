#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 100000

//����\ϣ��\ѡ��\�鲢\ð��\����\������\��������ʵ��

void PrintArray(int* a, int n);	//��������Ĵ�ӡ
void InsertSort(int* a, int n);	// ��������
void ShellSort(int* a, int n);	// ϣ������
void SelectSort(int* a, int n);	// ѡ������
void AdjustDown(int* a, int n, int root);	//���µ����㷨
void HeapSort(int* a, int n);	// ������
void BubbleSort(int* a, int n);	// ð������

// ��������ݹ�ʵ��
int PartSort1(int* a, int begin, int end);	// ��������hoare�汾
int PartSort2(int* a, int begin, int end);	// ���������ڿӷ�
int PartSort3(int* a, int begin, int end);	// ��������ǰ��ָ�뷨
void QuickSort(int* a, int left, int right);

void QuickSortNonR(int* a, int left, int right);	// ��������ǵݹ�ʵ��

void MergeSort(int* a, int n);	// �鲢����ݹ�ʵ��
void MergeSortNonR(int* a, int n);	// �鲢����ǵݹ�ʵ��
void CountSort(int* a, int n);	// ��������