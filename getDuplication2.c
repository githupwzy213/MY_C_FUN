#include"getDuplication.h"
//����һ���������飬��ԭ����������Ƶ����������С����ԭ����Ԫ����m����ŵ�
//���������±�Ϊm��λ�á������Ϳ��Է����ĸ��������ظ����ˡ�
int getDuplication2(const int* arr,const int length)
{
	if (arr == NULL)
		return -1;
	int arr1[20] = { 0 };
	int i = 0;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (arr[i] == arr1[arr[i]])
			return arr[i];
		else
			arr1[arr[i]] = arr[i];
	}
	return 0;
}