// OAiP_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>
using namespace std;

double Sum(double* line, int size) 
{
	double sum = 0;
	for (int i = 0; i < size; ++i) 
	{
		sum += line[i];
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите размер матрицы n*m" << endl;
	cin >> n >> m;
	double** matrix;
	matrix = new double* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double [m];
	}
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
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] < 0) 
			{
				cout << "Сумма в " << i+1 << " строке = " << Sum(matrix[i], m);
			}
		}
	}
	delete[] matrix;
	return 0;
}

