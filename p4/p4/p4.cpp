#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_LENGTH 200
#define MAX 16000

FILE *fp;
int size = 0;

typedef struct Log {
	char *ip, time[BUFFER_LENGTH], *url, *status;
	double ctime;
}Log;

Log web[MAX];

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
			printf("파일을 불러왔습니다.\n");
			return;
		}
	}
}

char* mtoi(char *p) {
	if (strcmp(p, "Jan") == 0)
		return strdup("01");
	else if (strcmp(p, "Feb") == 0)
		return strdup("02");
	else if (strcmp(p, "Mar") == 0)
		return strdup("03");
	else if (strcmp(p, "Apr") == 0)
		return strdup("04");
	else if (strcmp(p, "May") == 0)
		return strdup("05");
	else if (strcmp(p, "Jun") == 0)
		return strdup("06");
	else if (strcmp(p, "Jul") == 0)
		return strdup("07");
	else if (strcmp(p, "Aug") == 0)
		return strdup("08");
	else if (strcmp(p, "Sep") == 0)
		return strdup("09");
	else if (strcmp(p, "Oct") == 0)
		return strdup("10");
	else if (strcmp(p, "Nov") == 0)
		return strdup("11");
	else
		return strdup("12");
}

void save() {
	printf("데이터를 읽는 중...\n");
	char moon[BUFFER_LENGTH], *temp, *tday, *tmonth, *tyear, *tctime, *stopstring;
	fgets(moon, BUFFER_LENGTH, fp); //first skip
	while (!feof(fp)) {
		fgets(moon, BUFFER_LENGTH, fp);
		web[size].ip = strdup(strtok(moon, ","));
		strcpy(web[size].time, strtok(NULL, ","));
		for (int i = 0; web[size].time[i] != '\0'; i++)
			web[size].time[i] = web[size].time[i + 1];
		web[size].url = strdup(strtok(NULL, ","));
		web[size].status = strdup(strtok(NULL, "\n"));
		temp = strdup(web[size].time);
		tday = strtok(temp, "/");
		tmonth = strtok(NULL, "/");
		tmonth = mtoi(tmonth);
		tyear = strtok(NULL, ":");
		tctime = strdup(tyear);
		strcat(tctime, tmonth);
		strcat(tctime, tday);
		strcat(tctime, strtok(NULL, ":"));
		strcat(tctime, strtok(NULL, ":"));
		strcat(tctime, strtok(NULL, "\0"));
		web[size].ctime = strtod(tctime, &stopstring);
		size++;
	}
	printf("완료!...\n\n");
}

void print() {
	for (int i = 0; i < 100; i++)
		printf("IP: %s\nStatus: %s\nTime: %s\nURL: %s\n\n", web[i].ip, web[i].status, web[i].time, web[i].url);
}

void printT() {
	for (int i = 0; i < 100; i++)
		printf("%s\n\tIP: %s\n\tStatus: %s\n\tURL: %s\n", web[i].time, web[i].ip, web[i].status, web[i].url);
}

void printIP() {
	for (int i = 0; i < 100; i++)
		printf("%s\n\tTime: %s\n\tStatus: %s\n\tURL: %s\n", web[i].ip, web[i].time, web[i].status, web[i].url);
}

int compareT(const void *p, const void *q) {
	if (((Log *)p)->ctime > ((Log *)q)->ctime)
		return 1;
	else if (((Log *)p)->ctime < ((Log *)q)->ctime)
		return -1;
	else
		return 0;
}

int compareIP(const void *p, const void *q) {
	return strcmp(((Log *)p)->ip, ((Log *)q)->ip);
}

void sortT() {
	qsort(web, size, sizeof(Log), compareT);
}

void sortIP() {
	int temp = 0;
	qsort(web, size, sizeof(Log), compareIP);
	for (int i = temp; i < size; i++) {
		if (strcmp(web[i].ip, web[i + 1].ip) != 0) {
			qsort(web + temp, i + 1, sizeof(Log), compareT);
			break;
		}
	}
}

int main()
{
	char command[BUFFER_LENGTH];
	char *moon, *pmoon = NULL;
	load();
	save();
	while (1) {
		printf("$ ");
		gets_s(command, sizeof(command));
		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "print") == 0) {
			if (pmoon == NULL)
				print();
			else if (strcmp(pmoon, "-t") == 0)
				printT();
			else
				printIP();
		}
		else {
			strtok(command, " ");
			if (strcmp(command, "sort") == 0) {
				moon = strtok(NULL, "\0");
				if (moon == NULL) {
					printf("잘못된 입력입니다.\n\n");
					continue;
				}
				if (strcmp(moon, "-t") == 0) {
					sortT();
					pmoon = strdup(moon);
				}
				else if (strcmp(moon, "-ip") == 0) {
					sortIP();
					pmoon = strdup(moon);
				}
				else
					printf("잘못된 입력입니다.\n\n");
			}
			else
				printf("잘못된 입력입니다.\n\n");
		}
	}
	return 0;
}