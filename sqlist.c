#include"sqlist.h"
void SqlistInit(SL*ps)//初始化
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SqlistPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("元素个数：%d 容量：%d ", ps->size, ps->capacity);
	printf("\n");
}
void SqlistPushBck(SL* ps,SLDataType x)
{
	//1.空间满了、空间不足
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if(temp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//终止程序
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
		
	}
	//2.空间足够直接插入
	ps->a[ps->size] = x;
	ps->size++;
	
	
}
void SqlistPushFront(SL* ps, SLDataType x)
{
	//判断容量是否足够
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//终止程序
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
		
	}
	//将所有元素后移一个位置
	int i = 0;
	for (i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	//将要插入的元素放到头部
	ps->a[0] = x;
	ps->size++;
	
	
}
void SqlistPopBack(SL* ps)
{
	/*if (ps->size == 0)
	{
		printf("顺序表为空，没有元素可删\n");
	}*/
//直接用断言更方便
	assert(ps->size);
	ps->size--;
}
void SqlistPopFront(SL* ps)
{
	assert(ps->size);
	//将所有元素前移
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SqlistInsert(SL* ps, int pos, SLDataType x)
{
	//判断容量是否足够
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//终止程序
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}

	}
	//将pos位置以及后面的元素后移
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
void SqlistErase(SL* ps, int pos)
{
	//判断顺序表是否为空
	assert(ps->size);
	//将pos位置后面的元素前移
	int i = 0;
	for(i=pos;i<ps->size-1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
int SqlistFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	if (i >= ps->size)
		printf("元素不存在\n");
}
void SqlistModify(SL* ps, SLDataType sr, SLDataType ds)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == sr)
			ps->a[i] = ds;
	}
	if (i > ps->size)
		printf("顺序表中不存在要修改的元素\n");
}