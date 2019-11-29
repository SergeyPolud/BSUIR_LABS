// OAiP_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int strlen(char* str);
bool isDigit(char ch);
int check_left(char* str, int pos);
int check_right(char* stroka1, int pos);
//char* strConcat(char* dest, char* src);

//6.1
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	char stroka[256];
//	int length;
//	cout << "введите строку" << endl;
//	cin >> stroka;
//	length = strlen(stroka);
//	if (length & 1) {
//		for (int i = length / 2; i < length; i++) 
//		{
//			stroka[i] = stroka[i+1];
//		}
//		cout << stroka;
//	}
//	else {
//		cout << "Строка четной длины" << endl;
//		return -1;
//	}
//	return 0;
//}

// 6.2

//int main() 
//{
//	setlocale(LC_ALL, "Russian");
//	char stroka1[100] = "ojsjfalsf+-99ds,33.090980899878798698768768768768jeijieowe-.0008302987329";
//	int left, right;
//	int size = strlen(stroka1);
//	for (int i = 1; i < size-1; ++i)
//	{
//		if (stroka1[i] == '.')
//		{
//			if (stroka1[i - 1] == '-')
//			{
//				left = i - 1;
//				right = check_right(stroka1, i);
//			}
//			else
//			{
//				left = check_left(stroka1, i);
//				right = check_right(stroka1, i);
//			}
//			for (int j = left; j < right; j++) 
//			{
//				cout << stroka1[j];
//			}
//			i = right;
//			cout << endl;
//		}
//	}
//	return 0;
//}
//6.3
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	char stroka1[256] = "\0";
//	cout << "Введите строку\n" << endl;
//	cin >> stroka1;
//	int length = strlen(stroka1);
//	cout << endl;
//	for (int i = 0; i < length; i++)
//	{
//	
//		if (!i%3 && !i%4) stroka1[i] = '#';
//		else if (!i%4) stroka1[i] = '&';
//		else if (!i%3) stroka1[i] = '%';
//	}
//	cout << "Результат преобразования строки\n\n" << stroka1 << endl;
//	return 0;
//}

int strlen(char* str)
{
	int length = 0;
	while (*str++ != '\0') length++;
	return length;
}

bool isDigit(char ch)
{
	return ch > 47 && ch < 58 ? true : false;
}

int check_left(char* str, int pos)
{
	while (true){
		if (!isDigit(str[pos - 1]))
		{
			if(str[pos-1] == '-')
			{
				pos--;
				break;
			}
			else 
				break;
			
		}
		pos--;
	} 
	return pos;
}
int check_right(char* str, int pos)
{
	do {
		if (!isDigit(str[pos + 1])) break;
		pos++;
	} while (true);
	return pos;
}
/*char* strConcat(char* dest, char* src)
{
	int dst_length = strlen(dest);
	int final = dst_length + strlen(src) + 1;
	char* result = new char[dst_length + strlen(src) + 1];
	result = dest;
	for (int i = dst_length; i < final; i++) result[i] = src[i];
	return result;
}*/

int strcmp(char* s1, char* s2, int l1, int l2) {
	int targetSize = l1;
	if (l2 < l1) targetSize = l2;
	for (int i = 0; i < targetSize; i++) {
		if (s1[i] > s2[i]) return 1;
		else if (s1[i] < s2[i]) return -1;
	}
	return 0;
}

int main()
{
	char str[100] = "";
	cin.getline(str, 50);
	char w_arr[50][20];
	int w_cnt = 0, w_indx =0 ;
	int i = 0;
	while(str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\0')
			{
				w_arr[w_cnt][w_indx++] = str[i++];
			}
			w_arr[w_cnt][w_indx] = '\0';
			w_cnt++;
			w_indx = 0;
		}
		i++;
	}
	for (int i = 0; i < w_cnt-1; i++) {
		for (int j = i + 1; j < w_cnt; j++) {
			if (strcmp(w_arr[i], w_arr[j], strlen(w_arr[i]), strlen(w_arr[j])) == 1)
			{
				char temp[20];
				strcpy(temp, w_arr[i]);
				strcpy(w_arr[i], w_arr[j]);
				strcpy(w_arr[j], temp);
			}
		}
	}
	return 0;
}
