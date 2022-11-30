#include<stdio.h>

//union un
//{
//    int i;
//    char c;
//}u;
//int main()
//{
//    ////方案1.
//    //int a = 1;//16进制数是0x00 00 00 01
//    ////将整型地址截取一个字节，只访问一个字节
//    //char* p = &a;
//    //if (*p == 1)
//    //    printf("小端");
//    //else
//    //    printf("大端");
//
//    //方案2.联合
//    u.i = 1;
//    if (u.c == 1)
//        printf("小端\n");
//    else
//        printf("大端\n");
//}

//计算枚举大小
//enum sex {
//	m,f,s
//};
//int main()
//{
//	enum sex s = m;//m就是一个整数
//	printf("%d\n", sizeof(s));//4
//	return 0;
//}
union un {
	int i;//对齐数是4
	char arr[5];//对齐数是5
}u;
int main()
{
	u.arr[0] = 'a';
	printf("%d\n", sizeof(u));//8
	return 0;
}