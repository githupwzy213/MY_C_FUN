#include"sqlist.h"

void test1()
{
	SL s = { 0 };
	//初始化顺序表
	SqlistInit(&s);
}
void test2()
{
	SL s = { 0 };
	//初始化顺序表
	SqlistInit(&s);
	//添加元素
	//1.尾插
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	//2.头插
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushFront(&s, x);

	}
	SqlistPrint(&s);
}
void test3()
{
	SL s = { 0 };
	//初始化顺序表
	SqlistInit(&s);
	//添加元素
	//1.尾插
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	//删除元素
	//1.尾删
	SqlistPopBack(&s);
	//2.头删
	SqlistPopFront(&s);
	SqlistPrint(&s);
}
//在指定下标出插入元素
void test4()
{
	SL s = { 0 };
	//初始化顺序表
	SqlistInit(&s);
	//添加元素
	//1.尾插
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	SqlistInsert(&s,2,10);
	SqlistPrint(&s);
}
//删除指定下标下的元素
//查找元素
//修改元素
void test5()
{
	SL s = { 0 };
	//初始化顺序表
	SqlistInit(&s);
	//添加元素
	//1.尾插
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	SqlistErase(&s,2);
	SqlistPrint(&s);
	printf("要查找的元素4下标为：%d\n", SqlistFind(&s, 4));
	SqlistModify(&s, 4, 5);
	SqlistPrint(&s);
}
int main()
{
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}