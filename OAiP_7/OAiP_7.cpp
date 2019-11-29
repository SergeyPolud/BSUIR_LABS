#define _CRT_SECURE_NO_WARNINGS
#define STUD_SIZE sizeof(Student)
#include <iostream>
#include <string>
//#include "student.h"
#include <Windows.h>

using namespace std;

struct Student
{
	char FIO[30];
	int groupNumber;
	double phys_mark;
	double inf_mark;
	double math_mark;
	double average;
};

long GetFileSize(const char* filepath);
void Rewrite(Student* stud, const char* filepath, int struct_count);
void Create_New(const char* filePath);
Student* Edit(const char* filepath);
void Output(Student* stud);
void Open_Read(const char* filePath);
bool Append(const char* filePath, Student ptr);




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
				Create_New(FILE_PATH);
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
					break;
				};
				break;
			case 4:
				cout << "введите имя открываемого файла" << endl;
				cin >> FILE_PATH;
				fp3 = fopen(FILE_PATH, "rb");
				while (fread(&Stud, STUD_SIZE, 1, fp3) != NULL) {
					if (Stud.math_mark >= 4 && Stud.inf_mark >= 4) {
						Output(&Stud);
					}
				}
				break;
			case 5:
				cout << "введите имя открываемого файла" << endl;
				cin >> FILE_PATH;
				int struct_count = GetFileSize(FILE_PATH) / STUD_SIZE;
				Rewrite(Edit(FILE_PATH), FILE_PATH, struct_count);
		}
	} while (select >= 1 && select <= 6);
	_fcloseall();
	return 0;
}

long GetFileSize(const char* filepath)
{
	FILE* fptr = fopen(filepath, "rb");
	fseek(fptr, 0L, SEEK_END);
	long fileSize = ftell(fptr);
	return fileSize;
}
void Rewrite(Student* stud, const char* filepath, int struct_count)
{
	FILE* fw = fopen(filepath, "wb");
	for (int i = 0; i < struct_count; ++i)
	{
		fwrite(&stud[i], STUD_SIZE, 1, fw);
	}
	delete[] stud;
	fclose(fw);
}
void Create_New(const char* filePath)
{
	FILE* fp = fopen(filePath, "wb");
	fclose(fp);
}

Student* Edit(const char* filepath)
{
	char FIO[50];
	short select;
	cout << "Введите ФИО студента для редактирования" << endl;
	cin.ignore();
	cin.getline(FIO, 50);
	long struct_count = GetFileSize(filepath) / STUD_SIZE;
	FILE* fpt1 = fopen(filepath, "rb");
	Student* stArray = new Student[struct_count];
	for (int i = 0; i < struct_count; i++)
	{
		fread(&stArray[i], STUD_SIZE, 1, fpt1);
		if (*(stArray[i].FIO) == *FIO)
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
					cin >> stArray[i].FIO;
					break;
				case 2:
					cout << "введите новый номер группы" << endl;
					cin >> stArray[i].groupNumber;
					break;
				case 3:
					cout << "Введите новую Оценку по физике" << endl;
					cin >> stArray[i].phys_mark;
					break;
				case 4:
					cout << "Введите новую Оценку по математике" << endl;
					cin >> stArray[i].math_mark;
					break;
				case 5:
					cout << "Введите новую Оценку по информматике" << endl;
					cin >> stArray[i].inf_mark;
					break;
				}
			} while (select > 1 && select < 6);
		}
		stArray[i].average = (stArray[i].inf_mark + stArray[i].math_mark + stArray[i].phys_mark) / 3;
	}
	return stArray;
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
