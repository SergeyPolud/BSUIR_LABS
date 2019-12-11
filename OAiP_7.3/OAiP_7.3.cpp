#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

void Encrypt(char*);
int strlen_custom(char*);
char* Decrypt(FILE* enc_ptr);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char encryptedFile[20] = "encrypted.txt";
	char outputFile[20] = "output.txt";
	char string[256];
	int length;
	FILE* enc_ptr;
	char* str_from_file;
	short select;
	char* decrypted;
	do {
		cout << "\t 1. Ввод строки с клавиатуры и запись в файл \n\t 2. Cчитывание строки из файла \n\t 3. Зашифровать файл \n\t 4. Дешифровать файл \n\t" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "Введите строку\n" << endl;
			cin.ignore();
			cin.getline(string, 256);
			enc_ptr = fopen(encryptedFile, "w");
			fwrite(&string, strlen_custom(string), 1, enc_ptr);
			fclose(enc_ptr);
			break;
		case 2:
			enc_ptr = fopen(encryptedFile, "r");
			fseek(enc_ptr, 0, SEEK_END);
			length = ftell(enc_ptr);
			if (length == -1) {
				cout << "Ошибка считывания\n" << endl;
				break;
			}
			fseek(enc_ptr, 0, SEEK_SET);
			str_from_file = new char[length+1];
			fread(str_from_file, length, 1, enc_ptr);
			str_from_file[length] = '\0';
			cout << str_from_file << endl;
			fclose(enc_ptr);
			delete[] str_from_file;
			break;
		case 3:
			Encrypt(encryptedFile);
			break;
		case 4:
			enc_ptr = fopen(encryptedFile, "r");
			decrypted = Decrypt(enc_ptr);
			fclose(enc_ptr);
			enc_ptr = fopen(outputFile, "w");
			fwrite(decrypted, strlen_custom(decrypted), 1, enc_ptr);
			fclose(enc_ptr);
			delete[] decrypted;
			break;
		}
	} while (select == 1 || select == 2 || select == 3 || select == 4);
	_fcloseall();
	return 0;
}

void Encrypt(char* filename)
{
	int cnt;
	FILE* fptr = fopen(filename, "r");
	fseek(fptr, 0, SEEK_END);
	cnt = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	char* buf = new char[cnt];
	fread(buf, cnt, 1, fptr);
	fclose(fptr);
	fptr = fopen(filename, "w");
	for (int i = 0; i < cnt; i++)
	{
		if (!(buf[i] == 'а' || buf[i] == 'е' || buf[i] == 'ё' || buf[i] == 'и' || buf[i] == 'о' || buf[i] == 'у' || buf[i] == 'ы' || buf[i] == 'э' || buf[i] == 'ю' || buf[i] == 'я'))
			fwrite(&buf[i], 1, 1, fptr);
		else
		{
			fwrite(&buf[i], 1, 1, fptr);
			fwrite("с", 1, 1, fptr);
		}
	}
	fclose(fptr);
	delete[] buf;
}
char* Decrypt(FILE* fptr)
{
	int chars = 0;
	fseek(fptr, 0, SEEK_END);
	int cnt = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	char* output = new char[cnt+1];
	for (int i = 0; i < cnt; i++)
	{
		fread(&output[i], 1, 1, fptr);
		if (output[i] == 'с') 
		{
			chars++;
			fread(&output[i], 1, 1, fptr);
		}
	}
	if(chars)
		output[cnt-chars] = '\0';
	else output[cnt] = '\0';
	cout << output << endl;
	return output;
}

int strlen_custom(char* str)
{
	int length = 0;
	while (*str++ != '\0') length++;
	return length;
}