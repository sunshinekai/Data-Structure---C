#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SeqlistInit(Seqlist* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}   // ˳����ʼ��

void SeqlistDestory(Seqlist* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}   // ˳�������

void SeqlistCheckcapacity(Seqlist* ps)
{
	assert(ps);
	if (ps->_size >= ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a=realloc(ps->_a,newcapacity * 2 * sizeof(SLDataType));
		ps->_capacity = newcapacity;
	}
}   // ���ռ䣬������ˣ���������

void SeqlistPrint(Seqlist* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}   // ˳����ӡ

void SeqlistPushBack(Seqlist* ps, SLDataType x)
{
	assert(ps);
	SeqlistCheckcapacity(ps);
	ps->_a[ps->_size++] = x;
	//ps->_size++;
}   // ˳���β��

void SeqlistPopBack(Seqlist* ps)
{
	assert(ps && ps->_size > 0);
	ps->_size--;
}   // ˳���βɾ

void SeqlistPushFront(Seqlist* ps, SLDataType x)
{
	assert(ps);
	//�ռ䲻��
	SeqlistCheckcapacity(ps);
	size_t end = ps->_size;
	//Ų������
	while(end > 0)
	{
		ps->_a[end] = ps->_a[end - 1];
		--end;
	}
	ps->_a[0] = x;
	ps->_size++;
}   // ˳���ͷ��

void SeqlistPopFront(Seqlist* ps)
{
	assert(ps);
	for (size_t i = 1; i < ps->_size; i++)
	{
		ps->_a[i - 1] = ps->_a[i];
	}
	ps->_size--;
}   // ˳���ͷɾ

int SeqListFind(Seqlist* ps, SLDataType x)
{
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}   // ˳������

void SeqListInsert(Seqlist* ps, size_t pos, SLDataType x)
{
	assert(ps && pos < ps->_size);
	SeqlistCheckcapacity(ps);

	size_t end = ps->_size + 1;
	while (end > pos)
	{
		ps->_a[end] = ps->_a[end - 1];
		--end;
	}

	ps->_a[pos] = x;
	ps->_size++;
}   //˳�����posλ�ò���x

void SeqListErase(Seqlist* ps, size_t pos)
{
	assert(ps && ps->_size);

	size_t i = pos + 1;
	while (i < ps->_size)
	{
		ps->_a[i - 1] = ps->_a[i];
		++i;
	}
	ps->_size--;
}   // ˳���ɾ��posλ�õ�ֵ

void SeqListRmove(Seqlist* ps, SLDataType x)
{
	int pos = SeqListFind(ps, x);
	if (pos >= 0)
	{
		SeqListErase(ps, pos);
	}
}   // ˳����ƶ�

void SeqListBubbleSort(Seqlist* ps)
{
	int flag = 0;
	for (size_t end = ps->_size; end > 0; end--)
	{
		for (size_t i = 0; i < end - 1; i++)
		{
			if (ps->_a[i] > ps->_a[i + 1])
			{
				SLDataType tmp = ps->_a[i];
				ps->_a[i] = ps->_a[i + 1];
				ps->_a[i + 1] = tmp;
				flag = 1;
			}
		}
		if (flag = 0)
		{
			break;
		}
	}
}

int SeqListBinaryFind(Seqlist* ps, SLDataType x)
{
	size_t begin = 0,
		end = ps->_size - 1;
	while (begin <= end)
	{
		size_t mid = (begin + end) / 2;
		if (ps->_a[mid] == x)
			return mid;

		else if (ps->_a[mid] < x)
			begin = mid + 1;

		else
			end = mid - 1;
	}
	return -1;
}   // ˳�����ֲ���