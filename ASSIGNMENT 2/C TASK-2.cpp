
#include <iostream>
using namespace std;

// Return highest mark by reference
int& highestMark(int marks[], int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

// Return highest mark by const reference
const int& highestMarkConst(const int marks[], int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

// Return highest mark by value
int highestMarkCopy(const int marks[], int n)
{
    int maximum = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > maximum)
            maximum = marks[i];
    }

    return maximum;
}

// Return index of highest mark
int highestIndex(const int marks[], int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[index])
            index = i;
    }

    return index;
}

// Return pointer to highest mark
int* highestPointer(int marks[], int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[index])
            index = i;
    }

    return &marks[index];
}

// Intentionally unsafe: do not call this function.
int& danglingReference()
{
    int local = 50;
    return local;
}

int main()
{
    int marks[5] = {75, 89, 92, 81, 86};

    cout << "Original highest mark: "
         << highestMark(marks, 5) << endl;

    highestMark(marks, 5) += 2;

    cout << "After moderation: "
         << highestMark(marks, 5) << endl;

    cout << "Const reference result: "
         << highestMarkConst(marks, 5) << endl;

    cout << "Copy result: "
         << highestMarkCopy(marks, 5) << endl;

    int index = highestIndex(marks, 5);

    cout << "Highest mark index: "
         << index << endl;

    int* ptr = highestPointer(marks, 5);

    *ptr += 1;

    cout << "After pointer modification: "
         << marks[index] << endl;

    cout << "All marks: ";

    for (int i = 0; i < 5; i++)
        cout << marks[i] << " ";

    cout << endl;

    return 0;
}
