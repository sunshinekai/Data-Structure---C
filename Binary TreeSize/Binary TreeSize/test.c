#include"Binary TreeSize.h"
#include"Queue.h"

int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int index = 0;
	BTNode* tree = BinaryTreeCreate(a, &index);

	printf("Size:%d\n", BinaryTreeSize(tree));

	printf("Leaf Size:%d\n", BinaryTreeLeafSize(tree));

	printf("K Level:%d\n", BinaryTreeLevelKSize(tree,4));

	printf("%c\n", BinaryTreeFind(tree, 65)->_data);

	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeInOrder(tree);
	printf("\n");

	BinaryTreePostOrder(tree);
	printf("\n");

	BinaryTreeLevelOrder(tree);

	printf("Tree Complete: %d\n", BinaryTreeComplete(tree));

	BinaryTreeDestory(&tree);

	printf("Leaf Size:%d\n", BinaryTreeLeafSize(tree));

	return 0;
}	
/* 二叉树的创建、节点个数、叶子节点个数、第k层节点个数、查找值为x的节点
前序、中序、后序、层序遍历、完全二叉树判断等的测试*/