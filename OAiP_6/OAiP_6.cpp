// OAiP_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*int main()
{
	setlocale(LC_ALL, "Russian");
	char* string = new char[8192];
	int length, half;
	cout << "Введите строку" << endl;
	cin >> string;
	length = strlen(string);
	if (length % 2 != 0) {
		half = length / 2;
		char* tmpstr1 = new char[half];
		char* tmpstr2 = new char[half];
		char* result;
		for (int i = 0; i < half; i++) {
			tmpstr1[i] = string[i];
			tmpstr2[i] = string[half + i+1];
		}
		tmpstr1[half] = tmpstr1[half] = '\0';
		result = strcat(tmpstr1, tmpstr2);
		cout << result << endl;
		delete string;
		delete tmpstr1;
		delete tmpstr2;
		delete result;
		return 0;
	}
	else {
		cout << "Строка четной длины" << endl;
		return 0;
	}
}*/
char GetNext(char* strptr) {
	return *(++strptr);
}
char* ConcatNumbers(char* dest, char* src, int& index, int& mainIndex) {
	do {
		dest[index++] = *src;
		mainIndex++;
	} while (isdigit(GetNext(src++)));
	return dest;
}
void Clear(char* src) {
	for (int i = 0; i < 100; i++) {
		src[i] = '\0';
	}
}
int main() {

	char stroka1[100] = "ojsjfalsf+-99ds,-39.090980899878798698768768768768jeijdieowe";
	int index = 0;
	char* output = new char[100];
	char* result = new char[100];
	char* save;
	char* strptr = stroka1;
	for (int i = 0; i < 100; ++i) {
		if (isdigit(*(strptr + i)) || *(strptr + i) == '-') {
			save = strptr + i;
			ConcatNumbers(result, save, index, i);
			if (*(strptr + i) == '.') {
				result[index++] = '.';
				output = ConcatNumbers(result, strptr+i+1, index, i);
			}
			else {
				Clear(result);
				index = 0;
			}
		}
	}
	cout << output;
	return 0;
}
