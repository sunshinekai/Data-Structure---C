/*
1.给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
链接：https://leetcode-cn.com/problems/remove-element
*/
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}

		else
		{
			src++;
		}

	}
	return dst;
}

/*
2.给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/
int removeDuplicates(int* nums, int numsSize)
{
	int src1 = 0, src2 = 1;
	int dst = 0;

	while (src2 < numsSize)
	{
		nums[dst] = nums[src1];
		++dst;

		if (nums[src1] != nums[src2])
		{
			++src1;
			++src2;
		}

		else
		{
			while (src2 < numsSize && nums[src1] == nums[src2])
			{
				++src2;
			}
			src1 = src2;
			++src2;
		}
	}

	if (src1 < numsSize)
	{
		nums[dst] = nums[src1];
		++dst;
	}

	return dst;
}

/*
3.给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
链接：https://leetcode-cn.com/problems/merge-sorted-array
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
			nums1[end--] = nums1[end1--];

		else
			nums1[end--] = nums2[end2--];
	}
	//剩余元素依次向末尾存放
	while (end1 >= 0)
		nums1[end--] = nums1[end1--];

	while (end2 >= 0)
		nums1[end--] = nums2[end2--];
}

/*
 4.给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 链接:https://leetcode-cn.com/problems/rotate-array/
*/
void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	int temp1 = nums[(numsSize - k) % numsSize], p = 0, startp = p;
	for (int i = 0; i < numsSize; i++)
	{
		int temp2 = nums[p];
		nums[p] = temp1;
		temp1 = temp2;
		p = (p + k) % numsSize;
		if (startp == p)
		{
			p = (p + 1) % numsSize;
			startp = p;
			temp1 = nums[(p - k + numsSize) % numsSize];
		}
	}
}

/*
5.对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
*/
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		++begin;
		--end;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int* addRet = (int*)malloc(10001 * sizeof(int));
	//reti: 第i位的结果
	int reti = 0;
	//从低位开始相加
	int ai = ASize - 1;
	int next = 0; // 进位值
	while (ai >= 0 || K > 0)
	{
		int x1 = 0;
		//如果ai没有越界，还有未相加的位，取出一位存入x1
		if (ai >= 0)
		{
			x1 = A[ai];
			--ai;
		}
		int x2 = 0;
		//如果k大于0，获取k的第i位
		if (K > 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		//第i位的结果：每一位的值 + 进位
		int ret = x1 + x2 + next;
		//如果结果大于9，需要进位
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		//存入第i位的结果到数组中
		addRet[reti++] = ret;
	}
	//如果最高位有进位，需要在存入1
	if (next == 1)
	{
		addRet[reti++] = 1;
	}
	//逆置结果
	reverse(addRet, 0, reti - 1);
	*returnSize = reti;
	return addRet;
}