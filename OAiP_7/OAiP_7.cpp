#define _CRT_SECURE_NO_WARNINGS
#define STUD_SIZE sizeof(Student)
#include <iostream>
#include <string>
#include "student.h"
#include <Windows.h>

using namespace std;


int strlen(char*);
int strcmp(char*, char*, int, int);
long GetFileSize(FILE*);
void Save_Entry(Student*, FILE*);
bool Create_New(const char*);
void Edit(FILE*);
void Output(Student*);
void Open_Read(const char*);
bool Append(const char*, Student);
Student* DeleteEntry(FILE*);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short select;
	short ch;
	char FILE_PATH[100];
	do  
	{
		cout << "1. Открыть файл. 2. Создать файл 3. Выход" << endl;
		cin >> ch;
		if (ch == 3) return 0;
		if (ch == 1)
		{
		    cout << "введите имя открываемого файла" << endl;
			cin >> FILE_PATH;
			break;
		}
		char path[100];
		cout << "Введите имя нового файла" << endl;
		cin >> path;
		if (!Create_New(path))
		{
			cout << "Ошибка создания файла!!!!";
			break;
		}
		cout << "Успешно создан новый файл " << path << endl;
	}while(ch == 2);
	do 
	{
		FILE* fp3;
		FILE* fpt1;
		FILE* fpt2;
		Student Stud;
		cout << "Выберите желаемое действие\n\n:1.Прочитать файл\n\t 2.Добавить новую запись\n\t 3.Найти студентов, имеющих не ниже 4 по математике\n\t 4.Редактировать\n\t 5.Удалить запись" << endl;
		cin >> select;
		switch (select)
		{

		case 1:
			Open_Read(FILE_PATH);
			break;
		case 2:
			cout << "Введите ФИО студента" << endl;
			cin.ignore();
			cin.getline(Stud.FIO, 50);
			cout << "Введите номер группы" << endl;
			cin >> Stud.groupNumber;
			cout << "Введите оценку по математике, физике, информатике через пробел." << endl;
			cin >> Stud.math_mark >> Stud.phys_mark >> Stud.inf_mark;
			Stud.average = (Stud.inf_mark + Stud.math_mark + Stud.phys_mark) / 3;
			if (!Append(FILE_PATH, Stud))
			{
				cout << "Ошибка добавления!" << endl;
				break;
			};
			break;
		case 3:
			fp3 = fopen(FILE_PATH, "rb");
			while (fread(&Stud, STUD_SIZE, 1, fp3) != NULL)
			{
				if (Stud.math_mark >= 4 && Stud.inf_mark >= 4)
				{
					Output(&Stud);
				}
			}
			break;
		case 4:
			fpt1 = fopen(FILE_PATH, "r+");
			Edit(fpt1);
			fclose(fpt1);
		case 5:
			fpt2 = fopen(FILE_PATH, "r");
			Student* arr = DeleteEntry(fpt2);
			int struct_cnt = ftell(fpt2) / STUD_SIZE - 1;
			fclose(fpt2);
			fpt2 = fopen(FILE_PATH, "wb"); //Clears the file
			for (int i = 0; i < struct_cnt; i++)
				fwrite(&arr[i], STUD_SIZE, 1, fpt2);
			fclose(fpt2);
			break;
		}
	} while (select >= 1 && select < 6);
	_fcloseall();
	return 0;
}

Student* DeleteEntry(FILE* fpt2)
{
	bool flag = false;
	char FIO[50];
	cout << "Введите ФИО для удаления" << endl;
	cin.ignore();
	cin.getline(FIO, 50);
	long struct_count = GetFileSize(fpt2) / STUD_SIZE;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++) 
	{
		fread(&struct_arr[i], STUD_SIZE, 1, fpt2);
	}
	for (int i = 0; i < struct_count; i++) 
	{
		if (!strcmp(struct_arr[i].FIO, FIO, strlen(struct_arr[i].FIO), strlen(FIO)))
		{
			flag = true;
			for (int j = i; j < struct_count-1; j++) 
				struct_arr[j] = struct_arr[j + 1];
			break;
		}
	}
	if (!flag) 
	{
		delete[] struct_arr;
		return false;
	}
	struct_count--;
	return struct_arr;
}

long GetFileSize(FILE* file)
{
	fseek(file, 0L, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return fileSize;
}
void Save_Entry(Student* stud, FILE* fpt1)
{
	int pos = ftell(fpt1);
	fseek(fpt1, pos - STUD_SIZE, SEEK_SET);
	fwrite(stud, STUD_SIZE, 1, fpt1);
}
bool Create_New(const char* filePath)
{
	FILE* fp = fopen(filePath, "wb");
	if (fp == NULL) return false;
	fclose(fp);
	return true;
}

void Edit(FILE* fpt1)
{
	do 
	{
		char FIO[50];
		short select;
		Student* stud = new Student;
		cout << "Введите ФИО студента для редактирования, 1 для выхода" << endl;
		cin.ignore();
		cin.getline(FIO, 50);
		if (FIO == "1") break;
		long struct_count = GetFileSize(fpt1) / STUD_SIZE;
		for (int i = 0; i < struct_count; i++)
		{
			fread(stud, STUD_SIZE, 1, fpt1);
			if (!strcmp(stud->FIO, FIO, strlen(stud->FIO), strlen(FIO)))
			{
				do
				{
					cout << "Выберите поле для редактирования: 1-ФИО\n\t 2-Номер группы\n\t 3-Оценка по физике\n\t 4-Оценка по математике\n\t 5-Оценка по иноформатике\n\t" << endl;
					cout << "6-сохранить изменения" << endl;
					cin >> select;
					switch (select)
					{
					case 1:
						cout << "Введите новое ФИО" << endl;
						cin.ignore();
						cin.getline(stud->FIO, 50);
						break;
					case 2:
						cout << "введите новый номер группы" << endl;
						cin >> stud->groupNumber;
						break;
					case 3:
						cout << "Введите новую Оценку по физике" << endl;
						cin >> stud->phys_mark;
						stud->average = (stud->inf_mark + stud->math_mark + stud->phys_mark) / 3;
						break;
					case 4:
						cout << "Введите новую Оценку по математике" << endl;
						cin >> stud->math_mark;
						stud->average = (stud->inf_mark + stud->math_mark + stud->phys_mark) / 3;
						break;
					case 5:
						cout << "Введите новую Оценку по информматике" << endl;
						cin >> stud->inf_mark;
						stud->average = (stud->inf_mark + stud->math_mark + stud->phys_mark) / 3;
						break;
					case 6:
						Save_Entry(stud, fpt1);
						break;
					}
				} while (select > 0 && select < 6);
				break;
			}
			else
			{
				cout << "Записи о данном ФИО не существует!" << endl;
				break;
			}
		}
		delete stud;
	} while (true);
}
void Output(Student* stud)
{
	cout << "=========================++++++++++++============================" << endl;
	cout << "Имя: " << stud->FIO << "\nНомер группы: " << stud->groupNumber << "\n\t+-------------------+" << endl;
	cout << "Оценка по физикие: " << stud->phys_mark << endl;
	cout << "Оценка по математике: " << stud->math_mark << endl;
	cout << "Оценка балл по информатике: " << stud->inf_mark << endl;
	cout << "Средний балл " << stud->average << endl;
	cout << "=========================++++++++++++============================" << endl;
}
void Open_Read(const char* filePath)
{
	FILE* fp2 = fopen(filePath, "rb");
	Student st;
	while (true)
	{
		if (!fread(&st, sizeof(Student), 1, fp2)) break;
		Output(&st);
	}
	fclose(fp2);
}
bool Append(const char* filePath, Student ptr)
{
	FILE* fp1 = fopen(filePath, "ab");
	if (fp1 == NULL) return false;
	fwrite(&ptr, STUD_SIZE, 1, fp1);
	fclose(fp1);
	return true;
}
int strcmp(char* s1, char* s2, int l1, int l2) 
{
	int targetSize = l1;
	if (l2 < l1) targetSize = l2;
	for (int i = 0; i < targetSize; i++) 
	{
		if (s1[i] > s2[i]) return 1;
		else if (s1[i] < s2[i]) return -1;
	}
	return 0;
}
int strlen(char* str)
{
	int length = 0;
	while (*str++ != '\0') length++;
	return length;
}