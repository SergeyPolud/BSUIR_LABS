#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	const int size = 20;
	double mass[size];
	int i;
	for (i = 0; i < size; ++i) {
		mass[i] = rand();
	}
	for (i = 0; i < size; ++i) {
		cout << mass[i] << endl;
	}
	return 0;
}

int n, i_p, i_n, t;
cin >> n;
int* arr;
arr = new int[n];
for (int i = 0; i < n; ++i) {
	cout << "arr[" << i << "]= ";
	cin >> arr[i];
}
cout << endl;
for (int i = 0; i < n; ++i) {
	if (arr[i] > 0) {
		i_p = i;
		break;
	}
}
for (int i = i_p; i < n; ++i) {
	if (arr[i] < 0 && i) {
		t = arr[i];
		for (int j = i; j > i_p; --j) {
			arr[j] = arr[j - 1];
		}
		arr[i_p] = t;
		i = ++i_p;
	}
}
for (int i = 0; i < n; ++i) {
	cout << "arr[" << i << "]= " << arr[i] << endl;
}
delete[] arr;
return 0;