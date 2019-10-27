#include<iostream>
using namespace std;

void Print(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}


void  Min(int** matrix, int n, int& min_r, int& min_c) {
	int min = 9999999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
				min_r = i;
				min_c = j;
			}
		}
	}
}

int** Swap_Columns(int** matrix, int n, int column) {
	int t, j=0;
	for (int i = 0; i < n; i++) {
		t = matrix[i][column];
		matrix[i][column] = matrix[i][column + 1];
		matrix[i][column + 1] = t;
	}
	return matrix;
}

int main()
{
	int n;
	cout << "Enter matrix size" << endl;
	cin >> n;
	int** matrix;
	int min_r = -1;
	int min_c = -1;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "matrix[" << i << "]" << "[" << j << "]=";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	Min(matrix, n, min_r, min_c);
	while (min_c < n-1) {
		matrix = Swap_Columns(matrix, n, min_c);
		cout << "--------------------------------------" << endl;
		Print(matrix, n);
		min_c++;
	}
	while (min_r < n-1) {
		int* t = matrix[min_r];
		matrix[min_r] = matrix[min_r+1];
		matrix[min_r + 1] = t;
		cout << "--------------------------------------" << endl;
		Print(matrix, n);
		min_r++;
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
	Print(matrix, n);
	return 0;
}