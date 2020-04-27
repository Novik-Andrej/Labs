#include<iostream>
using namespace std;
int RemoveForInc(float* arr, int size) {
    int p, i, j;
    for (p = 0, i = 1; i < size; i++) {
        if (arr[i] < arr[p]) {
            for (j = i; j < size - 1; j++)
                arr[j] = arr[j + 1];
            --size;
            i--;
        }
        else
            p++;
    }
    return size;
}
float randfrom(float min, float max)
{
    float range = (max - min);
    float div = RAND_MAX / range;
    return round((min + (rand() / div)) * 10) / 10;
}
void FillArray(float* const arr, const int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = randfrom(1, 15);
    }
}
void ShowArray(float* const arr, const int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    cout << "enter array size 1  ";
    int size1;
    cin >> size1;
    float* arr1 = new float[size1];
    FillArray(arr1, size1);
    ShowArray(arr1, size1);
    size1 = RemoveForInc(arr1, size1);
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    cout << endl;
    delete[] arr1;


    cout << "enter array size 2  ";
    int size2;
    cin >> size2;
    float* arr2 = new float[size2];
    FillArray(arr2, size2);
    ShowArray(arr2, size2);
    size2 = RemoveForInc(arr2, size2);
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " ";
    cout << endl;
    delete[] arr2;


    cout << "enter array size 3  ";
    int size3;
    cin >> size3;
    float* arr3 = new float[size3];
    FillArray(arr3, size3);
    ShowArray(arr3, size3);
    size3 = RemoveForInc(arr3, size3);
    for (int i = 0; i < size3; i++)
        cout << arr3[i] << " ";
    cout << endl;
    delete[] arr3;

    return 0;
}
