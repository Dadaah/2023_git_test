#include <stdio.h>

void ArrPrintf(int arg[]);

int main(void)
{
	int arr[3] = { 1, 2, 3 };
	ArrPrint(arr);

	return 0;
}

void ArrPrintf(int arg[])
{
	int i;

	for (i = 0; i < 3; i++)
		print("%4d", arg[i]);

	printf("\n");
}