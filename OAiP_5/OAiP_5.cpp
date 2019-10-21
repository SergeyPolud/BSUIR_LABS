// OAiP_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int n, j, m;
	cin >> n;
	cin >> m;
	int* b = new int[m];
	for (int i = 0; i < m; ++i) {
		b[i] = 0;
	}
	double** mas;
	mas = new double*[n];
	for (int i = 0; i < n; ++i) {
		mas[i] = new double[m];
	}
	for (int i = 0;i < n; i++) {
		for (int j = 0; j < m; ++j) {
			cin >> mas[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; ++j) {
			cout << setw(15) << mas[i][j];
		}
		cout << endl;
	}


	
	for (j = 0; j < m; j++) {
		b[j]=0;
		for (int i = 0; i < n; ++i) {
			if (mas[i][j] != 0) {
				b[j] = 1;
				break;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) cout << b[i];

	for (int i = 0; i < n; ++i) {
		delete[] mas[i];
	}
	delete[] mas;
	return 0;
}

