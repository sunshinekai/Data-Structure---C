#include"Stack.h"

void StackTest()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	printf("%d\n", StackEmpty(&st));

	printf("%d\n", StackSize(&st));

	while (StackEmpty(&st) == 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	printf("%d\n", StackEmpty(&st));

	printf("%d\n", StackSize(&st));

	StackDestory(&st);
	while (StackEmpty(&st) == 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

}	//ջ�ĳ�ʼ������ջ����ջ���ж�ջ�Ƿ�Ϊ�ա���ȡջ����ЧԪ�ظ����Լ�ջ�����ٲ���

int main()
{
	StackTest();
}