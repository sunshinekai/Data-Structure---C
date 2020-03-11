#include"Queue.h"
#include"Binary TreeSize.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pindex)
{
	BTNode* root;
	if (a[*pindex] == '#')
		return NULL;

	root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pindex];

	++(*pindex);
	root->_left = BinaryTreeCreate(a, pindex);

	++(*pindex);
	root->_right = BinaryTreeCreate(a, pindex);

	return root;
}	// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

void BinaryTreeDestory(BTNode** proot)
{
	if (*proot)
	{
		BinaryTreeDestory(&(*proot)->_left);
		BinaryTreeDestory(&(*proot)->_right);
		free(*proot);
		*proot = NULL;
	}
}	// ����������

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}	// �������ڵ����

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
	if (root == NULL)
		return NULL;

	else if (root->_data == x)
		return root;

	else
	{
		BTNode* temp;
		temp = BinaryTreeFind(root->_left, x);	// ��

		if (!temp)
			return BinaryTreeFind(root->_right, x);	//��

		return temp;
	}
	return NULL;
}	// ����������ֵΪx�Ľڵ�

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}	// ������ǰ����� 

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}	// �������������

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}	// �������������

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);

		if (front->_left)
			QueuePush(&q, front->_left);

		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
}	// ������������� 

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;

		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			return -1;
			QueueDestory(&q);
		}
	}
	return 1;

}	// �ж϶������Ƿ�����ȫ������