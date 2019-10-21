// OAiP_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

void InputData(int* arrPtr, int arrSize);
void RandomFill(int* arrPtr, int arrSize);
void PrintArray(const char* arrayName, int* array, int size);
/*
int main()
{
	
	int index=0, n;
	cout << "Введите размер массива" << endl;
	cin >> n;
	double* array = new double[n];
	int i_v = 0;
	double sum=0;
	for (int i = 0; i < n; ++i) {
		cout << "array[" << i << "]=";
		cin >> array[i];
	}
	for (int i = 0; i < n; ++i) {
		if (array[i]< array[i_v]) {
			i_v = i;
		}
	}
	if (i_v == 0) {
		cout << "подохдящих для суммирования элементов нет!";
		return 0;
	}

	for (int i = 0; i < i_v; ++i) {
		sum += array[i];
	}
	cout << "Сумма до первого минимального элемента="<<sum;
	delete[] array;
	return 0;
}*/


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	short select;
	int size, sum = 0, i_p=-1, i_n=-1;
	cout << "Введите размер массива, от 1 до 20" << endl;
	cin >> size;
	while ((size < 1 || size > 20)) {
		cout << "Неверно введен размер, повторите ввод от 1 до 20" << endl;
		cin.clear();
		cin >> size;
	}
	int* array = new int[size];
	cout << "Выберите способ ввода данных в массив:\n 1.Cлучайные числа\n 2.Ввод пользовательских данных" << endl;
	cin >> select;
	while (select != 1 && select != 2) {
		cout << "Неверный выбор!!!" << endl;
		cin.clear();
		cin >> select;
	}
	if (select == 1) {
		RandomFill(array, size);
		PrintArray("array", array, size);
	}
	else InputData(array, size);
	for (int i = 0; i < size; i++) {
		if (array[i] > 0) {
			i_p = i;
			break;
		}
	}
	for (int i = i_p; i < size; ++i) {
		if (array[i] < 0) {
			i_n = i;
			break;
		}
	}
	if (i_n == i_p+1) {
		cout << "Складывать нечего, положительный и отрицательный находятся рядом";
		return -1;
	}
	if (i_n == -1) {
		cout << "нет отрицательных элементов после положительного" << endl;
		return -1;
	}
	if (i_p == -1) {
		cout << "Нет положительных элементов";
		return -1;
	}
	for (int i = ++i_p; i < i_n; ++i) {
		sum += array[i];
	}
	cout << "Сумма элементов от первого положительного до первого отрицательного = " << sum << endl;
	delete[] array;
	return 0;
}

/*int Solve(int* dynamicArray1, int* dynamicArray2, int size1, int size2) {
	int min = INT_MAX, i, j;
	bool flag=false;
	for (i = 0; i < size1; ++i) {
		if (dynamicArray1[i] < min) {
			for (j = 0; j < size2; j++) {
				if (dynamicArray1[i] == dynamicArray2[j]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				flag = false;
				continue;
			}
			else {
				min = dynamicArray1[i];
				flag = false;
			}
		}
	}
	return min;
}



int main() 
{
	setlocale(LC_ALL, "Russian");
	short select;
	int size1, size2, result;
	cout << "Введите размер первого массива" << endl;
	cin >> size1;
	cout << "Введите размер второго массива" << endl;
	cin >> size2;
	int* dynamicArray1 = new int[size1];
	int* dynamicArray2 = new int[size2];
	cout << "Выберите способ ввода данных в массив:\n 1.Cлучайные числа\n 2.Ввод пользовательских данных" << endl;
	cin >> select;
	while (select != 1 && select != 2) {
		cout << "Неверный выбор!!!" << endl;
		cin.clear();
		cin >> select;
	}
	if (select == 1) {
		RandomFill(dynamicArray1, size1);
		PrintArray("dynamicArray1", dynamicArray1, size1);
		cout << "---------------------------------" << endl;
		RandomFill(dynamicArray2, size2);
		PrintArray("dynamicArray2", dynamicArray2, size2);
	}
	else {
		cout << "Введите данные первого массива" << endl;
		InputData(dynamicArray1, size1);
		cout << "Введите данные второго массива" << endl;
		InputData(dynamicArray2, size2);
	}
	result = Solve(dynamicArray1, dynamicArray2, size1, size2);
	cout << "Минимальное из первого массива, не входящее во второй массив = " << result << endl;
	return 0;
}*/

void RandomFill(int* arrPtr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arrPtr[i] = -100 + rand() % 1000;
	}
}

void InputData(int* arrPtr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << "array[" << i << "]=";
		while (!(cin >> arrPtr[i]) || cin.get() != '\n') {
			cout << "Вы ввели не число, повториве ввод элемента" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
void PrintArray(const char* arrayName, int* array, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arrayName << "[" << i << "] = " << array[i] << endl;
	}
}