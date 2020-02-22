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
	printf("%d\n", SeqListBinaryFind(&s, 1));
}   //顺序表的初始化、尾插、尾删、头插、头删、查找、二分查找测试

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

	SeqListRmove(&s, 1);
	SeqlistPrint(&s);
}   //顺序表任意位置(前)插入及删除、删除数据测试

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
}   //顺序表(冒泡)排序测试

int main()
{
	TestSeqlist1();
	return 0;
}