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
			printf("������ ã�� �� �����ϴ�.\n");
		else {
			printf("������ �ҷ��Խ��ϴ�.\n\n");
			return;
		}
	}
}

void save() {
	//char moon[2000];
	//int ok = 0;

	//while (!feof(fp)) {

	//}
	printf("������ �����̴�.\n");
}

void print() {
	printf("������ ����̴�.\n\n");
}

void sortT() {
	printf("�ð��� �����̴�.\n\n");
}

void sortIP() {
	printf("�����Ǽ� �����̴�.\n\n");
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
					printf("�߸��� �Է��Դϴ�.\n\n");
					continue;
				}
				if (strcmp(moon, "-t") == 0)
					sortT();
				else if (strcmp(moon, "-ip") == 0)
					sortIP();
				else
					printf("�߸��� �Է��Դϴ�.\n\n");
			}
			else
				printf("�߸��� �Է��Դϴ�.\n\n");
		}
	}
	return 0;
}