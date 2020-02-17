#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void TestSeqlist1()
{
	Seqlist s;
	SeqlistInit(&s);
	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 2);
	SeqlistPushBack(&s, 3);
	SeqlistPushBack(&s, 4);
	SeqlistPushBack(&s, 5);
	SeqlistPrint(&s);

	SeqlistPopBack(&s);
	SeqlistPopBack(&s);
	SeqlistPrint(&s);

	SeqlistPushFront(&s, 0);
	SeqlistPrint(&s);

	SeqlistPopFront(&s);
	SeqlistPrint(&s);

	printf("%d\n", SeqListFind(&s, 1));

}

void TestSeqlist2()
{
	Seqlist s;
	SeqlistInit(&s);
	SeqlistPushBack(&s, 0);
	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 2);
	SeqlistPushBack(&s, 3);
	SeqlistPushBack(&s, 4);
	SeqlistPushBack(&s, 5);

	SeqListInsert(&s, 3, 30);
	SeqlistPrint(&s);

	SeqListInsert(&s, 0, -1);
	SeqlistPrint(&s);

	SeqListErase(&s, 4);
	SeqlistPrint(&s);

	SeqListErase(&s, 0);
	SeqlistPrint(&s);

	SeqListRmove(&s, 5);
	SeqlistPrint(&s);
}

void TestSeqlist3()
{
	Seqlist s;
	SeqlistInit(&s);
	SeqlistPushBack(&s, 2);
	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 0);
	SeqlistPushBack(&s, 7);
	SeqlistPushBack(&s, 6);
	SeqlistPushBack(&s, 5);
	SeqlistPrint(&s);

	SeqListBubbleSort(&s);
	SeqlistPrint(&s);
}

int main()
{
	TestSeqlist3();
	return 0;
}