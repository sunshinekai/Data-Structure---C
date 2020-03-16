#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   // ��ʼ��ջ

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   //ջ������

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
}   // ��ջ

void StackPop(Stack* pst)
{
	assert(pst && pst->top > 0);
	--pst->top;
}   // ��ջ

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}   // ��ȡջ��Ԫ��

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}	// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0

size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}	// ��ȡջ����ЧԪ�ظ���