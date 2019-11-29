// OAiP_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>


using namespace std;

void InputData(const char* arrName, int* arrPtr, int arrSize);
void RandomFill(int* arrPtr, int arrSize);
void PrintArray(const char* arrayName, int* array, int size);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива" << endl;
	cin >> n;
	double* array = new double[n];
	int i_m = 0;
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		cout << "array[" << i << "]=";
		cin >> array[i];
	}
	for (int i = 0; i < n; ++i) {
		if (array[i]< array[i_m]) {
			i_m = i;
		}
	}
	if (i_m == 0) {
		cout << "подохдящих для суммирования элементов нет!";
		delete[] array;
		return 0;
	}
	for (int i = 0; i < i_m; ++i) {
		sum += array[i];
	}
	cout << "Сумма до минимального элемента="<<sum;
	delete[] array;
	return 0;
}


//int main() {
//	srand(time(NULL));
//	
//	setlocale(LC_ALL, "Russian");
//	short select;
//	int size, sum = 0, i_p=-1, i_n=-1;
//	cout << "Введите размер массива, от 1 до 20" << endl;
//	cin >> size;
//	while (size < 1 || size > 20) {
//		cout << "Неверно введен размер, повторите ввод от 1 до 20" << endl;
//		cin.clear();
//		cin >> size;
//	}
//	int* array = new int [size];
//	RandomFill(array, size);
//	cout << "Выберите способ ввода данных в массив:\n 1.Cлучайные числа\n 2.Ввод пользовательских данных" << endl;
//	cin >> select;
//	while (select != 1 && select != 2) {
//		cout << "Неверный выбор!!!" << endl;
//		cin.clear();
//		cin >> select;
//	}
//	if (select == 1) {
//		RandomFill(array, size);
//		PrintArray("array", array, size);
//	}
//	else InputData("array", array, size);
//	for (int i = 0; i < size; i++) {
//		if (array[i] > 0) {
//			i_p = i;
//			break;
//		}
//	}
//	if (i_p == -1) {
//		cout << "нет положительных элементов " << endl;
//		delete[] array;
//		return -1;
//	}
//	for (int i = 0; i < size; ++i) {
//		if (array[i] < 0) {
//			i_n = i;
//			break;
//		}
//	}
//	if (i_n == -1) {
//		cout << "Нет отрициательных элементов";
//		delete[] array;
//		return -1;
//	}
//	if (i_n == i_p+1 || i_p==i_n+1) {
//		cout << "Складывать нечего, положительный и отрицательный находятся рядом";
//		delete[] array;
//		return -1;
//	}
//	if (i_n > i_p) {
//		for (int i = ++i_p; i < i_n; ++i) {
//			sum += array[i];
//		}
//	}      
//	else {
//		for (int i = --i_p; i > i_n; --i) {
//			sum += array[i];
//		}
//	}
//	cout << "Сумма элементов от первого положительного до первого отрицательного = " << sum << endl;
//	delete[] array;
//	return 0;
//}
//
//int Solve(int* array1, int* array2, int size1, int size2) {
//	int min=array1[0], i, j;
//	bool flag;
//	for (i = 0; i < size1; ++i) {
//		flag = false;
//		if (array1[i] < min) 
//		{
//			for (j = 0; j < size2; j++) 
//			{
//				if (array1[i] == array2[j]) 
//				{
//					flag = true;
//					break;
//				}
//			}
//			if (!flag) {
//				min = array1[i];
//			}
//		}
//	}
//	return min;
//}
//
//
//
//int main() 
//{
//	setlocale(LC_ALL, "Russian");
//	short select;
//	int size1, size2, result;
//	cout << "Введите размер первого массива" << endl;
//	cin >> size1;
//	cout << "Введите размер второго массива" << endl;
//	cin >> size2;
//	int* array1 = new int[size1];
//	int* array2 = new int[size2];
//	cout << "Выберите способ ввода данных в массив:\n 1.Cлучайные числа\n 2.Ввод пользовательских данных" << endl;
//	cin >> select;
//	while (select != 1 && select != 2) {
//		cout << "Неверный выбор!!!" << endl;
//		cin.clear();
//		cin >> select;
//	}
//	if (select == 1) {
//		RandomFill(array1, size1);
//		PrintArray("Array1", array1, size1);
//		cout << "---------------------------------" << endl;
//		RandomFill(array2, size2);
//		PrintArray("Array2", array2, size2);
//	}
//	else {
//		cout << "Введите данные первого массива" << endl;
//		InputData("array1", array1, size1);
//		cout << "Введите данные второго массива" << endl;
//		InputData("array2", array2, size2);
//	}
//	result = Solve(array1, array2, size1, size2);
//
//	cout << "Минимальное из первого массива, не входящее во второй массив = " << result << endl;
//	delete[] array1;
//	delete[] array2;
//	return 0;
//}
//
//void RandomFill(int* arrPtr, int arrSize) {
//	for (int i = 0; i < arrSize; i++) {
//		arrPtr[i] = -10.5 + rand() % 21;
//	}
//}
//
//void InputData(const char* arrName, int* arrPtr, int arrSize) {
//	for (int i = 0; i < arrSize; i++) {
//		cout << arrName << "[" << i << "]=";
//		while (!(cin >> arrPtr[i]) || cin.get() != '\n') {
//			cout << "Вы ввели не число, повторите ввод элемента" << endl;
//			cout << arrName << "[" << i << "]=";
//			cin.clear();
//			while (cin.get() != '\n');
//		}
//	}
//}
//void PrintArray(const char* arrayName, int* array, int size) {
//	for (int i = 0; i < size; ++i) {
//		cout << arrayName << "[" << i << "] = " << array[i] << endl;
//	}
//}