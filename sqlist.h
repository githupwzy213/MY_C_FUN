
#pragma once//��ֹ�ظ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 20
typedef int SLDataType;
//��̬˳���
//typedef struct Sqlist
//{
//	SLDataType arr[N];
//	int size;//������Ԫ�ظ���
//}SL1;
//���嶯̬˳��
typedef struct Sqlist
{
	SLDataType* a;
	int size;//��¼������Ԫ�ظ���
	int capacity;//��¼��������
}SL;
//��̬˳�����ɾ�Ĳ����
void SqlistInit(SL*ps);//��ʼ��
void SqlistPrint(SL* ps);//��ӡ˳���Ԫ��
void SqlistPushBck(SL* ps,SLDataType x);//β��
void SqlistPushFront(SL* ps,SLDataType x);//ͷ��
void SqlistPopBack(SL* ps);//βɾ
void SqlistPopFront(SL* ps);//ͷɾ
void SqlistInsert(SL* ps,int pos,SLDataType x);//��ָ�������²���
void SqlistErase(SL* ps, int pos);//ɾ��ָ������Ԫ��
int SqlistFind(SL* ps,SLDataType x);//����Ԫ��
void SqlistModify(SL* ps, SLDataType sr,SLDataType ds);//����Ԫ��sr