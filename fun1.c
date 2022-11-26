#include<stdio.h>
//只允许字符窜前导*有n个或者小于等于n个
void fun1(char* a, int n)
{
	int i = 0;
	int k = 0;
	char* p, * t;
	p = t = a;
	while (*t == '*')
	{
		k++;//计算前导'*'个数
		t++;
	}
	if (k > n)
	{
		//1.
		/*while (*(p+k-n))//或while(*p)
		{//直接用下标为k-n后的元素覆盖原数组元素
			a[i] = *(p + k - n);
			p++;
			i++;
		}
		a[i] = '\0';*/
		//2.
		int j = k;
		i = n;
		for (j = k, i = n; a[j] != '\0'; j++)
			a[i++] = a[j];//保留前n个元素，将下标n到下标k-1之间的*删除
		a[i] = '\0';

	}
}
int main()
{
	char a[] = "*********AB**CD*****";
	printf("%s\n", a);
	fun1(a, 4);
	printf("删除后的字符窜\n");
	printf("%s", a);
	return 0;
}