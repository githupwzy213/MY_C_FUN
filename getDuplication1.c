#include"getDuplication.h"
int getDuplication1(const int* arr, int length)
{
	if (arr ==NULL|| length < 0)
		return -1;
	//��1-n�����ִ��м�ֿ���ǰһ����1-m����һ��m+1-n��
	//���������1-m�����ָ�������m������һ��������һ�����ظ������ַ�����һ��һ�������ظ�������
	// �ظ��������ظ�����������һ��Ϊ��ֱ���ҵ��ظ�������
	//
	int left = 1;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;//int mid=((right-left)>>1)+left
		//ͳ����������������䷶Χ��������Ŀ
		int count = countRange(arr, length, left, mid);
		//���ж�left=right�����
		if (left == right)
		{
			if (count > 1)
				return left;//�����ظ�����
			else
				break;
		}
		if (count > (mid - left + 1))
			right = mid;//����������������Ŀ>���䷶Χ������������ظ�������
		else
			left = mid + 1;
	}
	return 0;
}
//�������ַ����ҵ�˼·����ȷ���ҵ�ÿһ���ظ������֡����㷨�����ҵ�
// {2,3,5,4,3,2,6,7}���ظ�����2
//ͳ����������������䷶Χ��������Ŀ
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