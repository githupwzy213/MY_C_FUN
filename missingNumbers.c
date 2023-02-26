#include"problems.h"
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
int compare(const void* e1, const void* e2)//浮点数排序
{
	return *(int*)e1 - *(int*)e2;
}
//思路1：快速排序+查找
int missingNumbers1(int* nums, int numsSize)
{
	int i = 0;
	qsort(nums, numsSize, sizeof(int), compare);
	//快速排序复杂度N*(log以2为底N的对数）
	for (i = 0; i < numsSize; i++)
	{//执行N次
		if (nums[i] != i)
			return i;
	}
	//复杂度分析为O(N+N*(log以2为底N的对数）)
	return 0;
}
//思路2：创建数组arr[N+1]={0},将nums中的元素放入arr指定下标中，arr[i]==0时输出i
int missingNumbers2(int* nums, int numsSize)
{
	int i = 0;
	int* arr = (int*)malloc(2 * numsSize * sizeof(int));
	if (arr == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	else
	{
		for (i = 0; i < numsSize; i++)
		{
			arr[i] = numsSize + 2;
		}
		for (i = 0; i < numsSize; i++)
		{//基本操作此时执行N次
			arr[nums[i]] = nums[i];
		}
		for (i = 0; i < numsSize + 1; i++)
		{//基本操作执行N+1次
			if (arr[i] == numsSize + 2)
				return i;
		}
	}
	free(arr);
	arr = NULL;
	return 0;
}//时间复杂度为O(N)
//思路3:1+2+……n-（nums[0]+nums[1]+……nums[nmsSize-1]
int missingNumbers3(int* nums, int numsSize)
{
	int i = 0;
	int temp1 = 0;
	int temp2 = 0;
	for (i = 0; i < numsSize; i++)//n=numsSize+1
	{
		temp1 += nums[i];
	}
	for (i = 0; i <= numsSize; i++)
		temp2 += i;
	return temp2 - temp1;
}//时间复杂度为O(N)
//思路4：用x与0-n每个数字异或再与nums中每个元素异或，最后得到的结果就是缺失的值
//0^x==x,x^x==0
int missingNumbers4(int* nums, int numsSize)
{
	int i = 0;
	int x = 0;
	for (i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	for (i = 0; i <= numsSize; i++)
		x ^= i;
	return x;
}//时间复杂度为O(N)