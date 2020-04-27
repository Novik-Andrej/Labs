#include<iostream>
#include <Windows.h>
#include <string>
using namespace std;
int Finding_a_position(string S, string S0)
{
	for (int i = size(S) - 1, j, k; i >= 0; i--) {
		for (j = size(S0) - 1, k = 0; j >= 0; j--, k++) {
			if (S[i - k] != S0[j])
				break;
		}
		if (j == -1)
			return i - size(S0) + 1;
		else return 0;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string S1;
	cout << "Введите строку1: ";
	cin >> S1;
	string S01;
	cout << "Введите подстроку1: ";
	cin >> S01;
	cout << Finding_a_position(S1, S01) << endl;;

	string S2;
	cout << "Введите строку2: ";
	cin >> S2;
	string S02;
	cout << "Введите подстроку2: ";
	cin >> S02;
	cout << Finding_a_position(S2, S02) << endl;;

	string S3;
	cout << "Введите строку3: ";
	cin >> S3;
	string S03;
	cout << "Введите подстроку3: ";
	cin >> S03;
	cout << Finding_a_position(S3, S03) << endl;
}
