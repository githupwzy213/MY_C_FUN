//题目：不修改数组找出重复的数字.长度为n+1的数组里的所有数字都在1-n范围内
//测试用例1：中包含多个重复的数字
#include"getDuplication.h"
int test1()
{
	int arr1[] = {2,3,5,4,3,2,6,7};
	int length1 = sizeof(arr1)/sizeof(arr1[0]);
	//return getDuplication1(arr1, length1);
//创建辅助数组
	return getDuplication2(arr1, length1);
}
//测试用例2：中包含一个重复的数字
int test2()
{
	int arr2[] = { 1,2,2,3,4 };
	int length2 = sizeof(arr2) / sizeof(arr2[0]);
	//return getDuplication1(arr2, length2);
	//创建辅助数组
	return getDuplication2(arr2, length2);
}
//测试用例3：中包不包含重复的数字
int test3()
{
	int arr3[] = { 1,2,3,4 };
	int length3 = sizeof(arr3) / sizeof(arr3[0]);
	//return getDuplication1(arr3, length3);
	//创建辅助数组
	return getDuplication2(arr3, length3);
}
//测试用例4：无效输入测试用例（输入空指针）
int test4()
{
	int *arr4 = NULL;
	int length4 = sizeof(arr4) / sizeof(arr4[0]);
	//return getDuplication1(arr4, length4);
	//创建辅助数组
	return getDuplication2(arr4, length4);
}

int main()
{
	//printf("%d",test1());
	//printf("%d", test2());
	//printf("%d", test3());
	printf("%d", test4());
	return 0;
}