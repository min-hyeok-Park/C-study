// 포인터(pointer): 변수의 주소를 저장하는 변수

#include <stdio.h>

int main()
{
	int a = 20;

	int *ptr_a;

	int **ptr_ptr;
	ptr_ptr = &ptr_a;

	ptr_a = &a;
	// & = 주소
	printf("a의 값 : %d \n", a);
	printf("a의 주소값 : %d\n", &a);
	printf("ptr_a에 저장된 값 : %d\n", ptr_a);
	printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a);

	printf("a = %d\n", a);
	printf("&a = %d\n", &a);
	printf("ptr_a = %d\n", ptr_a);
	printf("&ptr_a = %d\n", &ptr_a);
	printf("*ptr_a = %d\n", *ptr_a);
	printf("ptr_ptr %d\n", ptr_ptr);
	printf("*ptr_ptr %d\n", *ptr_ptr);
	printf("**ptr_ptr %d\n", **ptr_ptr);
}