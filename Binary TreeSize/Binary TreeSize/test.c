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

	BinaryTreeLevelOrder(tree);

	printf("Tree Complete: %d\n",BinaryTreeComplete(tree));

	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeInOrder(tree);
	printf("\n");

	BinaryTreePostOrder(tree);
	printf("\n");

	printf("%d\n", BinaryTreeFind(tree, 10));
	
	BinaryTreeDestory(&tree);

	printf("Leaf Size:%d\n", BinaryTreeLeafSize(tree));

	return 0;

}