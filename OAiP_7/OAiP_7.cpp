#define _CRT_SECURE_NO_WARNINGS
#define ST_SIZE sizeof(Student)
#include <iostream>
#include "student.h"
#include <Windows.h>

using namespace std;

int strlen_custom(char*);
int strcmp(char*, char*, int, int);
long GetFileSize(FILE*);
void Save_Entry(Student*, FILE*);
bool Create_New(const char*);
void Edit(FILE*);
void Output(Student*);
void Open_Read(const char*);
bool Append(const char*, Student*);
Student* DeleteEntry(FILE*);
Student* SortByAlphabetic(FILE*);
Student* SortByGroupDec(FILE*);
Student* SortByGroupInc(FILE*);
Student* SortByAverageDec(FILE*);
Student* SortByAverageInc(FILE*);

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
		cin.ignore();
		cin.getline(path, 100);
		if (!Create_New(path))
		{
			cout << "Ошибка создания файла!!!!";
		}
		cout << "Успешно создан новый файл " << path << endl;
	}while(ch == 2);
	do 
	{
		int struct_cnt;
		FILE* f_ptr;
		Student Stud;
		Student* sorted_arr;
		Student* arr;
		cout << "Выберите желаемое действие: \n\t 1.Сортировка \n\t 2.Прочитать файл \n\t 3.Добавить новую запись \n\t 4.Найти студентов, имеющих не ниже 4 по математике \n\t 5.Редактировать \n\t 6.Удалить запись \n\t 7.Выход" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			f_ptr = fopen(FILE_PATH, "a+");
			cout << "\n\t 1. Сортировка по номеру группы. \n\t 2. Сортировка по имени(алфавиту). \n\t 3. Сортировка по среднему баллу. \n\t 4. Выход" << endl;
			short sort_select;
			cin >> sort_select;
			switch (sort_select) 
			{
			case 1:
					cout << "\n\t 1. По убыванию. \n\t 2. По возрастанию." << endl;
					cin >> sort_select;
					if(sort_select==1)
					sorted_arr = SortByGroupDec(f_ptr);
					else
					sorted_arr = SortByGroupInc(f_ptr);

				 struct_cnt = GetFileSize(f_ptr) / ST_SIZE;
				 fclose(f_ptr);
				 f_ptr = fopen(FILE_PATH, "wb");
				 for (int i = 0; i < struct_cnt; i++)
					 fwrite(&sorted_arr[i], ST_SIZE, 1, f_ptr);
				 delete[] sorted_arr;
				 break;
			case 2:
				sorted_arr = SortByAlphabetic(f_ptr);
				struct_cnt = GetFileSize(f_ptr) / ST_SIZE;
				fclose(f_ptr);
				f_ptr = fopen(FILE_PATH, "wb");
				for (int i = 0; i < struct_cnt; i++)
					fwrite(&sorted_arr[i], ST_SIZE, 1, f_ptr);
				delete[] sorted_arr;
				break;
			case 3:
					cout << "\n\t 1. По убыванию. \n\t 2. По возрастанию." << endl;
					cin >> sort_select;
					if(sort_select == 1)
						sorted_arr = SortByAverageDec(f_ptr);
					else
						sorted_arr = SortByAverageInc(f_ptr);
				struct_cnt = GetFileSize(f_ptr) / ST_SIZE;
				fclose(f_ptr);
				f_ptr = fopen(FILE_PATH, "wb");
				for (int i = 0; i < struct_cnt; i++)
				fwrite(&sorted_arr[i], ST_SIZE, 1, f_ptr);
				delete[] sorted_arr;
				break;
			}
			fclose(f_ptr);
			cout << "\nФайл успешно отсортирован" << endl;
			break;
		case 2:
			Open_Read(FILE_PATH);
			break;
		case 3:
			cout << "Введите ФИО студента" << endl;
			cin.ignore();
			cin.getline(Stud.FIO, 50);
			cout << "Введите номер группы" << endl;
			cin >> Stud.groupNumber;
			cout << "Введите оценку по математике, физике, информатике." << endl;
			cin >> Stud.math_mark >> Stud.phys_mark >> Stud.inf_mark;
			Stud.average = (Stud.inf_mark + Stud.math_mark + Stud.phys_mark) / 3;
			if (!Append(FILE_PATH, &Stud))
			{
				cout << "Ошибка добавления!" << endl;
				break;
			};
			break;
		case 4:
			f_ptr = fopen(FILE_PATH, "rb");
			while (fread(&Stud, ST_SIZE, 1, f_ptr) != NULL)
			{
				if (Stud.math_mark >= 4 && Stud.inf_mark >= 4)
				{
					Output(&Stud);
				}
			}
			fclose(f_ptr);
			break;
		case 5:
			f_ptr = fopen(FILE_PATH, "r+");
			Edit(f_ptr);
			fclose(f_ptr);
			break;
		case 6:
			f_ptr = fopen(FILE_PATH, "r");
			if ((arr = DeleteEntry(f_ptr)) != NULL)
			{
				struct_cnt = ftell(f_ptr) / ST_SIZE - 1;
				fclose(f_ptr);
				f_ptr = fopen(FILE_PATH, "wb"); //Clears the file
				for (int i = 0; i < struct_cnt; i++)
					fwrite(&arr[i], ST_SIZE, 1, f_ptr);
				fclose(f_ptr);
				delete[] arr;
				break;
			}
			else 
			{
				cout << "Ошибка удаления!" << endl;
				fclose(f_ptr);
				break;
			}
		}
	} while (select >= 1 && select <= 6);
	_fcloseall();
	return 0;
}

Student* SortByGroupDec(FILE* f_ptr) 
{

	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student temp;
	Student* struct_arr = new Student[struct_count];
	fseek(f_ptr, 0, SEEK_SET);
	for (int i = 0; i < struct_count; i++)
	{
		int chck = fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count-1; i++) 
	{
		for(int j = i+1; j < struct_count; ++j)
		{
			if (struct_arr[i].groupNumber < struct_arr[j].groupNumber) 
			{
				temp = struct_arr[i];
				struct_arr[i] = struct_arr[j];
				struct_arr[j] = temp;
			}
		}
	}
	return struct_arr;
}
Student* SortByGroupInc(FILE* f_ptr)
{
	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student temp;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++)
	{
		fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count - 1; i++)
	{
		for (int j = i + 1; j < struct_count; ++j)
		{
			if (struct_arr[i].groupNumber > struct_arr[j].groupNumber)
			{
				temp = struct_arr[i];
				struct_arr[i] = struct_arr[j];
				struct_arr[j] = temp;
			}
		}
	}
	return struct_arr;
}

Student* SortByAlphabetic(FILE* f_ptr)
{
	Student temp;
	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++)
	{
		fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count - 1; i++)
	{
		for (int j = i + 1; j < struct_count; ++j)
		{
			if (strcmp(struct_arr[i].FIO, struct_arr[j].FIO, strlen_custom(struct_arr[j].FIO), strlen_custom(struct_arr[j].FIO)) == 1)
			{
				temp = struct_arr[i];
				struct_arr[i] = struct_arr[j];
				struct_arr[j] = temp;
			}
		}
	}
	return struct_arr;
}

Student* SortByAverageDec(FILE* f_ptr)
{
	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student temp;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++)
	{
		fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count - 1; i++)
	{
		for (int j = i + 1; j < struct_count; ++j)
		{
			if (struct_arr[i].average < struct_arr[j].average)
			{
				temp = struct_arr[i];
				struct_arr[i] = struct_arr[j];
				struct_arr[j] = temp;
			}
		}
	}
	return struct_arr;
}

Student* SortByAverageInc(FILE* f_ptr)
{
	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student temp;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++)
	{
		fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count - 1; i++)
	{
		for (int j = i + 1; j < struct_count; ++j)
		{
			if (struct_arr[i].average > struct_arr[j].average)
			{
				temp = struct_arr[i];
				struct_arr[i] = struct_arr[j];
				struct_arr[j] = temp;
			}
		}
	}
	return struct_arr;
}

Student* DeleteEntry(FILE* f_ptr)
{
	bool flag = false;
	char FIO[50];
	cout << "Введите ФИО для удаления" << endl;
	cin.ignore();
	cin.getline(FIO, 50);
	long struct_count = GetFileSize(f_ptr) / ST_SIZE;
	Student* struct_arr = new Student[struct_count];
	for (int i = 0; i < struct_count; i++) 
	{
		fread(&struct_arr[i], ST_SIZE, 1, f_ptr);
	}
	for (int i = 0; i < struct_count; i++) 
	{
		if (!strcmp(struct_arr[i].FIO, FIO, strlen_custom(struct_arr[i].FIO), strlen_custom(FIO)))
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
		return nullptr;
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
void Save_Entry(Student* stud, FILE* f_ptr)
{
	int pos = ftell(f_ptr);
	fseek(f_ptr, pos - ST_SIZE, SEEK_SET);
	fwrite(stud, ST_SIZE, 1, f_ptr);
}
bool Create_New(const char* filePath)
{
	FILE* fp = fopen(filePath, "wb");
	if (fp == NULL) return false;
	fclose(fp);
	return true;
}

void Edit(FILE* f_ptr)
{
	do 
	{
		char FIO[50];
		bool flag = false;
		short select;
		Student* stud = new Student;
		cout << "Введите ФИО студента для редактирования, 1 для выхода" << endl;
		cin.ignore();
		cin.getline(FIO, 50);
		if (*FIO == '1') break;
		long struct_count = GetFileSize(f_ptr) / ST_SIZE;
		for (int i = 0; i < struct_count; i++)
		{
			fread(stud, ST_SIZE, 1, f_ptr);
			if (!strcmp(stud->FIO, FIO, strlen_custom(stud->FIO), strlen_custom(FIO)))
			{
				do
				{
					flag = true;
					cout << "Выберите поле для редактирования: \n\t 1-ФИО \n\t 2-Номер группы \n\t 3-Оценка по физике \n\t 4-Оценка по математике \n\t 5-Оценка по иноформатике \n\t" << endl;
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
						Save_Entry(stud, f_ptr);
						break;
					}
				} while (select > 0 && select < 6);
				break;
			}
		}
		if (!flag) cout << "Записи о данном ФИО не существует" << endl;
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
bool Append(const char* filePath, Student* ptr)
{
	FILE* fp1 = fopen(filePath, "ab");
	if (fp1 == NULL) return false;
	fwrite(ptr, ST_SIZE, 1, fp1);
	fclose(fp1);
	return true;
}
int strcmp(char* s1, char* s2, int l1, int l2) 
{
	for (int i = 0; i < l1 && i < l2; i++) 
		if (s1[i] > s2[i]) return 1;
		else if (s1[i] < s2[i]) return -1;
	return 0;
}
int strlen_custom(char* str)
{
	int length = 0;
	while (*str++ != '\0') length++;
	return length;
}