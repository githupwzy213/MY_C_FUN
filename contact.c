#include"contact.h"
void InitContact(struct contact*ps)
{
	 ps->data = (struct Member*)malloc(SIZE * sizeof(struct Member));
	 //动态开辟空间存放联系人信息，初始化开辟SIZE个联系人空间后续不足再扩充
	if (ps->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	memset(ps->data, '#', SIZE*sizeof(struct Member));//内存设置，将通讯录成员信息全部初始化为0
	ps->size = 0;//通讯录大小初始化为0
	ps->capicty = SIZE;//通讯录容量初始化为3
}

//退出通讯录，释放通讯录所占的内存空间
void DestroyContact(struct contact* ps)
{
	free(ps->data);
	ps->data = NULL;
	//ps不是动态开辟的不用free
}
//判断通讯录大小是否达到容量上限，当容量达到上限扩容
void CheckCapicty(struct contact* ps)
{

	if (ps->size == ps->capicty)//当通讯录达到容量
	{
		struct Member* temp = (struct Member*)realloc(ps->data, sizeof(struct Member)*(ps->capicty+2));
		//一次扩充两个容量
		if (temp == NULL)
		{
			printf("%s\n", strerror(errno));
			printf("扩容失败\n");
			return;
		}
		ps->data = temp;
		ps->capicty += 2;
		//free(temp);//此时还不能free因为temp和ps->data指的是同一块空间，如果free(temp)相当于把通讯录内存空间给释放了，后续就不能用力
		temp = NULL;
		printf("扩容成功\n");
	}
}
//添加联系人
void Add(struct contact* ps)
{
	CheckCapicty(ps);//检查通讯录容量是否不足，是否需要扩充
	if (ps->size < ps->capicty)
	{
		printf("请输入姓名：\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别：\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄：\n");
		scanf("%d", &ps->data[ps->size].age);//->和.优先级大于&
		printf("请输入电话号：\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("添加成功\n");
		ps->size++;
	}
	
}
//打印通讯录信息
void ShowContact(struct contact* ps)
{
	//打印一个题头
	printf("%-20s\t%-10s\t%-3s\t%-12s\n", "姓名", "性别", "年龄", "电话");
	int i = 0;
	for (i = 0; i < ps->size; i++)//循环打印通讯录所有联系人信息
		printf("%-20s\t%-10s\t%-3d\t%-12s\n", ps->data[i].name, ps->data[i].sex, ps->data[i].age, ps->data[i].tele);
	
}
//通过姓名查找位置找到了返回下标找不到返回-1
int FindByName(struct contact* ps, char Name[20])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(Name, ps->data[i].name) == 0)
		{
			return i;//返回联系人姓名地址
			break;
		}
	}
	if (i >= ps->size)
	{
		return -1;
	}
}

//查找联系人
void SearchContact(struct contact* ps)
{
	char Name[20] = { 0 };
	printf("请输入要查询联系人的姓名：");
	scanf("%s", Name);
	int pos = FindByName(ps, Name);
	if (pos== -1)
		printf("此联系人不存在\n");
	else
	{//找到了打印出来
		printf("%-20s\t%-10s\t%-3s\t%-12s\n", "姓名", "性别", "年龄", "电话");
		printf("%-20s\t%-10s\t%-3d\t%-12s\n", ps->data[pos].name, ps->data[pos].sex, ps->data[pos].age, ps->data[pos].tele);
	}

}
//删除通讯录联系人
void DeleteContact(struct contact* ps)
{
	char Name[20] = { 0 };
	printf("请输入要删除联系人的姓名：");
	scanf("%s", Name);
	int pos = FindByName(ps, Name);
	//判断通讯录中是否有此联系人
	if ( pos==-1)
		printf("此联系人不存在\n");
	else
	{
		int i = 0;
		for (i = pos; i < ps->size - 1; i++)
			ps->data[i] = ps->data[i + 1];
		ps->size--;
		printf("删除成功\n");
	}
	
}
//修改联系人
void ModifyContact(struct contact* ps)
{
	char Name[20] = {0};
	printf("请输入要修改的联系人姓名：");
	scanf("%s",Name);
	int pos = FindByName(ps,Name);
	if (pos == -1)
		printf("此联系人不存在\n");
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", ps->data[pos].name);
		printf("请输入性别：\n");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄：\n");
		scanf("%d", &ps->data[pos].age);//->和.优先级大于&
		printf("请输入电话号：\n");
		scanf("%s", ps->data[pos].tele);
		printf("修改成功\n");
	}
}
//通过姓名排序
void SortContact(struct contact* ps)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size;i++)
	{
		for(j=0;j<ps->size-1-i;j++)
			if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)//若名字不是升序排序则交换位置
			{
				struct Member ret = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = ret;
			}

	}
	printf("排序完成\n");
}