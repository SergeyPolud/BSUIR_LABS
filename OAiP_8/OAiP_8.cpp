 //OAiP_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

/*
8.3.1
/*На основании задания, размещенного в п. 3.3.2
написать программу расчета выбранной функции Y(x), S(x), |Y(x)-S(x)|,
вид которой, в свою очередь, передается в качестве параметра в функцию вывода out_rez().
*/

//double Y(double, int);
//double S(double, int);
//double Subtract(double, int);
//void out_rez(double t(double x, int n), double a, double b, double h, int n);
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	double a, b, h;
//	int n;
//	short select;
//	cout << "Enter a, b, h, n" << endl;
//	cin >> a >> b >> h >> n;
//	do {
//		cout << "Choose a function\n 1.Y(x)  2.S(x) 3.|Y(x)-S(x)|" << endl;
//		cin >> select;
//		switch (select) {
//		case 1:
//			out_rez(Y, a, b, h, n);
//			break;
//		case 2:
//			out_rez(S, a, b, h, n);
//			break;
//		case 3:
//			out_rez(Subtract, a, b, h, n);
//			break;
//		}
//	} while (select == 1 || select == 2 || select == 3);
//	return 0;
//}
//
//void out_rez(double t(double x, int n), double a, double b, double h, int n)
//{
//	cout << endl;
//	for (double x = a; x < b; x += h / 2)
//	{
//		cout << t(x, n) << endl;
//	}
//	cout << endl;
//}
//double Y(double x, int n)
//{
//	return -1. / 2 * log(1 - 2 * x * cos(M_PI / 3) + x * x);
//}
//
//double S(double x, int n)
//{
//	double r = 1;
//	double s = 0;
//	for (int k = 1; k < n; k++) {
//		r *= x;
//		s += r * cos(k * M_PI / 3) / k;
//	}
//	return s;
//}
//double Subtract(double x, int n)
//{
//	return abs(Y(x, n) - S(x, n));
//}
//
//
///*
//8.3.2
//На основании задания, размещенного в п. 3.3.3
//написать программу расчета выбранной функции Y(x)
//вид которой, в свою очередь, передается в качестве параметра в функцию вывода out_rez().
//*/
//
//double Y(double, int&, double);
//double S(double, int&, double);
//void out_rez(double t(double x, int& n, double eps), double a, double b, double h, double eps);
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	double a, b, h, eps;
//	short select;
//	cout << "Enter a, b, h" << endl;
//	cin >> a >> b >> h;
//	cout << "Choose epsilon: \n1: 0.001 \n2: 0.0001 \n3: 0.00001" << endl;
//	cin >> select;
//	switch(select)
//	{
//	case 1: 
//		eps = 0.001;
//		break;
//	case 2:
//		eps = 0.0001;
//		break;
//	case 3:
//		eps = 0.00001;
//		break;
//	}
//	do {
//		cout << "Choose a function\n 1.Y(x)  2.S(x) 3.|Y(x)-S(x)|" << endl;
//		cin >> select;
//		switch (select) {
//		case 1:
//			out_rez(Y, a, b, h, eps);
//			break;
//		case 2:
//			out_rez(S, a, b, h, eps);
//			break;
//		}
//	} while (select == 1 || select == 2 || select == 3);
//	return 0;
//}
//
//void out_rez(double t(double x, int& n, double eps), double a, double b, double h, double eps)
//{
//	cout << endl;
//	int n = 1;
//	for (double x = a; x < b; x += h / 2)
//	{
//		cout << t(x, n, eps);
//		cout <<" Steps =  " << n << endl;
//		n = 1;
//	}
//	cout << endl;
//}
//double Y(double x, int& n, double eps)
//{
//	return -1. / 2 * log(1 - 2 * x * cos(M_PI / 3) + x * x);
//}
//
//double S(double x, int& n, double eps)
//{
//	double r = 1, t=1, s = 0;
//	while(abs(t) > eps) {
//		r *= x;
//		t = r* cos(n * M_PI / 3) / n;
//		s += t;
//		n++;
//	}
//	return s;
//}

////8.3.3

double sqrt_recursive(double a, int n);
double sqrt_nonRecursive(double a, double x, int n);

int main() {

	setlocale(LC_ALL, "Russian");
	double a,x;
	int n;
	cout << "Введите Х для выичсления корня" << endl;
	cin >> a;
	cout << "Введите N" << endl;
	cin >> n;
	x = 0.5 * (1 + a);
	cout << "Результат, вычисленный при помощи рекурсивной функции = " << sqrt_recursive(a, n) << endl;
	cout << "Результат, вычисленный без использования рекурсии = " << sqrt_nonRecursive(a,x,n) << endl;
	return '0';
}

double sqrt_recursive(double a, int n) 
{
	if (!n) return 0.5 * (1 + a);
	return 0.5 * (sqrt_recursive(a, n - 1) + a / sqrt_recursive(a, n-1));
}

double sqrt_nonRecursive(double a, double x, int n) {
	for (int k = 0; k < n; k++) {
		x =  1. / 2 * (x + a / x);
	}
	return x;
}
