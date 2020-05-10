#include <iostream>
using namespace std;


void bubble_sorting(int);
void Shell_sorting(int);
void insertion_sorting(int);


int main()
{
	setlocale(LC_ALL, "ru");

	void (*P[3])(int) = { bubble_sorting,Shell_sorting,insertion_sorting };
	cout << "1.Сортировка пузырьком\n";
	cout << "2.Сортировка Шелла\n";
	cout << "3.Сортировка вставками\n";
	cout << "  Какую из трех сортировок выбрать?\n ";
	int my_choose;
	cin >> my_choose;
	my_choose--;
	(*P[my_choose])(my_choose);
	return 0;
}

void bubble_sorting(int)
{
	int size;
	cout << "Введите размер массива ";
	cin >> size;
	int* array = new int[size];
	cout << "Ваш массив ";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 25 + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}
	}
	cout << "Данные после сортировки пузырьком: ";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}


void Shell_sorting(int)
{
	int size;
	cout << "Введите размер массива ";
	cin >> size;
	int* array = new int[size];
	cout << "Ваш массив ";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 25 + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	int value, j;
	for (int i = 1; i < size; i++)
	{
		value = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > value)
		{
			array[j + 1] = array[j];
			array[j] = value;
			j--;
		}
	}
	cout << "Данные после сортировки Шелла: ";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}


void insertion_sorting(int)
{
	int size;
	cout << "Введите размер массива ";
	cin >> size;
	int* array = new int[size];
	cout << "Ваш массив ";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 25 + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	int step = size / 2;
	while (step > 0)
	{
		for (int i = 0; i < (size - step); i++)
		{
			int j = i;
			while (j >= 0 && array[j] > array[j + step])
			{
				int temp = array[j];
				array[j] = array[j + step];
				array[j + step] = temp;
				j--;
			}
		}
		step = step / 2;
	}
	cout << "Данные после сортировки вставками: ";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}
