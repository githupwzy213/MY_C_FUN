#include"sqlist.h"
void SqlistInit(SL*ps)//��ʼ��
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
	printf("Ԫ�ظ�����%d ������%d ", ps->size, ps->capacity);
	printf("\n");
}
void SqlistPushBck(SL* ps,SLDataType x)
{
	//1.�ռ����ˡ��ռ䲻��
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if(temp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);//��ֹ����
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
		
	}
	//2.�ռ��㹻ֱ�Ӳ���
	ps->a[ps->size] = x;
	ps->size++;
	
	
}
void SqlistPushFront(SL* ps, SLDataType x)
{
	//�ж������Ƿ��㹻
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//��ֹ����
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
		
	}
	//������Ԫ�غ���һ��λ��
	int i = 0;
	for (i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	//��Ҫ�����Ԫ�طŵ�ͷ��
	ps->a[0] = x;
	ps->size++;
	
	
}
void SqlistPopBack(SL* ps)
{
	/*if (ps->size == 0)
	{
		printf("˳���Ϊ�գ�û��Ԫ�ؿ�ɾ\n");
	}*/
//ֱ���ö��Ը�����
	assert(ps->size);
	ps->size--;
}
void SqlistPopFront(SL* ps)
{
	assert(ps->size);
	//������Ԫ��ǰ��
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SqlistInsert(SL* ps, int pos, SLDataType x)
{
	//�ж������Ƿ��㹻
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//��ֹ����
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}

	}
	//��posλ���Լ������Ԫ�غ���
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
	//�ж�˳����Ƿ�Ϊ��
	assert(ps->size);
	//��posλ�ú����Ԫ��ǰ��
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
		printf("Ԫ�ز�����\n");
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
		printf("˳����в�����Ҫ�޸ĵ�Ԫ��\n");
}