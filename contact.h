#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define SIZE 3
enum option
{
	EXIT,//0
	ADD,//1
	DELETE,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};

struct Member
{
	char name[MAX_NAME];
	char sex[MAX_SEX];//性别数组宽度不要小于3，否则会add时会出错，打印结果和预期不同
	char tele[MAX_TELE];
	int age;
};
struct contact
{
	struct Member *data;//通讯录结构体，
	int size;//记录联系人当前容量
	int capicty;//记录联系人最大容量
};
void InitContact(struct contact*);
void DestroyContact(struct contact*);
void CheckCapicty(struct contact*);
void Add(struct contact*);
void ShowContact(struct contact*);
void DeleteContact(struct contact*);
void SearchContact(struct contact*);
void ModifyContact(struct contact*);
void SortContact(struct contact*);