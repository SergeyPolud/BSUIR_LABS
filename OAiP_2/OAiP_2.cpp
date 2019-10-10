// OAiP_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;
/*  Лаба 2.1

int main()
{
	setlocale(LC_ALL, "Russian");
	double c, d, z, k, x, y, tmp;
	cout << "Введите c , z , d, k" << endl;
	cin >> c >> d >> k >> z;
	if (z < 0) {
		cout << "Вычисление по первой ветке z^2-z" << endl;
		x = z * z - z;

	}
	else {
		cout << "Вычисление по второй ветке z^3" << endl;
		x = z * z * z;
	}
	tmp = sin(c * x + d * d + k * x * x);
	y = tmp*tmp*tmp;
	cout << "Результат выислений " << y << endl;
	return 0;
}
*/
// Лаба 2.2
/*
int main()
{
	setlocale(LC_ALL, "Russian");
	int select;
	double x, z, y, c, d, func, tmp;
	cout << " Введите z, c, d" << endl;
	
	while(!(cin >> z >> c >> d) || cin.get()!='\n'){
		cout << "ERROR"<< endl;
		cin.clear();
		while(cin.get()!='\n'){};
	}
	if (z < 0) 
	{
		cout << "Вычисление по первой ветке при z<0" << endl;
		x = z * z - z;
	}
	else
	{
		cout << "Вычисление по второй ветке при z>=0" << endl;
		x = z * z * z;
	}
	cout << "Выберите функцию\n\t1.x^2\n\t2.x/3\n\t3.2x " << endl;
	cin >> select;
	switch(select)
	{
		case 1:
			cout << "Выбрана функция x^2" << endl;
			func = x * x;
			break;
		case 2:
			cout << "Выбрана функция x/3" << endl;
			func = x / 3;
			break;
		case 3:
			cout << "Выбрана функция 2*x" << endl;
			func = 2 * x;
			break;
		default: 
		{
			cout << "Неверный выбор" << endl;
			return -1;
		}
	}
	tmp = sin(c * func + d * d + x * x);
	y = tmp * tmp * tmp;
	cout << "Результат выислений " << y << endl;
	return 0;
}*/

double min(double a, double b)
{
	return a < b ? a : b;
}
double max(double a, double b)
{
	return a > b ? a : b;
}
/*
int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, z, m, a, b, c;
	cout << "Введите x, y, z" << endl;
	cin >> x >> y >> z;
	if (cin.fail())
	{
		cout << "Введено не число" << endl;
		return -1;
	}
	if (z == 0) {
		cout << "Деление на ноль запрещено" << endl;
		return -1;
	}
	a = min(x - y + z, x * y / z);
	if (a == 0) {
		cout << "Деление на ноль запрещено" << endl;
		return -1;
	}
	m = max(x + y + z, x * y * z) / a;
	cout << "Результат m = " << m << endl;
	return 0;
}*/

/*

int main() {
	setlocale(LC_ALL, "Russian");
	int a1, a2, a3, b1, b2, res1, res2, res3=0, sum2, sum1;
	cout << "Введите а3, а2, а1, b2, b1" << endl;
	cin >> a3 >> a2 >> a1 >> b2 >> b1;
	sum1 = a1 + b1;
	sum2 = a2 + b2;
	res1 = sum1 % 10;
	if (sum1 > 9) {
		res2 = (++sum2) % 10;
	}
	else {
		res2 = (sum2) % 10;
	}
	if (++sum2 > 9) {
		res3 = ++a3;
	}
	else {
		res3 = a3;
	}
	cout << res3 << " " << res2 << " " << res1; 
	return 0;
}


*/


int main()
{
	setlocale(LC_ALL, "Russian");
	int a1, a2, b1, b2, res1, res2, sub1, sub2;
	cout << "Введите а2, а1, b2, b1" << endl;
	cin >> a2 >> a1 >> b2 >> b1;
	sub1 = a1 - b1;
	sub2 = a2 - b2;
	if (sub2 < 0 && sub1 > 0) {
		res1 = abs(a1 - (10 + b1));
		cout << 0 << " "<< res1;
	}
	if (sub2 < 0 && sub1 < 0){
		res1 = abs(a1 - b1);
		res2 = abs(a2 - b2);
		cout << res2 << " " << res1;
	} 
	if (sub2 == 0 && sub1 < 0) {
		res1 = abs((a1 + 10) - b1);
		cout << 0 << " " << res1;
	}
	if (sub2 == 0 && sub1 > 0) {
		res1 = a1 - b1;
		cout << 0 << " " << res1;
	}
	if (sub2 > 0 && a1 >= b1) {
		res1 = a1 - b1;
		res2 = a2 - b2;
		cout << res2 << " " << res1;
	}
	if (sub2 > 0 && a1 < b1) {
		a2--;
		res1 = (10 + a1) - b1;
		res2 = a2 - b2;
		cout << res2 << " " << res1;
	}
	
	
	
	
	return 0;

}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


