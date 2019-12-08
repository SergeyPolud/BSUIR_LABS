#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int strlenka(char* str)
{
	int length = 0;
	while (*str++ != '\0') length++;
	return length;
}
void strposconcat(char* dest, char* src, int pos)
{
	int l1 = strlenka(dest);
	int l2 = strlenka(src);
	int indx = 0;

	for (int i = 0; i < l2; i++)
	{
		dest[pos++] = src[indx++];
	}
	dest[l1 + l2] = '\0';
}
void third_ex()
{
	char first_str[255], second_str[255];
	cout << "Введите первую строку" << endl;
	gets_s(first_str);
	cout << "Введите вторую строку" << endl;
	gets_s(second_str);
	int len_1 = strlenka(first_str), len_2 = strlenka(second_str);
	cout << len_1 << " " << len_2 << endl;
	int pos = len_1 / 2;
	char tmp[255];
	for (int i = 0; i <= len_1/2; i++)
	{
		tmp[i] = first_str[pos++];
	}
	tmp[len_1 / 2+1] = '\0';
	strposconcat(first_str, second_str, len_1/2);
	strposconcat(first_str, tmp, len_1 / 2 + len_2);
	cout << first_str << endl;
}

int main()
{
	//setlocale(0, " ");
	setlocale(LC_ALL, "Russian");
	//first_ex();
	//double_ex();
	third_ex();
	system("pause");
	return 0;
}