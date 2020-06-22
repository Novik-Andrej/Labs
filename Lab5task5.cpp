#include<iostream>
#include<list>

using namespace std;


template<typename T>
void PrintList(const list<T>& lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)   //с перед началом и концом тк const, чтобы случайно не изменить
	{
		cout << *i << "\t";
	}
	cout << endl;
}


int main()
{
	setlocale(0, "ru");

	list<int>myList;

	list<int>List1 = { 1,2,3,4,5 };

	list<int>List2 = { 3,4,5,6,7 };


	myList.merge(List1);
	myList.merge(List2);
	myList.sort();
	myList.unique();

	PrintList(myList);
	return 0;
}
