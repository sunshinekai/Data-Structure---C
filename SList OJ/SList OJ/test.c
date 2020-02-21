/*
1.删除链表中等于给定值 val 的所有节点。
链接：https://leetcode-cn.com/problems/remove-linked-list-elements/description/
*/
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	ListNode* cur = head;
	ListNode* newhead = NULL;
	ListNode* newtail = NULL;

	while (cur)
	{
		//保存下一个
		ListNode* next = cur->next;

		if (cur->val == val)
		{
			free(cur);
			cur = next;
		}
		else
		{
			if (newtail == NULL)
			{
				newtail = newhead = cur;
			}

			else
			{
				newtail->next = cur;
				newtail = cur;
			}
			newtail->next = NULL;

			cur = next;
		}
	}

	return newhead;
}
/*
2.反转一个单链表。
链接：https://leetcode-cn.com/problems/reverse-linked-list/description/
*/
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	ListNode* newnode = NULL;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* curnext = cur->next;
		cur->next = newnode;
		newnode = cur;
		cur = curnext;
	}
	return newnode;
}   //解法2.建立一个新结点，进行头插
/*
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* cur = head;
	ListNode* curnext = cur->next;
	ListNode* curnextnext = curnext->next;
	head->next = NULL;
	while(curnext)
	{
		curnext->next = cur;
		cur = curnext;
		curnext = curnextnext;

		if(curnextnext)
			curnextnext = curnextnext->next;
	}
	return cur;
}   //解法1.定义三个指针进行反转
*/

/*
3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
链接：https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
*/
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}   //快慢指针问题

/*
4.输入一个链表，输出该链表中倒数第k个结点。
链接：https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
*/
typedef struct ListNode ListNode;
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		int i = 0;
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		if (pListHead == NULL || k == 0)
			return NULL;

		while (i < k)
		{
			if (fast == NULL)
				return NULL;
			fast = fast->next;
			i++;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};//快慢指针的变形问题

/*
5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
*/
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	ListNode* head = NULL, *tail = NULL;
	head = tail = (ListNode*)malloc(sizeof(ListNode));
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			tail->next = l1;
			tail = tail->next;

			l1 = l1->next;
		}

		else
		{
			tail->next = l2;
			tail = tail->next;

			l2 = l2->next;
		}
	}
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;

	ListNode* list = head->next;
	free(head);
	return list;
}
/*
6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持
原来的数据顺序不变。
链接：https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		ListNode* lessHead = (ListNode*)malloc(sizeof(ListNode));
		lessHead->next = NULL;
		ListNode* lessTail = lessHead;

		ListNode* greaterHead = (ListNode*)malloc(sizeof(ListNode));
		greaterHead->next = NULL;
		ListNode* greaterTail = greaterHead;

		ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = cur;
			}
			else
			{
				greaterTail->next = cur;
				greaterTail = cur;
			}
			cur = cur->next;
		}
		greaterTail->next = NULL;

		lessTail->next = greaterHead->next;
		ListNode* list = lessHead->next;
		free(lessHead);
		free(greaterHead);

		return list;
	}
};

/*
7.对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
链接：https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL || A->next == NULL)
			return true;
		ListNode* slow, *fast;
		slow = fast = A;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* prev = NULL, *mid = slow;
		while (mid)
		{
			ListNode* next = mid->next;
			mid->next = prev;
			prev = mid;
			mid = next;
		}
		while (A && prev)
		{
			if (A->val != prev->val)
				return false;
			A = A->next;
			prev = prev->next;
		}
		return true;
	}
};

/*
8.编写一个程序，找到两个单链表相交的起始节点。
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
*/
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;

	ListNode* pA = headA;
	ListNode* pB = headB;
	while (pA != pB)
		// 遍历两个链表
	{
		pA = (pA == NULL ? headB : pA->next);
		pB = (pB == NULL ? headA : pB->next);
	}
	return pA;
}
/*
9.给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环
链接：https://leetcode-cn.com/problems/linked-list-cycle
*/
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}// 快慢指针判断

/*
10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
*/
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			ListNode* meet = fast;
			ListNode* start = head;
			while (meet != start)
			{
				meet = meet->next;
				start = start->next;
			}
			return meet;
		}
	}
	return NULL;
}
/*
11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		// 拷贝链表，并插入到原节点的之后
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			// 插入
			cur->next = copy;
			copy->next = next;
			// 迭代
			cur = next;
		}

		// 置拷贝结点的random
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;

			if (cur->random)
				copy->random = cur->random->next;

			else
				copy->random = NULL;

			cur = copy->next;
		}
		// 解拷贝节点，链接拷贝的节点
		Node* copyHead = NULL;
		Node* copyTail = NULL;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			// copy解下来尾插
			if (copyTail == NULL)
			{
				copyHead = copyTail = copy;
			}
			else
			{
				copyTail->next = copy;
				copyTail = copy;
			}
			cur->next = next;
			cur = next;
		}
		return copyHead;
	}
};
/*12.对链表进行插入排序。
链接：https://leetcode-cn.com/problems/insertion-sort-list/
*/
typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* sortHead = (ListNode*)malloc(sizeof(ListNode));
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* curnext = cur->next;
		ListNode* sortprev = sortHead;
		ListNode* sortcur = sortHead->next;

		while (sortcur)
		{
			if (cur->val > sortcur->val)
			{
				sortprev = sortcur;
				sortcur = sortcur->next;
			}
			else
			{
				break;
			}
		}
		//在合适位置进行插入
		sortprev->next = cur;
		cur->next = sortcur;
		cur = curnext;
	}
	ListNode* sortList = sortHead->next;
	free(sortHead);
	return sortList;
}
/*
13.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
链接：https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* cur = pHead, *prev = NULL;
		ListNode* next = cur->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				while (next && next->val == cur->val)
					next = next->next;

				if (prev)
					prev->next = next;
				else
					pHead = next;

				while (cur != next)
				{
					ListNode* curnext = cur->next;
					free(cur);
					cur = curnext;
				}

				cur = next;
				if (next)
					next = next->next;
			}
		}
		return pHead;
	}
};