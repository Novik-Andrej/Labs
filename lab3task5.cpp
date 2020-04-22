#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");
	ifstream fin;
	fin.open("Lab.txt");
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		vector<double> myVector;
		while (!fin.eof()) {
			double v;
			fin >> v;
			if (floor(v) == v)
				myVector.push_back(v);
		}
		cout << "Все целые числа из файла" << endl;
		for (int i = 0; i < myVector.size(); i++) 
			cout << myVector[i] << " ";
		cout << endl;
		ofstream fout;
		fout.open("newLab.txt");
		for (int i = 0; i < myVector.size(); i++) {
			fout << myVector[i] << " ";
		}
		fout.close();
	}
	fin.close();
	return 0;
}
