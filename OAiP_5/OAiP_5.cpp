// OAiP_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>
#include "OAiP_5.h"
using namespace std;

void Print(double** matrix, int n, int m);
double** RandomFill(double** matrix, int n, int m);
double** InputData(double** matrix, int n, int m);
bool Scalar_Product(double** matrix, int n);
bool Scalar_Row(double** matrix, int n);
double Sum(double* line, int size);




//уровень 1

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int n, m;
//	cout << "Введите размер матрицы n*m" << endl;
//	cin >> n >> m;
//	double** matrix;
//	matrix = new double* [n];
//	for (int i = 0; i < n; ++i) 
//	{
//		matrix[i] = new double [m];
//	}
//	cout << "введите элементы матрицы" << endl;
//	cout << endl;
//	for (int i = 0; i < n; ++i) 
//	{
//		for (int j = 0; j < m; ++j) 
//		{
//			cout << "[" << i << "]" << "[" << j << "]=";
//			cin >> matrix[i][j];
//
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			if (matrix[i][j] < 0) 
//			{
//				cout << "Сумма в " << i+1 << " строке = " << Sum(matrix[i], m) << endl;
//				break;
//			}
//		}
//	}
//	delete[] matrix;
//	return 0;
//}
//
//// уровень 2
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	int n, m;
//	cout << "Введите размер матрицы n*m" << endl;
//	cin >> n >> m;
//	double** matrix;
//	matrix = new double* [n];
//	for (int i = 0; i < n; ++i) 
//	{
//		matrix[i] = new double[m];
//	}
//	short selector;
//	cout << "1. Заполнить рандомно.\n2. Ввод с клавиатуры.\n";
//	cin >> selector;
//	switch (selector) 
//	{
//		case 1:
//			matrix = RandomFill(matrix, n, m);
//			break;
//		case 2:
//			matrix = InputData(matrix, n, m);
//			break;
//	}
//	cout << "---------------------------" << endl;
//	double* tmp;
//	for (int i = 0; i < n - 1; i++) 
//	{
//		for (int j = i + 1; j < n; j++) 
//		{
//			if (*matrix[i] > *matrix[j]) 
//			{
//				tmp = matrix[i];
//				matrix[i] = matrix[j];
//				matrix[j] = tmp;
//			}
//		}
//	}
//	cout << "Результат сортировки строк по первым элементам" << endl;
//	cout << "---------------------------" << endl;
//	Print(matrix, n, m);
//	delete[] matrix;
//	return 0;


//уровень 3

int main() {
	setlocale(LC_ALL, "Russian");
	int n ;
	cout << "Введите размер матрицы n" << endl;
	cin >> n ;
	double** matrix;
	matrix = new double* [n];
	for (int i = 0; i < n; ++i) 
	{
		matrix[i] = new double[n];
	}
	short selector;
	cout << "1. Заполнить рандомно.\n2. Ввод с клавиатуры.\n";
	cin >> selector;
	switch (selector) {
	case 1:
		matrix = RandomFill(matrix, n, n);
		break;
	case 2:
		matrix = InputData(matrix, n, n);
		break;
	}
	cout << "---------------------------" << endl;
	if (Scalar_Product(matrix, n) && Scalar_Row(matrix, n)) 
	{
		cout << "Матрица является ортонормированной" << endl;
		delete[] matrix;
	}
	else 
	{
		cout << "Матрица НЕ является ортонормированной" << endl;
		delete[] matrix;
	}
	return 0;
}

bool Scalar_Row(double** matrix, int n) 
{
	for (int i = 0; i < n; ++i) 
	{
		double product = 0;
		for (int j = 0; j < n; j++) 
		{
			product += matrix[i][j] * matrix[i][j];
		}
		if (product != 1) return false;
	}
	return true;
}

bool Scalar_Product(double** matrix, int n) 
{
	for (int i = 0; i < n-1; ++i) 
	{
		double product = 0;
		for (int j = 0; j < n; j++) 
		{
			product += matrix[i][j] * matrix[i + 1][j];
		}
		if (product != 0) return false;
	}
	return true;
}


void Print(double** matrix, int n, int m) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cout << setw(7) << matrix[i][j];
		}
		cout << endl;
	}
}
double** RandomFill(double** matrix, int n, int m) 
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			matrix[i][j] = -50 + double(rand() % 10000) / 100;
		}
	}
	cout << "Сгенерированная матрица:\n";
	Print(matrix, n, m);
	return matrix;
}
double** InputData(double** matrix, int n, int m) 
{
	cout << "введите элементы матрицы" << endl;
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "]=";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	cout << "Введенная матрица:\n";
	Print(matrix, n, m);
	return matrix;
}

double Sum(double* line, int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += line[i];
	}
	return sum;
}
