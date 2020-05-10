#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<string>
using namespace std;



int main()
{
	setlocale(0, "ru");
	
	
	srand(time(NULL));
	int k;
	cout << "Введите количество матриц ";
	cin >> k; //количество матриц
	int n;
	cout << "Введите размер матриц ";
	cin >> n;  //размер матриц
	for (int i = 0; i < k; i++)
	{
		ofstream file1;
		file1.open("File1.txt",ofstream::app);
		if (!file1.is_open()) cout << "Error";
		else
		{
			int** arr = new int* [n];
			for (int j = 0; j < n; j++)
			{
				arr[j] = new int[n];
			}
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					arr[j][k] = rand() % 20 + 1;
					//cout << arr[j][k] << "\t";
				}
				//cout << endl;
			}
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (k == j || k + j == n - 1)
					{
						sum += arr[j][k];
						if (n % 2 != 0)
							sum - arr[(n - 1) / 2][(n - 1) / 2];
					}
				}
			}
		//	cout << sum << endl;
			if (sum % 2 == 0)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						file1 << arr[j][k] << "\t";
					}
					file1 << endl;
				}
				file1 << endl;
				file1.close();
			}
			else
			{
				ofstream file2;
				file2.open("File2.txt", ofstream::app);
				if (!file2.is_open()) cout << "Error";
				else
				{
					for (int j = 0; j < n; j++)
					{
						for (int k = 0; k < n; k++)
						{
							file2 << arr[j][k] << "\t";
						}
						file2 << endl;
					}
					file2 << endl;
					file2.close();
				}	
				//транспонирование матрицы
				
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						
						int** tmp = new int* [n];
						for (j = 0; j < n; ++j)
							tmp[j] = new int[n];
						for (j = 0; j < n; ++j)
							for (k = 0; k < n; ++k)
								tmp[j][k] = arr[k][j];
						for (int g = 0; g < n; g++)
						{
							for (int h = 0;h < n; h++)
							{
								file1 << tmp[g][h] << "\t";
							}
							file1 << endl;
						}
						file1 << endl;				
					}				
				}
				file1 << endl;
				file1.close();
			}
			cout << endl;
			for (int j = 0; j < n; j++)
				delete[] arr[j];
			delete[]arr;
		}
	}
	
	ifstream fil1;
	fil1.open("File1.txt");
	if (!fil1.is_open()) cout << "Error";
	else
	{
		cout << "Матрицы из первого файла " << endl;
		string s;
		while (!fil1.eof())
		{
			string s = "";
			getline(fil1, s);
			cout << s << endl;
		}
		fil1.close();
	}
	cout << "====================================\n\n";
	ifstream fil2;
	fil2.open("File2.txt");
	if (!fil2.is_open()) cout << "Error";
	else
	{
		cout << "Матрицы из второго файла " << endl;
		string s;
		while (!fil2.eof())
		{
			string s = "";
			getline(fil2, s);
			cout << s << endl;
		}
		fil2.close();
	}
	return 0;
}
