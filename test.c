//��Ŀ�����޸������ҳ��ظ�������.����Ϊn+1����������������ֶ���1-n��Χ��
//��������1���а�������ظ�������
#include"getDuplication.h"
int test1()
{
	int arr1[] = {2,3,5,4,3,2,6,7};
	int length1 = sizeof(arr1)/sizeof(arr1[0]);
	//return getDuplication1(arr1, length1);
//������������
	return getDuplication2(arr1, length1);
}
//��������2���а���һ���ظ�������
int test2()
{
	int arr2[] = { 1,2,2,3,4 };
	int length2 = sizeof(arr2) / sizeof(arr2[0]);
	//return getDuplication1(arr2, length2);
	//������������
	return getDuplication2(arr2, length2);
}
//��������3���а��������ظ�������
int test3()
{
	int arr3[] = { 1,2,3,4 };
	int length3 = sizeof(arr3) / sizeof(arr3[0]);
	//return getDuplication1(arr3, length3);
	//������������
	return getDuplication2(arr3, length3);
}
//��������4����Ч������������������ָ�룩
int test4()
{
	int *arr4 = NULL;
	int length4 = sizeof(arr4) / sizeof(arr4[0]);
	//return getDuplication1(arr4, length4);
	//������������
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