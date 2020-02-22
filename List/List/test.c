#include"List.h"

void TestList()
{
	ListNode* pHead = ListCreateHead();
	ListPushPack(pHead, 1);
	ListPushPack(pHead, 2);
	ListPushPack(pHead, 3);
	ListPushPack(pHead, 4);
	ListPushPack(pHead, 5);
	ListPrint(pHead);

	ListPushFront(pHead, 0);
	ListPushFront(pHead, -1);
	ListPrint(pHead);

	ListNode* ret = ListFind(pHead, 5);
	if (ret)
	{
		ret->data = 10;
	}
	ListPrint(pHead);

	ListPopPack(pHead);
	ListPopPack(pHead);
	ListPopPack(pHead);
	ListPrint(pHead);

	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
}   // 双向链表的尾插、头插、查找替换、尾删、头删测试
int main()
{
	TestList();
	return 0;
}   