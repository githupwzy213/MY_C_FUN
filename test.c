#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define SQUARE(x) x*x
//#define SQUARE1(x) (x)*(x)
//#define DOUBLE(x) (x)+(x)
//#define DOUBLE1(x) ((x)+(x))
////int main()
////{
//	//printf("%d\n",SQUARE(5));//��ӡ25
//	//printf("%d\n", SQUARE(5 + 1));//5+1*5+1=11
//	////�궨�����滻�����Ǵ��Σ����ǽ�5+1������ٴ���ȥ����ֱ�������滻x
//	//printf("%d\n", SQUARE1(5 + 1));
//	////����#define SQUARE(x) (x)*(x) .��ʱSQUARE(5 + 1)=36
//
//	//printf("%d\n", 10 * DOUBLE(5));//�������Ԥ���100����550,10*5+5=55
//	//printf("%d\n", 10 * DOUBLE1(5));
//	////#define DOUBLE(x) ((x)+(x)),��ʱ�����100��10*((5)+(5))=100
//
//	//return 0;
////}
//
////void print1(a)
////{
////	printf("The vlalue of a is %d\n", a);
////}
//#define PRINT(x) printf("The value of " #x "is %d\n",x)
////xǰ���һ��#ʹ�ô˴���x���ᱻ�滻���˴���x��ʾ����x��������ַ��ܣ���x��ʾ����a��#x����"a"
//#define CRT(x,y) x##y
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//print1(a);
//	//print1(b);
//	//The vlalue of a is 10
//		//The vlalue of a is 20
//	//���ʵ��һ��������ӡ������������	//The vlalue of a is 10
//		//The vlalue of a is 20��Ϊ	//The vlalue of a is 10
//		//The vlalue of b is 20
//	
//	//#����
//	
//	//���ú�ʵ�֣�����������뵽�ַ�����
//	//printf("hello world\n");
//	//printf("hello"" world");//����������ǵȼ۵ģ������ַ��ܻ��Զ�������һ�𣬶����ӡhello world
//	PRINT(a);
//	PRINT(b);
//
//	//##���ã���λ�������ߵķ��źϳ�һ�����ţ�������궨��ӷ�����ı�Ƭ�δ�����ʶ��
//	printf("%d\n", CRT(10, 01));//��ӡ1001
//	return 0;
//}

//#define MAX(x,y) (x)>(y)?(x):(y)
////����ʵ�������ֵ
//int max(int a, int b)
//{
//	return (a > b ? a : b);
//}
////��ʵ�������ֵ
//#define MAX(x,y) (x)>(y)?(x):(y) 
//int main()
//{
//	int a = 10;
//	int b = 11;
//	//printf("%d\n", MAX(a++, b++));//��ӡ12
//	//printf("%d\n", a);//��ӡ11
//	//printf("%d\n", b);//��ӡ13
//	//��Ԥ�ڽ��������ͻ
//	// �滻֮��
//	//(a++)>(b++)?(a++):(b++)��a++��ʹ�ã�10��b++��ʹ��11������֮��a��b���Լ�һ��11,12.�ж�֮�����b++���
//	//��ʹ��b��ӡ12��Ȼ��b��һ����b=13��a=11
//	printf("%d\n", max(a, b));
//	printf("%d\n", MAX(a, b));//������䶼��������ϴ�ֵ11
//	return MAX(a, b);
//	
//}

//#define SIZEOF(type) sizeof(type)
//#define		MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int i = 0;
//	printf("%d\n", (int)SIZEOF(int));//��������������ռ�ռ��С
//	//��̬�����ڴ�ռ�
//	int* p = (int*)malloc(10 * sizeof(int));//ÿ��ʹ��ʱ��䶼��ܳ�����˿����ú��滻�����
//	int* p1 = MALLOC(10,int);
//	if (p1== NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	for (i = 0; i < 10; i++)//�˴���p��p1������ʵ�ֶ�̬�ڴ�Ŀ���
//	{
//		*p1 = i;
//		printf("%d ",*p1);
//	}
//	free(p);
//	free(p1);
//	p1 = NULL;
//	p = NULL;
//	return 0;
//}

//��������
#define DEBUG 100
#define DEBUG3 100
int main()
{
#if defined(DEBUG1)
	//#ifdef DEBUG
	printf("�Ѷ���\n");
	#ifndef DEBUG1
		printf("δ����DEBUG1\n");
	#endif

	#if !defined(DEBUG2)
		printf("δ����DEBUG2\n");
	#endif
#elif defined(DEBUG3)
	printf("�Ѷ���DEBUG3\n");

#endif
	return 0;
}











