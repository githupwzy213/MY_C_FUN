#include<stdio.h>
#include<string.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX 10
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
	char sex[MAX_SEX];//�Ա������Ȳ�ҪС��3�������addʱ�������ӡ�����Ԥ�ڲ�ͬ
	char tele[MAX_TELE];
	int age;
};
struct contact
{
	struct Member data[MAX];
	int size;
};
void InitContact(struct contact*);
void Add(struct contact*);
void ShowContact(struct contact*);
void DeleteContact(struct contact*);
void SearchContact(struct contact*);
void ModifyContact(struct contact*);
void SortContact(struct contact*);