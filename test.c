#include"sqlist.h"

void test1()
{
	SL s = { 0 };
	//��ʼ��˳���
	SqlistInit(&s);
}
void test2()
{
	SL s = { 0 };
	//��ʼ��˳���
	SqlistInit(&s);
	//���Ԫ��
	//1.β��
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	//2.ͷ��
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
	//��ʼ��˳���
	SqlistInit(&s);
	//���Ԫ��
	//1.β��
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	//ɾ��Ԫ��
	//1.βɾ
	SqlistPopBack(&s);
	//2.ͷɾ
	SqlistPopFront(&s);
	SqlistPrint(&s);
}
//��ָ���±������Ԫ��
void test4()
{
	SL s = { 0 };
	//��ʼ��˳���
	SqlistInit(&s);
	//���Ԫ��
	//1.β��
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	SqlistInsert(&s,2,10);
	SqlistPrint(&s);
}
//ɾ��ָ���±��µ�Ԫ��
//����Ԫ��
//�޸�Ԫ��
void test5()
{
	SL s = { 0 };
	//��ʼ��˳���
	SqlistInit(&s);
	//���Ԫ��
	//1.β��
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		SLDataType x = i;
		SqlistPushBck(&s, x);

	}
	SqlistErase(&s,2);
	SqlistPrint(&s);
	printf("Ҫ���ҵ�Ԫ��4�±�Ϊ��%d\n", SqlistFind(&s, 4));
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