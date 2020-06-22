#include <iostream>
#include <ctime>





using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();

    void push_back(T data);

    void clear();

    int GetSize()
    {
        return Size;
    }

    void push_Front(T data);

    void insert(T value, int index);

    void remove(int index);

    void pop_back();

    T& operator[](const int index);
private:

    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};


template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;



        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }


}

template<typename T>
void List<T>::push_Front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_Front(value);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) { previous = previous->pNext; }

        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }

}

template<typename T>
void List<T>::remove(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) { previous = previous->pNext; }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    remove(Size - 1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    setlocale(0, "ru");

    srand(time(NULL));

    List<int> lst;

    lst.push_back(-5);
    lst.push_back(-9);
    lst.push_back(-3);
    lst.push_back(6);
    lst.push_back(-1);
    lst.push_back(0);
    lst.push_back(5);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << "\t";
    }
    for (int i = 0; i < lst.GetSize(); i++)
    {
        if (lst[i] < 0)
        {
            lst.remove(i);
            i--;
        }
    }
    cout << endl;
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << "\t";
    }
    return 0;
}
