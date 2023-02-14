#include"getDuplication.h"
int getDuplication1(const int* arr, int length)
{
	if (arr ==NULL|| length < 0)
		return -1;
	//将1-n的数字从中间分开，前一半是1-m，后一半m+1-n。
	//如果数组中1-m的数字个数超过m则在这一半区间里一定有重复的数字否则另一半一定包含重复的数字
	// 重复将包含重复的数字区间一分为二直到找到重复的数字
	//
	int left = 1;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;//int mid=((right-left)>>1)+left
		//统计数组中在左边区间范围的数字数目
		int count = countRange(arr, length, left, mid);
		//先判断left=right的情况
		if (left == right)
		{
			if (count > 1)
				return left;//返回重复数字
			else
				break;
		}
		if (count > (mid - left + 1))
			right = mid;//如果左边区间数字数目>区间范围则此区间内有重复的数字
		else
			left = mid + 1;
	}
	return 0;
}
//上述二分法查找的思路不能确定找到每一个重复的数字。该算法不能找到
// {2,3,5,4,3,2,6,7}中重复数字2
//统计数组中在左边区间范围的数字数目
int countRange(int* arr,int length,int left,int mid)
{
	if (arr == NULL)
		return 0;
	int i = 0;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (arr[i] >= left && arr[i] <= mid)
			count++;
	}
	return count;
}