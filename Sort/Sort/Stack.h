#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;   //栈顶
	size_t capacity;   // 容量
}Stack;   // 支持动态增长的栈

void StackInit(Stack* pst);   // 初始化栈
void StackDestory(Stack* pst);    //栈的销毁
void StackPush(Stack* pst, STDataType x);   // 出栈
void StackPop(Stack* pst);   //入栈
STDataType StackTop(Stack* pst);   // 获取栈顶元素
int StackEmpty(Stack* pst);   // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
size_t StackSize(Stack* pst);   // 获取栈中有效元素个数