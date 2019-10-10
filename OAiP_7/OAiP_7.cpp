
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "student.h"



using namespace std;
void Flush_Stream() {
	while (cin.get() != '\n') {};
}
void Output(Student* stud) {
	cout << "=========================++++++++++++============================" << endl;
	cout << "Имя: " << stud->FIO << "\nНомер группы: " << stud->groupNumber << "\n\t+-------------------+" << endl;
	cout << "Средний балл по физикие: " << stud->phys_mark << endl;
	cout << "Средний балл по математике: " << stud->math_mark << endl;
	cout << "Средний балл по информатике: " << stud->inf_mark << endl;
	cout << "=========================++++++++++++============================" << endl;
}

bool Create_New(const char* filePath) {
	FILE* fp = fopen(filePath, "wb");
	return fp == NULL ? false : true;
}

void Open_Read(const char* filePath) {
	FILE* fp2 = fopen(filePath, "rb");
	Student st;
	while (true) {
		if(!fread(&st.FIO, sizeof(st.FIO), 1, fp2)) break;
		fread(&(st.groupNumber), 4, 1, fp2);
		fread(&(st.inf_mark), 8, 1, fp2);
		fread(&(st.phys_mark), 8, 1, fp2);
		fread(&(st.math_mark), 8, 1, fp2);
		Output(&st);
	}
	fclose(fp2);
}
bool Append(const char* filePath, Student* ptr) {
	try {
		FILE* fp1 = fopen(filePath, "ab");
		if (fp1 == NULL) throw("Error opening file!");
		fwrite(&ptr->FIO, sizeof(ptr->FIO), 1, fp1);
		fwrite(&ptr->groupNumber, 4, 1, fp1);
		fwrite(&ptr->inf_mark, 8, 1, fp1);
		fwrite(&ptr->phys_mark, 8, 1, fp1);
		fwrite(&ptr->math_mark, 8, 1, fp1);
		fclose(fp1);
		return true;
	}
	catch (const char* error) {
		cout << error;
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	short select;

	do {
		char* FILE_PATH = new char[100];
		cout << "Выберите желаемое действие:\n\t 1.Создать файл\n\t 2.Открыть файл\n\t 3.Добавить новую запись\n\t 4.Выход из программы\n\t" << endl;
		cin >> select;
		switch (select) {
			case 1: 
				cout << "Введите имя нового файла" << endl;
				cin >> FILE_PATH;
				if (!Create_New(FILE_PATH)) {
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
				Student* StudPtr = new Student;
				cout << "введите имя октрываемого файла:" << endl;
				cin >> FILE_PATH;
				cout << "Введите ФИО студента" << endl;
				cin.sync_with_stdio();
				cin >> StudPtr->FIO;
				cout << "Введите номер группы" << endl;
				cin >> StudPtr->groupNumber;
				cout << "Введите средний балл по математике, физике, информатике через пробел." << endl;
				cin >> StudPtr->math_mark >> StudPtr->phys_mark >> StudPtr->inf_mark;
				if (!Append(FILE_PATH, StudPtr)) {
					break;
				};
				delete StudPtr;
				break;
		}
	} while (select == 1 || select == 2 || select == 3);
	_fcloseall();
	return 0;
}