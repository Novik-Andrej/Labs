#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Phone_owner
{
public:
	string last_name, first_name, patronymic, country, city, street, house_number, phone_number;	
};

ostream& operator << (ostream& os, const Phone_owner& phone_owner)
{
	os << phone_owner.last_name << " " << phone_owner.first_name << " " << phone_owner.patronymic << " " << phone_owner.country << " " << phone_owner.city
		<< " " << phone_owner.street << " " << phone_owner.house_number << " " << phone_owner.phone_number << "\n";
	return os;
}
istream& operator >> (istream& is, Phone_owner& phone_owner)
{
	is >>  phone_owner.last_name >> phone_owner.first_name >> phone_owner.patronymic >> phone_owner.country >> phone_owner.city
		>> phone_owner.street >> phone_owner.house_number >> phone_owner.phone_number;
	return is;
}


void output_owner(Phone_owner owner)
{
	cout << "Фамилия: " << owner.last_name << endl;
	cout << "Имя: " << owner.first_name << endl;
	cout << "Отчество: " << owner.patronymic << endl;
	cout << "Страна: " << owner.country << endl;
	cout << "Город: " << owner.city << endl;
	cout << "Улица: " <<  owner.street << endl;
	cout << "Номер дома: " << owner.house_number << endl;
	cout << "Номер телефона: " << owner.phone_number << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");
	Phone_owner* owner = new Phone_owner[8]; 
	int number; 
	
	while (1)
	{
		system("cls");

		Phone_owner phone_owner;
		int choose;
		cout << "1.Создание файла.\n";
		cout << "2.Добавление элемента в конец файла.\n";
		cout << "3.Вывод содержимого файла на экран.\n";
		cout << "4.Удаление элемента из файла(с заданным номером).\n";
		cout << "5.Удаление элемента из файла(с заданным ключом).\n";
		cout << "6.Упорядочивание элементов в файле по выбранному признаку, сортировкой перемешиванием.\n";
		cout << "Выберите действие\n ";

		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1: //создание файла
		{
			ofstream file;
			file.open("File.txt");
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
				cout << "Файл создан\n";
			file.close();
			Sleep(1000);
			break;
		}
		case 2:  //заполнения файла
		{
			ofstream file;
			file.open("File.txt",ofstream::app);//ofstream::app
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
			{
				cout << "Введите количество владельцев телефонов: ";
				cin >> number;
				if (number <= 0)
					break;
				else
				{
					owner = new Phone_owner[number];
					for (int i = 0; i < number; i++)
					{
						system("cls");


						cout << "Введите фамилию: "; cin >> owner[i].last_name;
						cout << "Введите имя: "; cin >> owner[i].first_name;
						cout << "Введите отчество: "; cin >> owner[i].patronymic;
						cout << "Введите страну: "; cin >> owner[i].country;
						cout << "Введите город: "; cin >> owner[i].city;
						cout << "Введите улицу: "; cin >> owner[i].street;
						cout << "Введите номер дома: "; cin >> owner[i].house_number;
						cout << "Введите номер телефона: "; cin >> owner[i].phone_number;
						file << owner[i];
					}
					cout << "Все данные введены!";
					Sleep(1000);
					system("cls");
				}
			}
			file.close();
			break;
		}
		case 3:  //вывод содержимого файла
		{
			ifstream file;
			file.open("File.txt");
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
			{
				int i=0	;
				while (!file.eof())
				{
					file >> owner[i];
					if (file.eof())
					{
						break;
					}
					cout << owner[i] << endl;
					i++;
				}
				system("pause");
			}
			file.close();
			break;
		}	
		case 4:  //удаление владельца по номеру
		{
			vector< Phone_owner>Myvector;
			ifstream file;
			file.open("File.txt");
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
			{
				while (!file.eof())
				{
					file >> phone_owner;
					if (file.eof())
					{
						break;
					}
					Myvector.push_back(phone_owner);
				}
				int number;
				cout << "Под каким номером удалить владельца ";
				cin >> number;
				if (number == 0 || number > Myvector.size())
				{
					cout << "Нет владельца с таким номером";
					Sleep(1000);
					break;
				}
				else
				{
					number--;
					Myvector.erase(Myvector.begin() + number);

					ofstream file;
					file.open("File.txt");//fstream::app
					if (!file.is_open())
					{
						cout << "Error";
					}
					else
					{
						for (int i = 0; i < Myvector.size(); i++)
							file << Myvector[i];

					}
					system("cls");
					cout << "Выполнено";
					Sleep(1000);
				}
			}
			file.close();
			break;
		}
		case 5: //удаление элемента по заданному ключу(фамилия)
		{
			ifstream file;
			file.open("File.txt");
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
			{
				int i = 0;
				vector<Phone_owner>myVector;
				while (!file.eof())
				{
					file >> owner[i];
					if (file.eof())
					{
						break;
					}
					cout << owner[i] << endl;					
					myVector.push_back(owner[i]);
					i++;
				}
				cout << "С какой фамилией вдадельца удалить? ";
				string last_n;
				cin >> last_n;
				
				for (int i = 0; i < myVector.size(); i++)
				{				
					if (owner[i].last_name==last_n)
					{						
						myVector.erase(myVector.begin() + i );
						break;
					}
				}
				ofstream file;
				file.open("File.txt");
				if (!file.is_open())
				{
					cout << "Error";
				}
				else
				{
					for (int i = 0; i < myVector.size(); i++)
						file << myVector[i];
				}
				system("cls");
				cout << "Выполнено";
				Sleep(1000);
			}
			file.close();
			break;
		}
		case 6:  //сортировка по фамилии
		{
			ifstream file;
			file.open("File.txt");
			if (!file.is_open())
			{
				cout << "Error";
			}
			else
			{
				int j = 0;
				vector<Phone_owner>myVector;
				while (!file.eof())
				{
					file >> owner[j];
					if (file.eof())
					{
						break;
					}
					cout << owner[j] << endl;
					myVector.push_back(owner[j]);
					j++;
				}
				Phone_owner owner_copy;
				for (int i = 0; i < j-1; i++)
				{
					if (owner[i].last_name[0] > owner[i + 1].last_name[0])
					{
						
						owner_copy = owner[i];
						owner[i] = owner[i + 1];
						owner[i + 1] = owner_copy;						
					}
					else
					{
						cout << "Error sorting!"; continue;
					}
				}				
				ofstream file;
				file.open("File.txt");
				if (!file.is_open())
				{
					cout << "Error";
				}
				else
				{
					for (int i = 0; i < j; i++)
						file << owner[i];
				}
				system("cls");
				cout << "Выполнено";
				Sleep(1000);

				
			}
			break;
		}
		case 7:  //выход
			return 0;
			break;
			
		}
	}
	system("pause");
	return 0;
}

