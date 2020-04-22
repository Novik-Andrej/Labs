#include<string>
#include<fstream>
#include<vector>
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "ru");
	string path = "myFile.txt";
	ofstream file;
	file.open(path); //не удаление предыдущих записей ofstream::app

	const int n = 7;
	int array[n];
	if (!file.is_open()) cout << "Error\n";
	else
	{
		cout << "Данные записанные в файл: ";
		for (int i = 0; i < n; i++) {
			array[i] = rand() % 10;
			file << array[i] << " ";
			cout << array[i] << " ";
		}
		cout << endl;
	}
	file.close();


	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		char ch;
		vector<char> myVector;
		cout << "Данные взятые из файла: ";
		while (fin.get(ch))
			if (ch != ' ')
				myVector.push_back(ch);

		for (int i = 0; i < myVector.size(); i++)
			cout << myVector[i] << " ";

		cout << endl;
		cout << "Данные после сортировки пузырьком: ";

		for (int i = 0; i < myVector.size(); i++) {
			for (int j = 0; j < myVector.size() - 1; j++) {
				if (myVector[j] > myVector[j + 1]) {
					int t = myVector[j];
					myVector[j] = myVector[j + 1];
					myVector[j + 1] = t;
				}
			}
		}
		for (int i = 0; i < myVector.size(); i++)
			cout << myVector[i] << " ";

		file.open(path, ofstream::app);
		file << endl;
		if (!file.is_open()) cout << "Error\n";
		for (int i = 0; i < myVector.size(); i++) {
			file << myVector[i] << " ";
		}
		file.close();
	}
	fin.close();
	return 0;
}



