#include<stdio.h>
//ֻ�����ַ���ǰ��*��n������С�ڵ���n��
void fun1(char* a, int n)
{
	int i = 0;
	int k = 0;
	char* p, * t;
	p = t = a;
	while (*t == '*')
	{
		k++;//����ǰ��'*'����
		t++;
	}
	if (k > n)
	{
		//1.
		/*while (*(p+k-n))//��while(*p)
		{//ֱ�����±�Ϊk-n���Ԫ�ظ���ԭ����Ԫ��
			a[i] = *(p + k - n);
			p++;
			i++;
		}
		a[i] = '\0';*/
		//2.
		int j = k;
		i = n;
		for (j = k, i = n; a[j] != '\0'; j++)
			a[i++] = a[j];//����ǰn��Ԫ�أ����±�n���±�k-1֮���*ɾ��
		a[i] = '\0';

	}
}
int main()
{
	char a[] = "*********AB**CD*****";
	printf("%s\n", a);
	fun1(a, 4);
	printf("ɾ������ַ���\n");
	printf("%s", a);
	return 0;
}