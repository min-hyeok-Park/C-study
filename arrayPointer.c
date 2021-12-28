#include <stdio.h>

int main()
{
	/*
	int arr[3] = { 1, 2, 3 };

	int(*ptr_arr)[3]; //길이 3인 int형 배열을 가리키는 포인터를 선언
	ptr_arr = &arr;

	for (int i = 0; i < 3; i++) {
		printf("%d\n", (*ptr_arr)[i]);
	}
	*/
	int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("%d\n", sizeof(arr2));		//24
	printf("%d\n", sizeof(arr2[0]));	//12
	printf("%d\n", sizeof(arr2[0][0])); //4

	for (int(*row)[3] = arr2; row < arr2 + 2; row++)
	{
		for (int *col = *row; col < *row + 3; col++)
		{
			printf("%d ", *col);
		}
		printf("\n");
	}
}