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
}   //β�塢βɾ����
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
}   //ͷ�塢ͷɾ�����ҡ�����(ָ��λ�ú��ֵ���޸�)��ɾ��(ָ��λ�ú��ֵ)����

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

}   //���ٲ���
int main()
{
	TestSList3();
	return 0;
}