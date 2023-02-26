#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//查找缺失数字
int compare(const void* e1, const void* e2);
int missingNumbers1(int* nums, int numsSize);
int missingNumbers2(int* nums, int numsSize);
int missingNumbers3(int* nums, int numsSize);
int missingNumbers4(int* nums, int numsSize);
//旋转数组
void Rotate1(int* nums, int numsSize, int k);
void Rotate2(int* nums, int numsSize, int k);
void Rotate3(int* nums, int numsSize, int k);