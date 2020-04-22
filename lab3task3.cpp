#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	setlocale(0, "ru");
	ifstream fin;
	fin.open("File.txt");
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		string str;
		vector<string>myVector;
		int number = 0;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			myVector.push_back(str);
			cout << str << endl;
			number++;
		}
		fin.close();
		cout << "Количество строк: " << number << endl;	
		int s;
		cout << "После какой строки ставить пробел: ";
		cin >> s;
		if (s >= number) {
			cout << endl;
			cout << "Недостаточное кол-во строк" << endl;
		}
		else
		{
			if (s < number)
			{
				for (int i = 0; i < myVector.size(); i++) {
					if (i == s)
						myVector.emplace(myVector.begin() + s, "\n");
				}
			}
			for (int i = 0; i < myVector.size(); i++)
				cout << myVector[i] << endl;
			ofstream fout;
			fout.open("File.txt");
			for (int i = 0; i < myVector.size(); i++) {
				if (i == s)
					fout << myVector[i];
				else if (i == myVector.size() - 1)
					fout << myVector[i];
				else
					fout << myVector[i] << endl;
			}
				fout.close();
		}
	}
	return 0;
}
