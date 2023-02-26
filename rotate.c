#include"problems.h"
//����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
//˼·1��
void Rotate1(int* nums, int numsSize, int k) {
	//������ұ�k�������ƶ�nums[0]��
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
//˼·2��
//���ٶ���ռ�
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
		{//��temp��Ԫ�ؿ�����nums�и���ԭ��˳��
			nums[i] = *(temp + i);
		}
	}
	free(temp);
	temp = NULL;
}
//˼·3������

void Rotate3(int* nums, int numsSize, int k)
{
	//����k==numsSize�����账����k>numsSizeʱֻ����תK-numsSize��
	if (k > numsSize)
		k %= numsSize;
	int left = 0;
	int right = numsSize - 1;
	int mid = numsSize - k - 1;
	int temp = 0;
	//����ǰn-k��Ԫ��
	while (left < mid)
	{
		temp = nums[left];
		nums[left] = nums[mid];
		nums[mid] = temp;
		left++;
		mid--;
	}
	//���ú�K��Ԫ��
	mid = numsSize - k;
	while (mid < right)
	{
		temp = nums[mid];
		nums[mid] = nums[right];
		nums[right] = temp;
		mid++;
		right--;
	}
	//����������Ԫ������һ��
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