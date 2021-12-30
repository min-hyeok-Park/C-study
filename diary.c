#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 비밀번호를 입력 받아서
// 맞으면? 비밀 일기를 읽어와서 보여주고, 작성하게끔
// 틀리면? 경고 메시지 표시 후 종료.

#define MAX 10000

int main(void)
{
	// fgets, fputs 활용
	char line[MAX];		// 파일에서 불러온 내용 저장할 변수
	char contents[MAX]; // 일기장에 입력할 내용
	char password[20];	// 비밀번호 입력
	char check;			// 비밀번호 입력 할 때 키값 확인용 (마스킹)

	printf("'비밀일기'에 오신 것을 환영합니다\n");
	printf("비밀번호를 입력하세요 : ");

	// getchar() = 엔터를 입력받아야 동작
	// getch() = 키 입력 시 바로바로
	int i = 0;
	while (1)
	{
		check = getch();
		if (check == 13)
		{ // Enter -> 비밀번호 입력 종료
			password[i] = '\0';
			break;
		}
		else
		{ // 비밀번호 입력 중
			printf("*");
			password[i] = check;
		}
		i++;
	}

	printf("\n\n === 비밀번호 확인중... ===\n\n");
	if (strcmp(password, "wldk0909") == 0)
	{
		printf(" === 비밀번호 확인 완료 === \n\n");
		char *fileName = "C:\\Users\\alsgu\\OneDrive\\바탕 화면\\C\\secretDiary.txt";
		FILE *file = fopen(fileName, "a+b");
		// 파일이 없으면 생성, 파일이 있으면 append 를 한다. (뒤에서부터 내용을 추가.)
		if (file == NULL)
		{
			printf("파일 열기 실패\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT 를 입력하세요\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); // 세 줄(\n)이 나오기 전까지 읽어들임 (한 문장 씩)
			getchar();				   // Enter 입력 (\n) Flush 처리

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("비밀일기 입력을 종료합니다\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);
		}
		fclose(file);
	}
	else
	{
		printf(" === 비밀번호가 틀렸어요 ===\n\n");
		printf("멍충이 \n\n");
	}

	return 0;
}