#include"problems.h"
int main()
{
	int k = 13;
	int i = 0;
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	int sz= sizeof(nums) / sizeof(nums[0]);
	/*printf("%d\n", missingNumbers1(nums, sz));
	printf("%d\n", missingNumbers2(nums, sz));
	printf("%d\n", missingNumbers3(nums, sz));*/
	//printf("%d\n", missingNumbers4(nums, sz));
	//Rotate1(nums, sz, k);
	//Rotate2(nums, sz, k);
	Rotate3(nums, sz, k);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", nums[i]);
	}
}