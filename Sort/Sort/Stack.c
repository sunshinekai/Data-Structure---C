#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   // 初始化栈

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   //栈的销毁

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity*sizeof(STDataType));
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}   // 入栈

void StackPop(Stack* pst)
{
	assert(pst && pst->top > 0);
	--pst->top;
}   // 出栈

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}   // 获取栈顶元素

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0

size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}	// 获取栈中有效元素个数