#include<stdio.h>
int removeElement1(int* nums, int numsSize, int val) {
    int i = 0;
    int j = 0;
    int sz = numsSize;
    while (i < numsSize)
    {
        if (nums[i] == val)
        {//������Ԫ��ǰ��
            for (j = i; j < numsSize - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            sz--;
        }
        else
        {
            i++;
        }
    }
    return sz;

}
//ʱ�临�Ӷ�O(N^2)�ռ临�Ӷ�O(1)
int removeElement2(int* nums, int numsSize, int val)
{
    int left = 0;
    int right = 0;//���ƶ�Ԫ��
    for (right = 0; right < numsSize; right++)
    {
        if (nums[right] != val)
        {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}//ʱ�临�Ӷ�O(N)�ռ临�Ӷ�O(1)
int main()
{
    int i = 0;
    int nums[] = { 1,2,3,4,5,7,5,8,10 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 5;
    int newSize= removeElement2(&nums, numsSize, val);
    for (i = 0; i < newSize; i++)
        printf("%d ", nums[i]);
    printf("newSize=:%d", newSize);
	return 0;
}