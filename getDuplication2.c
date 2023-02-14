#include"getDuplication.h"
//创建一个辅助数组，将原数组逐个复制到辅助数组中。如果原数组元素是m则将其放到
//辅助数组下标为m的位置。这样就可以发现哪个数字是重复的了。
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