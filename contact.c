#include"contact.h"
void InitContact(struct contact*ps)
{
	 ps->data = (struct Member*)malloc(SIZE * sizeof(struct Member));
	 //��̬���ٿռ�����ϵ����Ϣ����ʼ������SIZE����ϵ�˿ռ��������������
	if (ps->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	memset(ps->data, '#', SIZE*sizeof(struct Member));//�ڴ����ã���ͨѶ¼��Ա��Ϣȫ����ʼ��Ϊ0
	ps->size = 0;//ͨѶ¼��С��ʼ��Ϊ0
	ps->capicty = SIZE;//ͨѶ¼������ʼ��Ϊ3
}

//�˳�ͨѶ¼���ͷ�ͨѶ¼��ռ���ڴ�ռ�
void DestroyContact(struct contact* ps)
{
	free(ps->data);
	ps->data = NULL;
	//ps���Ƕ�̬���ٵĲ���free
}
//�ж�ͨѶ¼��С�Ƿ�ﵽ�������ޣ��������ﵽ��������
void CheckCapicty(struct contact* ps)
{

	if (ps->size == ps->capicty)//��ͨѶ¼�ﵽ����
	{
		struct Member* temp = (struct Member*)realloc(ps->data, sizeof(struct Member)*(ps->capicty+2));
		//һ��������������
		if (temp == NULL)
		{
			printf("%s\n", strerror(errno));
			printf("����ʧ��\n");
			return;
		}
		ps->data = temp;
		ps->capicty += 2;
		//free(temp);//��ʱ������free��Ϊtemp��ps->dataָ����ͬһ��ռ䣬���free(temp)�൱�ڰ�ͨѶ¼�ڴ�ռ���ͷ��ˣ������Ͳ�������
		temp = NULL;
		printf("���ݳɹ�\n");
	}
}
//�����ϵ��
void Add(struct contact* ps)
{
	CheckCapicty(ps);//���ͨѶ¼�����Ƿ��㣬�Ƿ���Ҫ����
	if (ps->size < ps->capicty)
	{
		printf("������������\n");
		scanf("%s", ps->data[ps->size].name);
		printf("�������Ա�\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("���������䣺\n");
		scanf("%d", &ps->data[ps->size].age);//->��.���ȼ�����&
		printf("������绰�ţ�\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("��ӳɹ�\n");
		ps->size++;
	}
	
}
//��ӡͨѶ¼��Ϣ
void ShowContact(struct contact* ps)
{
	//��ӡһ����ͷ
	printf("%-20s\t%-10s\t%-3s\t%-12s\n", "����", "�Ա�", "����", "�绰");
	int i = 0;
	for (i = 0; i < ps->size; i++)//ѭ����ӡͨѶ¼������ϵ����Ϣ
		printf("%-20s\t%-10s\t%-3d\t%-12s\n", ps->data[i].name, ps->data[i].sex, ps->data[i].age, ps->data[i].tele);
	
}
//ͨ����������λ���ҵ��˷����±��Ҳ�������-1
int FindByName(struct contact* ps, char Name[20])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(Name, ps->data[i].name) == 0)
		{
			return i;//������ϵ��������ַ
			break;
		}
	}
	if (i >= ps->size)
	{
		return -1;
	}
}

//������ϵ��
void SearchContact(struct contact* ps)
{
	char Name[20] = { 0 };
	printf("������Ҫ��ѯ��ϵ�˵�������");
	scanf("%s", Name);
	int pos = FindByName(ps, Name);
	if (pos== -1)
		printf("����ϵ�˲�����\n");
	else
	{//�ҵ��˴�ӡ����
		printf("%-20s\t%-10s\t%-3s\t%-12s\n", "����", "�Ա�", "����", "�绰");
		printf("%-20s\t%-10s\t%-3d\t%-12s\n", ps->data[pos].name, ps->data[pos].sex, ps->data[pos].age, ps->data[pos].tele);
	}

}
//ɾ��ͨѶ¼��ϵ��
void DeleteContact(struct contact* ps)
{
	char Name[20] = { 0 };
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", Name);
	int pos = FindByName(ps, Name);
	//�ж�ͨѶ¼���Ƿ��д���ϵ��
	if ( pos==-1)
		printf("����ϵ�˲�����\n");
	else
	{
		int i = 0;
		for (i = pos; i < ps->size - 1; i++)
			ps->data[i] = ps->data[i + 1];
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
	
}
//�޸���ϵ��
void ModifyContact(struct contact* ps)
{
	char Name[20] = {0};
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s",Name);
	int pos = FindByName(ps,Name);
	if (pos == -1)
		printf("����ϵ�˲�����\n");
	else
	{
		printf("������������\n");
		scanf("%s", ps->data[pos].name);
		printf("�������Ա�\n");
		scanf("%s", ps->data[pos].sex);
		printf("���������䣺\n");
		scanf("%d", &ps->data[pos].age);//->��.���ȼ�����&
		printf("������绰�ţ�\n");
		scanf("%s", ps->data[pos].tele);
		printf("�޸ĳɹ�\n");
	}
}
//ͨ����������
void SortContact(struct contact* ps)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size;i++)
	{
		for(j=0;j<ps->size-1-i;j++)
			if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)//�����ֲ������������򽻻�λ��
			{
				struct Member ret = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = ret;
			}

	}
	printf("�������\n");
}