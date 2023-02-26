#include"problems.h"
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//思路1：
void Rotate1(int* nums, int numsSize, int k) {
	//逐个将右边k个数字移动nums[0]处
	int temp = 0;
	int i = 0;
	int j = 0;
	for (j = 0; j < k; j++)
	{
		temp = nums[numsSize - 1];
		for (i = numsSize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = temp;
	}
	
}
//思路2：
//开辟额外空间
void Rotate2(int* nums, int numsSize, int k)
{
	int i = 0;
	int* temp = (int*)malloc(numsSize * sizeof(int));
	if (temp == NULL)
	{
		printf("%s\n", strerror(errno));
	
	}
	else
	{
		for (i = 0; i < numsSize - k; i++)
		{
			temp[i + k] = nums[i];
		}
		for (i = numsSize - k; i < numsSize; i++)
		{
			temp[i - numsSize + k] = nums[i];
		}
		for (i = 0; i < numsSize; i++)
		{//将temp中元素拷贝到nums中覆盖原有顺序
			nums[i] = *(temp + i);
		}
	}
	free(temp);
	temp = NULL;
}
//思路3：逆置

void Rotate3(int* nums, int numsSize, int k)
{
	//加入k==numsSize则无需处理，当k>numsSize时只需旋转K-numsSize次
	if (k > numsSize)
		k %= numsSize;
	int left = 0;
	int right = numsSize - 1;
	int mid = numsSize - k - 1;
	int temp = 0;
	//逆置前n-k个元素
	while (left < mid)
	{
		temp = nums[left];
		nums[left] = nums[mid];
		nums[mid] = temp;
		left++;
		mid--;
	}
	//逆置后K个元素
	mid = numsSize - k;
	while (mid < right)
	{
		temp = nums[mid];
		nums[mid] = nums[right];
		nums[right] = temp;
		mid++;
		right--;
	}
	//将数组所有元素逆置一遍
	left = 0;
	right = numsSize - 1;
	while (left < right)
	{
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}