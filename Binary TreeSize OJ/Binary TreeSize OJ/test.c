/*
1.如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。
链接：https://leetcode-cn.com/problems/univalued-binary-tree/
*/

bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
		return true;

	if (root->left && root->left->val != root->val)
		return false;

	if (root->right && root->right->val != root->val)
		return false;

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}


/*
2.给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
*/

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


/*
3.翻转一棵二叉树。
链接：https://leetcode-cn.com/problems/invert-binary-tree/
*/

struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL)
		return NULL;

	struct TreeNode*tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}


/*
4.给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
链接：https://leetcode-cn.com/problems/same-tree/
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q != NULL)
		return false;

	else if (p != NULL && q == NULL)
		return false;

	else if (p == NULL && q == NULL)
		return true;

	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


/*
5.给定一个二叉树，检查它是否是镜像对称的。
链接：https://leetcode-cn.com/problems/symmetric-tree/
*/

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;

	if (left == NULL || right == NULL)
		return false;

	return left->val == right->val
		&& _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}


/*
6.给定一个二叉树，返回它的前序遍历
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
*/

int BSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return BSize(root->left)
		+ BSize(root->right) + 1;
}

void _preOrder(struct TreeNode* root, int* a, int* pi)
{
	if (root)
	{
		//前序遍历，保存当前节点的值
		a[*pi] = root->val;
		++(*pi);
		_preOrder(root->left, a, pi);
		_preOrder(root->right, a, pi);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int* array, i;
	*returnSize = BSize(root);
	array = (int*)malloc(sizeof(int)* (*returnSize));
	i = 0;
	_preOrder(root, array, &i);
	return array; 
	free(array);
}


/*
7.给定一个二叉树，返回它的中序遍历。
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/

int BSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return BSize(root->left)
		+ BSize(root->right) + 1;
}

void _inorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root)
	{
		//中序遍历，保存当前节点的值
		_inorderTraversal(root->left, a, pi);
		a[*pi] = root->val;
		++(*pi);
		_inorderTraversal(root->right, a, pi);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* array, i;
	*returnSize = BSize(root);
	array = (int*)malloc(sizeof(int)* (*returnSize));
	i = 0;
	_inorderTraversal(root, array, &i);
	return array;
	free(array);
}


/*
8.二叉树的后序遍历。
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
*/

int BSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return BSize(root->left)
		+ BSize(root->right) + 1;
}

void _postorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root)
	{
		//后序遍历，保存当前节点的值
		_postorderTraversal(root->left, a, pi);
		_postorderTraversal(root->right, a, pi);
		a[*pi] = root->val;
		++(*pi);
	}
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* array, i;
	*returnSize = BSize(root);
	array = (int*)malloc(sizeof(int)* (*returnSize));
	i = 0;
	_postorderTraversal(root, array, &i);
	return array;
	free(array);
}


/*
9.给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
链接：https://leetcode-cn.com/problems/subtree-of-another-tree/
*/

bool isSameTree(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 != NULL)
		return false;

	if (t1 != NULL && t2 == NULL)
		return false;

	if (t1 == NULL && t2 == NULL)
		return true;

	if (t1->val != t2->val)
		return false;

	return isSameTree(t1->left, t2->left)
		&& isSameTree(t1->right, t2->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (!s)
		return false;

	if (isSameTree(s, t))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}


/*
10.给定一个二叉树，判断它是否是高度平衡的二叉树。
一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
链接：https://leetcode-cn.com/problems/balanced-binary-tree/
*/

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

bool isBalanced(struct TreeNode* root){

	if (root == NULL)
		return true;

	int q1 = maxDepth(root->left);
	int q2 = maxDepth(root->right);

	return abs(q1 - q2) <= 1
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}


/*
11.编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树
（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”
表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，
输出遍历结果。
链接：https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
*/

#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode
{
	struct BTreeNode* left;
	struct BTreeNode* right;
	int val;
}BTreeNode;

BTreeNode* CreateTree(char *a, int* pindex)
{
	if (a[*pindex] == '#')
		return NULL;

	BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
	root->val = a[*pindex];

	++(*pindex);
	root->left = CreateTree(a, pindex);
	++(*pindex);
	root->right = CreateTree(a, pindex);
	return root;
}

void InOrder(BTreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	char a[100] = { 0 };
	scanf("%s", a);
	int index = 0;
	BTreeNode* root = CreateTree(a, &index);
	InOrder(root);
	return 0;
}