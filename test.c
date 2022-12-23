#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define SQUARE(x) x*x
//#define SQUARE1(x) (x)*(x)
//#define DOUBLE(x) (x)+(x)
//#define DOUBLE1(x) ((x)+(x))
////int main()
////{
//	//printf("%d\n",SQUARE(5));//打印25
//	//printf("%d\n", SQUARE(5 + 1));//5+1*5+1=11
//	////宏定义是替换而不是传参，不是将5+1计算好再传过去而是直接用于替换x
//	//printf("%d\n", SQUARE1(5 + 1));
//	////建议#define SQUARE(x) (x)*(x) .此时SQUARE(5 + 1)=36
//
//	//printf("%d\n", 10 * DOUBLE(5));//结果不是预想的100而是550,10*5+5=55
//	//printf("%d\n", 10 * DOUBLE1(5));
//	////#define DOUBLE(x) ((x)+(x)),此时结果是100，10*((5)+(5))=100
//
//	//return 0;
////}
//
////void print1(a)
////{
////	printf("The vlalue of a is %d\n", a);
////}
//#define PRINT(x) printf("The value of " #x "is %d\n",x)
////x前面加一个#使得此处的x不会被替换，此处的x表示的是x所代表的字符窜，若x表示的是a则#x即是"a"
//#define CRT(x,y) x##y
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//print1(a);
//	//print1(b);
//	//The vlalue of a is 10
//		//The vlalue of a is 20
//	//如何实现一个函数打印两个变量，将	//The vlalue of a is 10
//		//The vlalue of a is 20改为	//The vlalue of a is 10
//		//The vlalue of b is 20
//	
//	//#作用
//	
//	//利用宏实现，将宏参数插入到字符串中
//	//printf("hello world\n");
//	//printf("hello"" world");//这两句代码是等价的，两个字符窜会自动连接在一起，都会打印hello world
//	PRINT(a);
//	PRINT(b);
//
//	//##作用：将位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符
//	printf("%d\n", CRT(10, 01));//打印1001
//	return 0;
//}

//#define MAX(x,y) (x)>(y)?(x):(y)
////函数实现求最大值
//int max(int a, int b)
//{
//	return (a > b ? a : b);
//}
////宏实现求最大值
//#define MAX(x,y) (x)>(y)?(x):(y) 
//int main()
//{
//	int a = 10;
//	int b = 11;
//	//printf("%d\n", MAX(a++, b++));//打印12
//	//printf("%d\n", a);//打印11
//	//printf("%d\n", b);//打印13
//	//和预期结果有所冲突
//	// 替换之后
//	//(a++)>(b++)?(a++):(b++)。a++先使用，10。b++先使用11，用完之后a，b各自加一，11,12.判断之后进入b++语句
//	//先使用b打印12，然后b加一，得b=13，a=11
//	printf("%d\n", max(a, b));
//	printf("%d\n", MAX(a, b));//两条语句都可以输出较大值11
//	return MAX(a, b);
//	
//}

//#define SIZEOF(type) sizeof(type)
//#define		MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int i = 0;
//	printf("%d\n", (int)SIZEOF(int));//计算整型数据所占空间大小
//	//动态开辟内存空间
//	int* p = (int*)malloc(10 * sizeof(int));//每次使用时语句都会很长，因此可以用宏替换简化语句
//	int* p1 = MALLOC(10,int);
//	if (p1== NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	for (i = 0; i < 10; i++)//此处用p或p1都可以实现动态内存的开辟
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

//条件编译
#define DEBUG 100
#define DEBUG3 100
int main()
{
#if defined(DEBUG1)
	//#ifdef DEBUG
	printf("已定义\n");
	#ifndef DEBUG1
		printf("未定义DEBUG1\n");
	#endif

	#if !defined(DEBUG2)
		printf("未定义DEBUG2\n");
	#endif
#elif defined(DEBUG3)
	printf("已定义DEBUG3\n");

#endif
	return 0;
}











