#include<iostream>
#include<list>
#include<queue>
#include<Windows.h>
using namespace std;

enum num
{
	Front,
	Back
};


int main()
{
	queue<int, list<int>> q;
	while (true)
	{
		cout << "Enter 1 to add an item\nEnter 2 to access the item.\n";
		cout << "Enter any other number to exit\n";
		int number;
		cin >> number;

		if (number <= 0 || number > 2)
			return 0;
		if (number == 1)
			q.push(rand() % 15);
		if (number == 2)
		{
			cout << "Enter 1 to access the first item\nEnter 2 to access the last item\n";
			int num;
			cin >> num;
			num--;
			switch (num)
			{
			case Front:
			{
				if (q.empty())
				{
					cout << "No items\n";
					break;
				}
				cout << q.front() << endl;
				q.pop();

				break;
			}
			case Back:
			{
				if (q.empty())
				{
					cout << "No items\n";
					break;
				}
				cout << q.back();
				q.pop();
				break;
			}
			default:
				return 0;
				break;
			}
		}
		Sleep(1000);
		system("cls");
	}
}
