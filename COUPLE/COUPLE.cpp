// COUPLE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{

	bool correct;
	char gender;
	int year, couple;
	cout << "Hi, pairing program welcomes you!" << endl;
	cout << "What is your gender? (M - man/W - woman)" << endl;
	correct = false;
	do {
		try 
		{
			do 
			{
				
				cin >> gender;
			} while ((gender != 'M') && (gender != 'W'));
			correct = true;
		}
		catch (int exception) {}

	} while (!correct);
	cout << "How old are you" << endl;
	correct = false;
	do {
		try {
			cin >> year;
			correct = true;
		}
		catch(int exception){}

	} while (!correct);

	if (year > 14) {
		if (gender == 'M') {
			couple = year / 2 + 7;
		}
		else {
			couple = year * 2 - 14;
		}
		cout << "The age of your ideal couple is " << couple << endl;
	}
	else {
		cout << "You too early to find a couple!" << endl;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
