
#include"contact.h"
void menu()
{
	printf("0.EXIT/1.ADD/2.DELETE/3.SEARCH/4.MODIFY/5.SHOW/6.SORT\n");
}
int main()
{
	struct contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("�����룺");
		scanf("%d", &input);
		switch (input)//���ն�����ʱ������������0-6��������ֱ������EXIT��
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
			printf("�������\n");
			break;
		}
		}
	} while (input);
	return 0;
}