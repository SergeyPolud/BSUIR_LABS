// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include<math.h>
#include<iostream>
using namespace std;

//Уровень сложности 1, пример 7

int main()
{
	setlocale(LC_ALL, "Russian");
	double z1, z2, a, b;
	cout << "Введите а, b" << endl;
	cin >> a >> b;
	z1 = pow(cos(a), 4.0) + pow(sin(b), 2.0) + 1 / 4.0 * pow(sin(2 * a), 2.0) - 1;
	z2 = sin(b + a) * sin(b - a);
	cout << "Результат вычисления z1 = " << z1 << endl;
	cout << "Результат вычисления z2 = " << z2 << endl;
	return 0;
}



//Уровень сложности 2, пример 7

/*int main()
{
	setlocale(LC_ALL, "Russian");
	double z1, z2, a, b, tmp1, tmp2;
	cout << "Введите а, b" << endl;
	cin >> a >> b;
	if (cin.fail())
	{
		cout << "Вы ввели не число!" << endl;
		return -1;
	}
	if (a == 0)
	{
		cout << "Деление на ноль запрещено!" << endl;
		return -1;
	}
	if (a < 0 || b < 0) 
	{
		cout << "Корень из отрицательных чисел не может быть извлечен!" << endl;
		return -1;
	}
	tmp1 = pow(pow(a, 3.0) * b, 1.0/2);
	if (tmp1 < 0)
	{
		cout << "Корень из отрицательных чисел не может быть извлечен!" << endl;
		return -1;
	}
	tmp2 = tmp1 + a * b + a*a - a;
	if (tmp2 == 0)
	{
		cout << "Деление на ноль запрещено!" << endl;
		return -1;
	}
	z1 = ((a - 1) * sqrt(a) - (b - 1) * sqrt(b)) / tmp2;
	z2 = (sqrt(a) - sqrt(b)) / a;
	cout << "Результат вычисления z1 = " << z1 << endl;
	cout << "Результат вычисления z2 = " << z2 << endl;
	return 0;
}*/


//Уровень сложности 3, пример 7

/*int main()
{
	setlocale(LC_ALL, "Russian");
	double gamma, x, y, z, tmp1, tmp2, tmp3;
	cout << "Введите x, y, z" << endl;
	cin >> x >> y >> z;
	if (cin.fail())
	{
		cout << "Вы ввели не число!" << endl;
		return -1;
	}
	tmp1 = abs(x - y) * z + x * x;
	if(tmp1 == 0)
	{
		cout << "Деление на ноль запрещено!" << endl;
		return -1;
	}
	tmp2 = x + 3 * abs(x - y) + x * x;
	tmp3 = tmp2 / tmp1;
	gamma = 5 * atan(x) - 1. / 4 * acos(x) * tmp3;
	cout << "Результат вычислений = " << gamma << endl;
	return 0;
}*/

//Уровень сложности 3, пример 8

/*int main()
{
	setlocale(LC_ALL, "Russian");
	double fi, x, y, z, tmp1, tmp2, tmp3, tmp4;
	cout << "Введите x, y, z" << endl;
	cin >> x >> y >> z;
	while (cin.fail())
	{
		cout << "Вы ввели не число!" << endl;
		cin >> x >> y >> z;
	}
	tmp1 = atan(x) + atan(z);
	if (tmp1 < 0)
	{
		cout<< "деление на ноль невозможно!"<< endl;
		return -1;
	}
	tmp2 = pow(x, 6.0) + log(y) * log(y);
	if (tmp2 == 0)
	{
		cout << "Вычисление корня из отрицательного числа невозможно" << endl;
		return -1;
	}
	else {
		tmp2 = pow(tmp2, 1. / 3);
	}
	tmp3 = exp(abs(x - y)) * pow(abs(x - y), (x + y));
	fi = tmp3 / tmp1 + tmp2;
	cout << "Результат вычислений = " <<  fi << endl;
	return 0;

}*/


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

