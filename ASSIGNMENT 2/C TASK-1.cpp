
#include <iostream>
using namespace std;

// Call by value
void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by reference
void applyByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long* fee, int percent)
{
    *fee -= *fee * percent / 100;
}

// Given change function
void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

// Return by reference
int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

// Default arguments
void show(int x, int y = 5, int z = 10)
{
    cout << x + y + z << " ";
}

int main()
{
    cout << "CALLING METHODS\n";

    long long f1 = 45000;
    long long f2 = 45000;
    long long f3 = 45000;

    applyByValue(f1, 10);
    applyByReference(f2, 10);
    applyByPointer(&f3, 10);

    cout << "Call by value: " << f1 << endl;
    cout << "Call by reference: " << f2 << endl;
    cout << "Call by pointer: " << f3 << endl;

    cout << "\nOUTPUT PREDICTION PROGRAM\n";

    int a = 1, b = 2, c = 3;

    change(a, b, &c);

    cout << a << " " << b << " " << c << endl;

    bigger(a, c) = 100;

    cout << a << " " << c << endl;

    show(1);
    show(1, 2);
    show(1, 2, 3);

    cout << endl;

    cout << "\nCOMPLETED CONCESSION PROGRAM\n";

    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);

    cout << "after call by value : "
         << hostelFee << endl;

    applyByReference(hostelFee, 10);

    cout << "after call by reference: "
         << hostelFee << endl;

    return 0;
}
