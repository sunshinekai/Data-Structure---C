/*
1.����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
���ӣ�https://leetcode-cn.com/problems/valid-parentheses/
*/

typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;   //ջ��
	size_t capacity;   // ����
}Stack;

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   // ��ʼ��ջ

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   //ջ������

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity*sizeof(STDataType));
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}   // ��ջ

void StackPop(Stack* pst)
{
	assert(pst && pst->top > 0);
	--pst->top;
}   // ��ջ

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}   // ��ȡջ��Ԫ��

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}	// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0

size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}	// ��ȡջ����ЧԪ�ظ���

bool isValid(char * s){
	Stack st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st) == 1)
				return false;

			char top = StackTop(&st);
			StackPop(&st);
			if (*s == ']' && top == '[')
			{
				++s;
				continue;
			}

			else if (*s == ')' && top == '(')
			{
				++s;
				continue;
			}

			else if (*s == '}' && top == '{')
			{
				++s;
				continue;
			}

			else
			{
				return false;
			}
		}
	}

	bool ret = StackEmpty(&st) == 1;
	StackDestory(&st);
	return ret;
}


/*
2. �ö���ʵ��ջ
ʹ�ö���ʵ��ջ�����в�����
push(x) --Ԫ�� x ��ջ
pop() --�Ƴ�ջ��Ԫ��
top() --��ȡջ��Ԫ��
empty() --����ջ�Ƿ�Ϊ��
���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues/
*/

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
// ��ʽ�ṹ����ʾ����

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
}Queue;
// ���еĽṹ

QueueNode* BuyQueueNode(QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->back = NULL;
}	// ��ʼ������

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->back = NULL;
}	// ���ٶ���

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);

	if (pq->back == NULL)
	{
		pq->front = pq->back = newnode;
	}
	else
	{
		pq->back->next = newnode;
		pq->back = newnode;
	}
}	// ��β�����

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->back = NULL;
	}
}	// ��ͷ������

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->data;
}	// ��ȡ��ͷԪ��

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->back->data;
}	// ��ȡ��βԪ��
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL ? 1 : 0;
}	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0

size_t QueueSize(Queue* pq)
{
	assert(pq);
	size_t n = 0;
	QueueNode* cur = pq->front;

	while (cur)
	{
		++n;
		cur = cur->next;
	}
	return n;
}	// ��ȡ��������ЧԪ�ظ���

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(pst->q1));
	QueueInit(&(pst->q2));
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&(obj->q1)) == 0)
		QueuePush(&(obj->q1), x);

	else
		QueuePush(&(obj->q2), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* empty = &(obj->q1);
	Queue* noempty = &(obj->q2);
	if (QueueEmpty(&(obj->q1)) == 0)
	{
		empty = &(obj->q2);
		noempty = &(obj->q1);
	}

	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	int top = QueueFront(noempty);
	QueuePop(noempty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (QueueEmpty(&(obj->q1)) == 0)
		return QueueBack(&(obj->q1));

	else
		return QueueBack(&(obj->q2));
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->q1)) == 1 && QueueEmpty(&(obj->q2)) == 1;
}

void myStackFree(MyStack* obj) {
	QueueDestory(&(obj->q1));
	QueueDestory(&(obj->q2));
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/


/*
3.ʹ��ջʵ�ֶ��е����в�����
push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�
���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks
*/

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;   //ջ��
	size_t capacity;   // ����
}Stack;   // ֧�ֶ�̬������ջ

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   // ��ʼ��ջ

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}   //ջ������

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity*sizeof(STDataType));
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}   // ��ջ

void StackPop(Stack* pst)
{
	assert(pst && pst->top > 0);
	--pst->top;
}   // ��ջ

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}   // ��ȡջ��Ԫ��

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}   // ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0

size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}   // ��ȡջ����ЧԪ�ظ���

typedef struct {
	Stack pushst;
	Stack popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* pst = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pst->pushst);
	StackInit(&pst->popst);
	return pst;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->pushst) == 0 && StackEmpty(&obj->popst) == 1)
	{
		while (StackEmpty(&obj->pushst) == 0)
		{
			int ret = StackTop(&obj->pushst);
			StackPush(&obj->popst, ret);
			StackPop(&obj->pushst);
		}
	}
	int ret = StackTop(&obj->popst);
	StackPop(&obj->popst);
	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	int flag = 0;
	if (StackEmpty(&obj->pushst) == 0 && StackEmpty(&obj->popst) == 1)
		//pushst �ǿ� popst ��
	{
		while (StackEmpty(&obj->pushst) == 0)
		{
			flag = StackTop(&obj->pushst);
			StackPush(&obj->popst, flag);
			StackPop(&obj->pushst);
		}
		flag = StackTop(&obj->popst);
	}

	else
		flag = StackTop(&obj->popst);

	return flag;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return  StackEmpty(&(obj->pushst)) == 1
		&& StackEmpty(&(obj->popst)) == 1;
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&(obj->pushst));
	StackDestory(&(obj->popst));
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/


/*
4.������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���
ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ�
���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
���ӣ�https://leetcode-cn.com/problems/design-circular-queue
*/

typedef struct {
	int* _a;
	int _n;
	int _front;
	int _rear;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_a = (int*)malloc(sizeof(int)*(k + 1));
	cq->_n = k + 1;
	cq->_front = cq->_rear = 0;

	return cq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_a[obj->_rear] = value;
	obj->_rear++;
	if (obj->_rear == obj->_n)
		obj->_rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;

	++obj->_front;
	if (obj->_front == obj->_n)
		obj->_front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->_a[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;

	int prevRear = obj->_rear - 1;
	if (obj->_rear == 0)
		prevRear = obj->_n - 1;

	return obj->_a[prevRear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->_front == obj->_rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int nextRear = obj->_rear + 1;
	nextRear %= obj->_n;

	return nextRear == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_a);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/