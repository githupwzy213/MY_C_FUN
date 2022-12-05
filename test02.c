
#include"contact.h"
void menu()
{
	printf("0.EXIT/1.ADD/2.DELETE/3.SEARCH/4.MODIFY/5.SHOW/6.SORT\n");
}
int main()
{
	struct contact con;
	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请输入：");
		scanf("%d", &input);
		switch (input)//在终端输入时必须输入整数0-6，不可以直接输入EXIT等
		{
		case  EXIT:
			break;
		case ADD:
		{
			Add(&con);
			break;
		}
		case DELETE:
		{
			
			DeleteContact(&con);
			break;
		}
		case SEARCH:
		{
			
			SearchContact(&con);
			break;
		}
		case MODIFY:
		{
			ModifyContact(&con);
			break;
		}
		case SHOW:
		{
			ShowContact(&con);
		}
		case SORT:
		{
			SortContact(&con);
			break;
		}
		default:
		{
			printf("输入错误\n");
			break;
		}
		}
	} while (input);
	return 0;
}