#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pindex);	// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
void BinaryTreeDestory(BTNode** root);   // ����������
int BinaryTreeSize(BTNode* root);   // �������ڵ����
int BinaryTreeLeafSize(BTNode* root);   // ������Ҷ�ӽڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);	// ��������k��ڵ����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);   // ����������ֵΪx�Ľڵ�
void BinaryTreePrevOrder(BTNode* root);   // ������ǰ�����
void BinaryTreeInOrder(BTNode* root);   // �������������
void BinaryTreePostOrder(BTNode* root);   // �������������
void BinaryTreeLevelOrder(BTNode* root);   // �������
int BinaryTreeComplete(BTNode* root);   // �ж϶������Ƿ�����ȫ������