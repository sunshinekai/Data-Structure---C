/*
1.���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
���ӣ�https://leetcode-cn.com/problems/univalued-binary-tree/
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
2.����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
���ӣ�https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
3.��תһ�ö�������
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree/
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
4.������������������дһ�����������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
���ӣ�https://leetcode-cn.com/problems/same-tree/
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
5.����һ����������������Ƿ��Ǿ���ԳƵġ�
���ӣ�https://leetcode-cn.com/problems/symmetric-tree/
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
6.����һ������������������ǰ�����
���ӣ�https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
		//ǰ����������浱ǰ�ڵ��ֵ
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
7.����һ���������������������������
���ӣ�https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
		//������������浱ǰ�ڵ��ֵ
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
8.�������ĺ��������
���ӣ�https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
		//������������浱ǰ�ڵ��ֵ
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
9.���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������
s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
���ӣ�https://leetcode-cn.com/problems/subtree-of-another-tree/
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
10.����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
���ӣ�https://leetcode-cn.com/problems/balanced-binary-tree/
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
11.��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ��������
����ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#��
��ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������
������������
���ӣ�https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
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