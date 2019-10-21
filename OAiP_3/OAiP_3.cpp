// OAiP_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;


double Y(double x);
double S(int& k, double x,  double epsilon);



int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, a, b, h, min,max , result;
	int cnt = 1;
	cout << "Введите a, b, h" << endl;
	cin >> a >> b >> h;
	max = min = a * M_PI * a * M_PI * sqrt(15 + 10 * sin(a * M_PI + M_PI));
	for (x = a * M_PI; x < b * M_PI; x += h) 
	{
		result = x * x * sqrt(15 + 10 * sin(x + M_PI));
		if (result > max) max = result;
		cout << cnt << "-----Значение Х: " << x << "\tРезультат вычисления функции: " << result << endl;
		cnt++;
	}
	for (x = a * M_PI; x < b * M_PI; x += h){
		result = x * x * sqrt(15 + 10 * sin(x + M_PI));
		if(min > result) min = result;
	}
	cout << "Максимальное зачение функции: " << max << endl;
	cout << "Минимальное значение функции: " << min << endl;
	cin.get();
	return 0;
}
/*

int main()
{
	setlocale(LC_ALL, "Russian");
	short select;
	int k;
	
	double r, x, a, b, h, res_s=0, res_y, n, check, px;
	cout << "Введите значения a, b, h" << endl;
	cin >> a >> b >> h;
	
	cout.precision(3);
	for (x = a; x < b; x += h) {
		r = 1;
		px = x;
		res_y = Y(x);
		for (k = 1; k < 25; k++) {
			r = r * px;
			res_s = res_s + r  * cos(k * M_PI / 3) / k;
			cout << "Y(x) = " << res_y << "\tS(x) = " << res_s << endl;
		}
		n = abs(res_y - res_s);
		res_s = 0;
		cout << "Модуль разности = " << n << endl;
		cout << "\n+----------------+\n" << endl;
	}
	system("pause");
	return 0;
}
*/
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	short select;
//	int counter = 0, k = 1;
//	double x, a, b, h, res_s = 0, res_y, n=1, epsilon;
//	cout << "Введите значения a, b, h" << endl;
//	cin >> a >> b >> h;
//	cout << "Выберите значение для проверки:\n 1. 0.001\n 2. 0.0001\n 3. 0000.1" << endl;
//	cin >> select;
//	while (select != 3 && select != 2 && select != 1) {
//		cout << "Неверный выбор!" << endl;
//		while (cin.get() != '\n') {};
//		cin >> select;
//	}
//	switch (select) {
//	case 1:
//		cout << " Выбрано 0.001" << endl;
//		epsilon = 0.001;
//		break;
//	case 2:
//		cout << " Выбрано 0.0001" << endl;
//		epsilon = 0.0001;
//		break;
//	case 3:
//		cout << " Выбрано 0.00001" << endl;
//		epsilon = 0.00001;
//		break;
//	}
//	for (x = a; x < b; x += h) {
//		res_y = Y(x);
//	    res_s = S(k, x, epsilon);
//		n = abs(res_s - res_y);
//		cout << " Значение функции Y(x) = " << res_y;
//		cout << " Значение функции S(x) = " << res_s;
//		cout << " Модуль разности = " << n; 
//		cout << " количество шагов вычисления суммы = " << k << endl;
//		k = 1;
//		n = 1;
//		res_s = 0;
//	}
//	return 0;
//}
//double S(int& k, double x, double epsilon) {
//	double r = 1, res_s=0, t=1;
//	while(abs(t) > epsilon){
//		r *= x;
//		t = r * cos(k * M_PI / 3) / k;
//		res_s += t;
//		k++;
//	}
//	return res_s;
//}
//
//double Y(double x) {
//	return -1. / 2 * log(1 - 2 * x * cos(M_PI / 3) + x * x);
//}