// OAiP_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
/*
double Y(double x);
double S(double x);
double Out_Rez(double x(double f), double a, double b, double h);

int main()
{
	setlocale(LC_ALL, "Russian");
	double a,b,h;
	short select;
	cout << "Введите a, b,h" << endl;
	cin >> a >> b >> h;
	cout << "Выберите функцию для расчета:\n 1. Y(x) 2. S(x)" << endl;
	cin >> select;
	switch (select) {
		case 1:	
			cout << "Результат вычисления Y(x)= " << Out_Rez(Y, a, b, h);
			return 0;
		case 2:
			cout << "Результат вычисления S(x)= " << Out_Rez(S, a, b, h);
			return 0;
	}
	return 0;
}

double Y(double x) {
	return -1. / 2 * log(1 - 2 * x * cos(M_PI / 3) + x * x);
}

double S(double x) {
	double r = 1;
	double s = 0;
	for (int k = 1; k < 100; k++) {
		r *= x;
		s+= r * cos(k * M_PI / 3) / k;
	}
	return s;
}

double Out_Rez(double t(double f), double a, double b, double h){
	double result = 0;
	for (double x = a; x < b; x += h) {
		result = t(x);
	}
	return result;
}
*/

/*
double sqrt_recursive(double a, double x, double x_prev);
double sqrt_nonRecursive(double a, double x);

int main() {

	setlocale(LC_ALL, "Russian");
	double a,x, x_prev=-1;
	cout << "Введите Х для выичсления корня" << endl;
	cin >> a;
	x = 0.5 * (1 + a);
	cout << "Результат, вычисленный при помощи рекурсивной функции = " << sqrt_recursive(a,x, x_prev) << endl;
	cout << "Результат, вычисленный без использования рекурсии" << sqrt_nonRecursive(a,x) << endl;
	return 0;
}

double sqrt_recursive(double a, double x, double x_prev) {
	while (x_prev != x) {
		x_prev = x;
		x = sqrt_recursive(a, 1. / 2 * (x + a / x), x_prev);
	}
	return x;
}

double sqrt_nonRecursive(double a, double x) {
	for (int k = 0; k < 100; k++) {
		x =  1. / 2 * (x + a / x);
	}
	return x;
}*/

/*
double Y(double x);
double Out_Rez(double t(double f), double x);

int main() {
	setlocale(LC_ALL, "Russian");
	double x, a, b ,h;
	cout << "Введите значения a, b , h" << endl;
	cin >> a >> b >> h;
	for (x = a; x < b; x += h) {
		cout << "Результат вычисления при x = " << x <<"\tравен = " <<Out_Rez(Y, x) << endl;
	}
	return 0;
}

double Y(double x) {
	return x * x * sqrt(15 + 10 * sin(x + M_PI));
}
double Out_Rez(double t(double f), double x) {
	return  t(x);
}*/