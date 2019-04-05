#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_LENGTH 100

FILE *fp;
int size = 0;

void load() {
	char buffer[BUFFER_LENGTH];
	while (1) {
		printf("$ read ");
		scanf("%s", buffer);
		getchar();
		fp = fopen(buffer, "r");
		if (fp == NULL)
			printf("파일을 찾을 수 없습니다.\n");
		else {
			printf("파일을 불러왔습니다.\n\n");
			return;
		}
	}
}

void save() {
	//char moon[2000];
	//int ok = 0;

	//while (!feof(fp)) {

	//}
	printf("데이터 저장이다.\n");
}

void print() {
	printf("데이터 출력이다.\n\n");
}

void sortT() {
	printf("시간순 정렬이다.\n\n");
}

void sortIP() {
	printf("아이피순 정렬이다.\n\n");
}

int main() 
{
	char command[BUFFER_LENGTH];
	char *moon;
	load();
	save();
	while (1) {
		printf("$ ");
		gets_s(command, sizeof(command));
		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "print") == 0)
			print();
		else{
			strtok(command, " ");
			if (strcmp(command, "sort") == 0) {
				moon = strtok(NULL, "\0");
				if (moon == NULL) {
					printf("잘못된 입력입니다.\n\n");
					continue;
				}
				if (strcmp(moon, "-t") == 0)
					sortT();
				else if (strcmp(moon, "-ip") == 0)
					sortIP();
				else
					printf("잘못된 입력입니다.\n\n");
			}
			else
				printf("잘못된 입력입니다.\n\n");
		}
	}
	return 0;
}