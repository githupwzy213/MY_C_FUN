#include<stdio.h>

//union un
//{
//    int i;
//    char c;
//}u;
//int main()
//{
//    ////����1.
//    //int a = 1;//16��������0x00 00 00 01
//    ////�����͵�ַ��ȡһ���ֽڣ�ֻ����һ���ֽ�
//    //char* p = &a;
//    //if (*p == 1)
//    //    printf("С��");
//    //else
//    //    printf("���");
//
//    //����2.����
//    u.i = 1;
//    if (u.c == 1)
//        printf("С��\n");
//    else
//        printf("���\n");
//}

//����ö�ٴ�С
//enum sex {
//	m,f,s
//};
//int main()
//{
//	enum sex s = m;//m����һ������
//	printf("%d\n", sizeof(s));//4
//	return 0;
//}
union un {
	int i;//��������4
	char arr[5];//��������5
}u;
int main()
{
	u.arr[0] = 'a';
	printf("%d\n", sizeof(u));//8
	return 0;
}