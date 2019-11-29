#define _CRT_SECURE_NO_WARNINGS
#define STUD_SIZE sizeof(Student)
#include <iostream>
#include <string>
#include "student.h"
#include <Windows.h>

using namespace std;

long GetFileSize(FILE*);
void Overwrite(Student*, FILE*);
bool Create_New(const char*);
Student* Edit(FILE*);
void Output(Student*);
void Open_Read(const char*);
bool Append(const char*, Student);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short select;
	do 
	{
		FILE* fp3;
		Student Stud;
		char FILE_PATH[100];
		cout << "Выберите желаемое действие:\n\t 1.Создать файл\n\t 2.Открыть файл\n\t 3.Добавить новую запись\n\t 4.Найти студентов, имеющих не ниже 4 по математике\n\t 5.Редактировать\n\t" << endl;
		cin >> select;
		switch (select) 
		{
			case 1: 
				cout << "Введите имя нового файла" << endl;
				cin >> FILE_PATH;
				if (!Create_New(FILE_PATH)) 
				{
					cout << "Ошибка создания файла!!!!";
					break;
				}
				cout << "Успешно создан новый файл " << FILE_PATH << endl;
				break;
			case 2:
				cout << "введите имя октрываемого файла:" << endl;
				cin >> FILE_PATH;
				Open_Read(FILE_PATH);
				break;
			case 3:
				cout << "введите имя октрываемого файла:" << endl;
				cin >> FILE_PATH;
				cout << "Введите ФИО студента" << endl;
				cin.ignore();
				cin.getline(Stud.FIO, 50);
				cout << "Введите номер группы" << endl;
				cin  >> Stud.groupNumber;
				cout << "Введите оценку по математике, физике, информатике через пробел." << endl;
				cin >> Stud.math_mark >> Stud.phys_mark >> Stud.inf_mark;
				Stud.average = (Stud.inf_mark + Stud.math_mark + Stud.phys_mark) / 3;
				if (!Append(FILE_PATH, Stud)) 
				{
					cout << "Ошибка добавления!" << endl;
					break;
				};
				break;
			case 4:
				cout << "введите имя открываемого файла" << endl;
				cin >> FILE_PATH;
				fp3 = fopen(FILE_PATH, "rb");
				while (fread(&Stud, STUD_SIZE, 1, fp3) != NULL) 
				{
					if (Stud.math_mark >= 4 && Stud.inf_mark >= 4) 
					{
						Output(&Stud);
					}
				}
				break;
			case 5:
				cout << "введите имя открываемого файла" << endl;
				cin >> FILE_PATH;
				FILE* fpt1 = fopen(FILE_PATH, "r+");
				int struct_count = GetFileSize(fpt1) / STUD_SIZE;
				Overwrite(Edit(fpt1), fpt1);
		}
	} while (select >= 1 && select <= 6);
	_fcloseall();
	return 0;
}

long GetFileSize(FILE* file)
{
	fseek(file, 0L, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return fileSize;
}
void Overwrite(Student* stud, FILE* fpt1)
{
	int pos = ftell(fpt1);
	fseek(fpt1, pos - STUD_SIZE, SEEK_SET);
	fwrite(stud, STUD_SIZE, 1, fpt1);
	delete stud;
	fclose(fpt1);
}
bool Create_New(const char* filePath)
{
	FILE* fp = fopen(filePath, "wb");
	if (fp == NULL) return false;
	fclose(fp);
	return true;
}

Student* Edit(FILE* fpt1)
{
	char FIO[50];
	short select;
	cout << "Введите ФИО студента для редактирования" << endl;
	cin.ignore();
	cin.getline(FIO, 50);
	long struct_count = GetFileSize(fpt1) / STUD_SIZE;
	//Student* stArray = new Student[struct_count];
	Student* stud = new Student;
	for (int i = 0; i < struct_count; i++)
	{
		fread(stud, STUD_SIZE, 1, fpt1);
		if (*(stud->FIO) == (*FIO))
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
					cin >> stud->FIO;
					break;
				case 2:
					cout << "введите новый номер группы" << endl;
					cin >> stud->groupNumber;
					break;
				case 3:
					cout << "Введите новую Оценку по физике" << endl;
					cin >> stud->phys_mark;
					break;
				case 4:
					cout << "Введите новую Оценку по математике" << endl;
					cin >> stud->math_mark;
					break;
				case 5:
					cout << "Введите новую Оценку по информматике" << endl;
					cin >> stud->inf_mark;
					break;
				}
			} while (select > 1 && select < 6);
		}
		stud->average = (stud->inf_mark + stud->math_mark + stud->phys_mark) / 3;
	}
	return stud;
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
	delete stud;
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
