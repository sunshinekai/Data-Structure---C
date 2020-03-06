#include"Binary TreeSize.h"

BTNode* CreateTree(BTDataType* a, int* pindex)
{
	if (a[*pindex] == '#')
		return NULL;

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pindex];

	++(*pindex);
	root->_left = CreateTree(a, pindex);
	++(*pindex);
	root->_right = CreateTree(a, pindex);
	return root;
}	// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

int BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeDestory(root->_left) + BinaryTreeDestory(root->_right) + 1;
}	// ���������� 

int BinaryTreeSize(BTNode* root);   // �������ڵ����

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}	// ������Ҷ�ӽڵ����

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}	// ��������k��ڵ����

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	// ����������ֵΪx�Ľڵ�
}

void BinaryTreePrevOrder(BTNode* root)
{

}	// ������ǰ����� 

void BinaryTreeInOrder(BTNode* root)
{

}	// �������������

void BinaryTreePostOrder(BTNode* root)
{


}	// �������������
void BinaryTreeLevelOrder(BTNode* root)
{

}	// ������� 

int BinaryTreeComplete(BTNode* root)
{
	
}// �ж϶������Ƿ�����ȫ������
