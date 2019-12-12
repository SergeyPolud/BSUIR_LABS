//в строке,состоящей из групп нулей и единиц,подсчитать количество символов в самой длинной группе
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void Input(const char* text, char* str) {
	int i = 0;
	cout << text << endl;
	while (1) {
		str[i] = _getch();
		if (str[i] == 13)break;
		if (str[i] == '0' || str[i] == '1') {
			cout << str[i];
			i++;
		}
	}
	str[i] = '\0';
}

int lengthString(char* stroka)
{
	int i;
	for (i = 0; stroka[i] != '\0'; i++);
	return i;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str1[81];
	int length = 0;
	int buffLength = 0;

	char item = str1[0], buffItem = str1[0];

	//cout << "Введите строку,состоящую из нулей и единиц " << endl;
	//cin.getline(str1,81);		// ???????!!!!!!!
	Input("\n Введите строку,состоящую из нулей и единиц ", str1);
	cout << endl;
	int l = lengthString(str1);
	cout << l << endl;

	/*for (int i = 0; i < l; i++)	//??????
	{
		if (str1[i] != '1' && str1[i] != '0')
		{
			cout << "Строка введена некорректно! " << endl;
			return 0;
		}
	}*/

	for (int i = 0; i < l; i++)
	{
		if (str1[i] == buffItem && i != l - 1)
		{
			buffLength++;
		}
		else
		{
			if (i == l - 1)
			{
				if (buffItem == str1[i]) buffLength++;
				else
				{
					buffLength = 1;
					buffItem = str1[i];
				}
			}
			if (buffLength >= length)
			{
				length = buffLength;
				item = buffItem;
			}
			buffLength = 1;
			buffItem = str1[i];
		}

	}

	cout << "Количество элементов в самой длинной строке равно " << length << endl;

	return 0;
}