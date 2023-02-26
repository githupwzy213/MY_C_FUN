#include"problems.h"
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
int compare(const void* e1, const void* e2)//����������
{
	return *(int*)e1 - *(int*)e2;
}
//˼·1����������+����
int missingNumbers1(int* nums, int numsSize)
{
	int i = 0;
	qsort(nums, numsSize, sizeof(int), compare);
	//���������Ӷ�N*(log��2Ϊ��N�Ķ�����
	for (i = 0; i < numsSize; i++)
	{//ִ��N��
		if (nums[i] != i)
			return i;
	}
	//���Ӷȷ���ΪO(N+N*(log��2Ϊ��N�Ķ�����)
	return 0;
}
//˼·2����������arr[N+1]={0},��nums�е�Ԫ�ط���arrָ���±��У�arr[i]==0ʱ���i
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
		{//����������ʱִ��N��
			arr[nums[i]] = nums[i];
		}
		for (i = 0; i < numsSize + 1; i++)
		{//��������ִ��N+1��
			if (arr[i] == numsSize + 2)
				return i;
		}
	}
	free(arr);
	arr = NULL;
	return 0;
}//ʱ�临�Ӷ�ΪO(N)
//˼·3:1+2+����n-��nums[0]+nums[1]+����nums[nmsSize-1]
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
}//ʱ�临�Ӷ�ΪO(N)
//˼·4����x��0-nÿ�������������nums��ÿ��Ԫ��������õ��Ľ������ȱʧ��ֵ
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
}//ʱ�临�Ӷ�ΪO(N)