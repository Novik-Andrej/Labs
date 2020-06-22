#include<iostream>
#include<list>

using namespace std;

template<typename T>
void PrintList(const list<T>& lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)
	{
		cout << *i << "\t";
	}
	cout << endl;
}

int main()
{
	list<int>List1 = { 1,2,3,4,5 };
	list<int>List2;

	auto it = List1.begin();
	advance(it, List1.size() - 1);

	List2.push_back(*it);
	List1.pop_back();

	auto it2 = List2.begin();
	List1.push_front(*it2);

	PrintList(List1);

	return 0;
}
