
// 1+.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

int* sort_row(int* row, int size)
{
	int t;
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = i + 1; j < size; j++)
		{
			if (row[i] > row[j]) 
			{
				t = row[i];
				row[i] = row[j];
				row[j] = t;
			}
		}
	}
	return row;
}

void Print(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(7) << matrix[i][j];
		}
		cout << endl;
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	cin >> n >> m;
	int** A;
	A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];
	cout << "введите элементы матрицы" << endl;
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "]=";
			cin >> A[i][j];
		}
		cout << endl;
	}
	Print(A, n, m);
	cout << "---------------------------------" << endl;
	int** B = new int*[n];
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		sort_row(A[i], m);
	}
	Print(A, n, m);
	cout << "---------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		int counter = 0;
		int reps = 0;
		for (int j = 0; j < m; j++) {
			if (A[i][j] == A[i][j + 1]) {
				counter++;
				reps++;
				continue;
			}
			temp[i] = reps;
			reps = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << temp[i]<<setw(2);
	}
	cout << "---------------------------------" << endl;
	for (int i = 0; i < n; i++) 
	{
		int size = temp[i];
		int index = 0;
		B[i] = new int[size];
		for (int j = 0; j < m-1; j++) 
		{
			for (int y = 0; y < m; y++) 
			{
				if (A[i][j] == A[i][j+1]) 
				{
					B[i][index++] = A[i][y];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int current_size = temp[i];
		for (int j = 0; j < current_size; j++) 
		{
			cout << setw(7) << B[i][j];
		}
		cout << endl;
	}
	delete[] A;
	delete[] B;
	delete[] temp;

	return 0;
}

