#include "SList.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
}   //尾插、尾删测试
void TestSList2()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(plist);

	SListNode* ret = SListFind(plist, 3);
	if (ret)
	{
		ret->dada = 30;
	}
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 30);
	SListInsertAfter(pos, 300);
	SListPrint(plist);

	SListEraseAfter(pos);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
}   //头插、头删、查找、插入(指定位置后的值并修改)、删除(指定位置后的值)测试

void TestSList3()
{

	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);

	SListDestory(&plist);
	SListPrint(plist);

	SListDestory(&plist);
	SListPrint(plist);

}   //销毁测试
int main()
{
	TestSList3();
	return 0;
}