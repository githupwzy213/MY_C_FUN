
#pragma once//防止重复包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 20
typedef int SLDataType;
//静态顺序表
//typedef struct Sqlist
//{
//	SLDataType arr[N];
//	int size;//数组中元素个数
//}SL1;
//定义动态顺序
typedef struct Sqlist
{
	SLDataType* a;
	int size;//记录数组中元素个数
	int capacity;//记录数组容量
}SL;
//动态顺序表增删改查操作
void SqlistInit(SL*ps);//初始化
void SqlistPrint(SL* ps);//打印顺序表元素
void SqlistPushBck(SL* ps,SLDataType x);//尾插
void SqlistPushFront(SL* ps,SLDataType x);//头插
void SqlistPopBack(SL* ps);//尾删
void SqlistPopFront(SL* ps);//头删
void SqlistInsert(SL* ps,int pos,SLDataType x);//在指定坐标下插入
void SqlistErase(SL* ps, int pos);//删除指定坐标元素
int SqlistFind(SL* ps,SLDataType x);//查找元素
void SqlistModify(SL* ps, SLDataType sr,SLDataType ds);//更改元素sr