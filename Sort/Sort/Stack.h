#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;   //ջ��
	size_t capacity;   // ����
}Stack;   // ֧�ֶ�̬������ջ

void StackInit(Stack* pst);   // ��ʼ��ջ
void StackDestory(Stack* pst);    //ջ������
void StackPush(Stack* pst, STDataType x);   // ��ջ
void StackPop(Stack* pst);   //��ջ
STDataType StackTop(Stack* pst);   // ��ȡջ��Ԫ��
int StackEmpty(Stack* pst);   // ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
size_t StackSize(Stack* pst);   // ��ȡջ����ЧԪ�ظ���