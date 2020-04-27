#include<iostream>
using namespace std;
int NOD(int a, int b)
{
	return b != 0 ? NOD(b, a % b) : a;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a, b, c, d;
	cout << "Введите числа: ";
	cin >> a >> b >> c >> d;
	cout << "Наименьший общий делитель числел a и b: ";
	cout << NOD(a, b) << endl;;
	cout << "Наименьший общий делитель числел a и c: ";
	cout << NOD(a, c) << endl;
	cout << "Наименьший общий делитель числел a и d: ";
	cout << NOD(a, d) << endl;
}

