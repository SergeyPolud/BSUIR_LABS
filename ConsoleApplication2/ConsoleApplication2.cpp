#include "iostream"
#include "math.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double S, a, n, k, b, h, x, y, min, max, minx, maxx, m, r, c, number;
	int kod;
	const double pi = 3.14;
	cout << "1-3.3.1,2-3.3.2,3-3.3.3" << endl;
	cin >> kod;
	switch (kod)
	{
	case 1: default:
		min = 1000000000000;
		max = -10000000000000;
		cout << "Введите а" << endl;
		cin >> a;
		cout << "Введите b" << endl;
		cin >> b;
		cout << "Введите h" << endl;
		cin >> h;
		x = a;
		m = 1;
		while (x <= b)
		{
			y = (x * sin(pi / 4)) / (1 - 2 * x * cos(pi / 4) + (x * x));
			cout << m << ")" << y << endl;
			if (y < min)
			{
				min = y;
				minx = x;
			}
			else if (y > max)
			{
				max = y;
				maxx = x;
			}
			m++;
			x = x + h;
		}
		cout << "max y=" << max << "при x=" << maxx << endl;
		cout << "min y=" << min << "при x=" << minx << endl;
		break;
	case 2:
		cout << "Введите а" << endl;
		cin >> a;
		cout << "Введите b" << endl;
		cin >> b;
		cout << "Введите h" << endl;
		cin >> h;
		cout << "Введите n" << endl;
		cin >> n;
		S = r = 1;
		x = a;
		m = 1;
		k = 1;
		number = 1;
		do
		{
			r = -r * (x / (2 * k + 1));
			S += r;
			cout << number << "_____" << endl;
			while (x <= b)
			{
				y = sin(x);
				x += h;
				c = fabs(S - y);
				cout << m << ")" << y << endl;
				cout << "Y-S=" << c << endl;
				m++;
			}
			x = a;
			k++;
			number++;
		} while (k <= n);
		break;
	}
	system("pause");
	return 0;
}