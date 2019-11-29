#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

using namespace std;

struct Students {
	char FIO[50]; //Group[5];
	char birthday[12];
	int group, phys, math, inf;
	double sball;
}student;


FILE* FD, * FR;
char File_Data[] = "data.dat";
char File_Rez[] = "rezult.txt";



// function's prototype
void Create();             
bool ShowAll();
void Add();
void Out(Students);
//void Save(Students*, int);
//void Task();


int main() {
	setlocale(LC_ALL, "Russian");
	//int edit_number;
	
	while (true) {
		cout << "Выберите необходимый вариант  " << endl;
		cout<<"\n 1 - Создание файла \t 2 - Просмотр  \t 3 - Редактирование  \t 4 - Задание \t 5 - Выход \n"<<endl;
			switch (_getch())
			{
			case '1': 
				FD = fopen(File_Data, "wb");
				if (FD==NULL) {   //????
					cout<<"Ошибка при создании!"<<endl;
					return 0;
				}
				cout << "Новый файл " << File_Data << " успешно создан " << endl;
				Create();
				fclose(FD);
				break;

			case '2':
			      // просматриваем
				if (!ShowAll()) {
					cout<<"Ошибка просмотра!"<<endl;
					return 0;
				}
			break;

			case '3': cout<<"\n  Добавьте новую запись "<<endl;
				//switch (_getch()) {
				//case '1':
				   Add();
				//	cout<<"Добавьте новую строку"<<endl;
					//break;
				//case '2': ShowAll();
				//	cout << "Введите номер записи, которую хотите изменить: " << endl;
				//	cin >> edit_number;
				//	Edit(edit_number);
				//	break;
				//}
			break;
			
			//case '4': 
			//	Task();
			//break;

			case '5': 
				fclose(FR);
			return 0;

			default : 
				cout << "Вы выбрали неверное значение. Повторите попытку" << endl;
			}
	}
	system("pause");
	return 0;
}


void Create() {
	
	int i, n;
	cout << "Enter number of students n: ";
	cin >> n;
	Students* Stud;
	Stud = new Students[n];
	for (i = 0; i < n; ++i)
	{
		cout << " ФИО - ";
		//fflush(stdin);
		getchar();
		gets_s(student.FIO);
		cout << "Дата рождения - ";
		cin >> student.birthday;
		cout << "Номер группы - ";
		cin >> student.group;                 //????????
		cout << "Введите балл по физике ";
		cin >> student.phys;
		cout << "Введите балл по математике ";
		cin >> student.math;
		cout << "Введите балл по информатике ";
		cin >> student.inf;
		student.sball = (student.phys + student.math + student.inf) / 3;
		cout << "Средний балл " << student.sball << endl << endl;
	}
	
	/*cout << "\n Spisok " << endl;
	for (i = 0; i < n; i++)
	{
	  Out(Students);
	}*/
	

	delete[]Stud;
}



bool ShowAll() {
	if ((FD=fopen(File_Data, "rb")) == NULL) {
		cout << "При открытии произошла ошибка " << endl;
		return false;
	}
	FR = fopen(File_Rez, "a");
	cout << "\t Информация о студентах " << endl << FR << endl;
	fprintf(FR, "Информация о студетах\n");

	while (true) {
		if (!fread(&student, sizeof(Students), 1, FD)) break;
		Out(student);
	}
	fclose(FD);
	fclose(FR);
	return true;
}

void Add() {
	
	FD = fopen(File_Data, "ab");
	cout << " ФИО - ";
	fflush(stdin);
	//getchar();
	gets_s(student.FIO);
	cout << "Дата рождения - ";
	cin >> student.birthday;
	cout << "Номер группы - ";
	cin>>student.group;                 //????????
	cout << "Введите балл по физике ";
    cin >> student.phys;
	cout << "Введите балл по математике ";
	cin >> student.math;
	cout << "Введите балл по информатике ";
	cin>> student.inf;
	student.sball = (student.phys + student.math + student.inf) / 3;
	cout << "Средний балл " << student.sball << endl<<endl;
	fwrite(&student, sizeof(Students), 1, FD);
	fclose(FD);
}

void Out(Students stud) {
	cout<< " ФИО - " <<student.FIO<< "\tДата рождения - " << student.birthday<< "\tНомер группы - " <<student.group<<endl<<"балл по физике "<<student.phys<<"\tбалл по математике "<<student.math<<"\tбалл по информатике "<<student.inf<<"\tсредний балл "<<student.sball<<endl;
	fprintf(FR, "\nFIO - %s\n Data of birthday: %s\n Group: %i\n Phys: %i\n Math: %i\n Inf: %s\n Sball: %lf\n", student.FIO, student.birthday, student.group, student.phys, student.math, student.inf, student.sball);
}


/*
void Edit(int edit_number) {
	Students* a, newStudent;
	int descriptor, i, col;
	long int len;
	cout << "Добавление студента: \nFIO -  ";
	gets_s(newStudent.FIO);
	cout << "Дата рождения - ";
	cin >> newStudent.birthday;
	cout << "Группа - ";
	cin >> newStudent.group;
	cout<<"Введите балл по: физике, математике, информатике - "; 
	cin >> newStudent.phys >> newStudent.math >> newStudent.inf;
	newStudent.sball = (newStudent.math + newStudent.phys + newStudent.inf) / 3;
	FD = fopen(File_Data, "rb");
	descriptor = _fileno(FD);
	len = _filelength(descriptor);
	col = len / sizeof(Students);
	a = new Students[col];
	for (int i = 0; i < col; i++)
	{
		fread((a + i), sizeof(Students), 1, FD);
	}
	fclose(FD);
	a[edit_number - 1] = newStudent;
	for (int i = 0; i < col; i++)
	{
		Out(a[i], i + 1);
	}
	Save(a, col);
	delete[]a;
}

void Save(Students* a, int num) {
	int i;
	FD = fopen(File_Data, "wb");
	for (int i = 0; i < num; i++)
	{
		fwrite(&a[i], sizeof(Students), 1, FD);
	}
	fclose(FD);
}
*/