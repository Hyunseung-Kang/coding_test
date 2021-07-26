#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include<string>

int solution(const char* s);

int main(void) {

	int result;
 
 
	// 문지열 상수는 프로그램이 로드될 때 정적영역에 "~~"를 저장한 후
	// 해당 메모리의 시작 주소를 const char의 포인터변수에 저장한다.
 
	//result = solution("one4seveneight");
	//result = solution("23four5six7");
	//result = solution("2three45sixseven");
	result = solution("123");
	
	printf("result: %d\n", result);

	return 0;
}


int solution(const char* s) {
	int answer = 0;

	int length = 0;
	for (int i = 0; i < 50; i++) {
		if (s[i] != NULL)
			length++;
		else
			break;
	}


	char* arr = (char*)malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++) {
		int num = s[i];

		if ((num >= '0') && (num <= '9')) {
			arr[i] = s[i];
			continue;
		}
		if (s[i] == 'z') {
			arr[i] = '0';
			for (int space = 1; space < 4; space++)
				arr[i + space] = NULL;
			i = i + 3;
			continue;
		}
		if (s[i] == 'o') {
			arr[i] = '1';
			for (int space = 1; space < 3; space++)
				arr[i + space] = NULL;
			i = i + 2;
			continue;
		}
		if ((s[i] == 't')&&(s[i+1]=='w')) {
			arr[i] = '2';
			for (int space = 1; space < 3; space++)
				arr[i + space] = NULL;
			i = i + 2;
			continue;
		}
		if ((s[i] == 't') && (s[i + 1] == 'h')) {
			arr[i] = '3';
			for (int space = 1; space < 5; space++)
				arr[i + space] = NULL;
			i = i + 4;
			continue;
		}
		if ((s[i] == 'f') && (s[i + 1] == 'o')) {
			arr[i] = '4';
			for (int space = 1; space < 4; space++)
				arr[i + space] = NULL;
			i = i + 3;
			continue;
		}
		if ((s[i] == 'f') && (s[i + 1] == 'i')) {
			arr[i] = '5';
			for (int space = 1; space < 4; space++)
				arr[i + space] = NULL;
			i = i + 3;
			continue;
		}
		if ((s[i] == 's') && (s[i + 1] == 'i')) {
			arr[i] = '6';
			for (int space = 1; space < 3; space++)
				arr[i + space] = NULL;
			i = i + 2;
			continue;
		}
		if ((s[i] == 's') && (s[i + 1] == 'e')) {
			arr[i] = '7';
			for (int space = 1; space < 5; space++)
				arr[i + space] = NULL;
			i = i + 4;
			continue;
		}
		if (s[i] == 'e') {
			arr[i] = '8';
			for (int space = 1; space < 5; space++)
				arr[i + space] = NULL;
			i = i + 4;
			continue;
		}
		if (s[i] == 'n') {
			arr[i] = '9';
			for (int space = 1; space < 4; space++)
				arr[i + space] = NULL;
			i = i + 3;
			continue;
		}
	}


	int count = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] != NULL)
			count++;
		else
			continue;
	}

	char* arr_2 = (char*)malloc(sizeof(int) * count);
	int count_2 = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] != NULL) {
			arr_2[count_2] = arr[i];
			count_2 = count_2 + 1;
		}
		else
			continue;
	}

	answer = atoi(arr_2);
	

	return answer;
}
