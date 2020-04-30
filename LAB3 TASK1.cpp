﻿#include <Windows.h>
#include <iostream>
using namespace std;

void division(float)
{
    cout << "Введите два числа: \n";
    float a, b;
    cin >> a >> b;
    cout << "Результат равен: " << a / b;
}
void pow(float)
{
    cout << "Введите два числа: \n";
    float a, b;
    cin >> a >> b;
    cout << "Результат равен: " << pow(a, b);
}
void sum(float)
{
    cout << "Введите два числа: \n";
    float a, b;
    cin >> a >> b;
    cout << "Результат равен: " << a + b;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    void (*P[3])(float) = { division,pow,sum };
    cout << "1.Деление двух чисел\n";
    cout << "2.Возведение в степень\n";
    cout << "3.Сумма двух чисел\n";
    cout << "  Какую из трех функций выбрать?\n ";
    int my_choose;
    cin >> my_choose;
    my_choose--;
    (*P[my_choose])(my_choose);
    return 0;
}
