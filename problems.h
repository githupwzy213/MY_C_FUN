#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//����ȱʧ����
int compare(const void* e1, const void* e2);
int missingNumbers1(int* nums, int numsSize);
int missingNumbers2(int* nums, int numsSize);
int missingNumbers3(int* nums, int numsSize);
int missingNumbers4(int* nums, int numsSize);
//��ת����
void Rotate1(int* nums, int numsSize, int k);
void Rotate2(int* nums, int numsSize, int k);
void Rotate3(int* nums, int numsSize, int k);