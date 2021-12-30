#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10000

// 파일 입출력
// 파일에 데이터 저장 및 불러오기

int main(void)
{

	// fputs, fgets 쌍
	char line[MAX];
	// 파일 쓰기
	/*
	FILE* file = fopen("C:\\Users\\alsgu\\OneDrive\\바탕 화면\\C\\test.txt", "wb"); // r w a, t b
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}

	fputs("fputs 를 이용해서 글을 적어볼게요\n", file);
	fputs("잘 적히는지 확인해주세요\n", file);
	*/
	// 파일 읽기

	FILE *file = fopen("C:\\Users\\alsgu\\OneDrive\\바탕 화면\\C\\test.txt", "rb"); // r w a, t b
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}

	// fprintf, fscanf 비슷함.

	fclose(file); // 파일을 열면 닫는 습관을 들이자.

	return 0;
}