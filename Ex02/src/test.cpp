
#include <iostream>
#include "ex_01.h"

using namespace std;

int main()
{
    CDArray arr1, arr2(3, 5.5);
    cout << "The original size of arr1 is "<< arr1.GetSize() << endl;
    cout << "The original size of arr2 is "<< arr2.GetSize() << endl;
    arr2.Print();
    cout << arr2[0] << " " << arr2.GetAt(2) << endl;
    arr1.PushBack(3.1);
    cout << arr1[0] << endl;
    arr2.DeleteAt(0);
    arr2.Print();
    CDArray arr3;
    arr3 = arr2;
    cout << "arr3 is: ";
    arr3.Print();
    arr3.SetAt(1, 7.8);
    cout << "arr3 is: ";
    arr3.Print();
    arr3.InsertAt(1, 1.9);
    arr3.PushBack(3.3);
    arr3.PushBack(0.8);
    cout << "arr3 is: ";
    arr3.Print();
    return 0;
}
