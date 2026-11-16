
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int CAPACITY = 10;
const int TOTAL = 100000;

class OriginalAccount
{
private:
    int transactions[CAPACITY];
    int count;

public:
    OriginalAccount()
    {
        count = 0;
    }

    void addTransaction(int value)
    {
        if (count == CAPACITY)
        {
            for (int i = 0; i < CAPACITY - 1; i++)
                transactions[i] = transactions[i + 1];

            count--;
        }

        transactions[count++] = value;
    }

    void display() const
    {
        for (int i = 0; i < count; i++)
            cout << transactions[i] << " ";

        cout << endl;
    }
};

class CircularAccount
{
private:
    int transactions[CAPACITY];
    int start;
    int count;

public:
    CircularAccount()
    {
        start = 0;
        count = 0;
    }

    void addTransaction(int value)
    {
        if (count < CAPACITY)
        {
            int position = (start + count) % CAPACITY;
            transactions[position] = value;
            count++;
        }
        else
        {
            transactions[start] = value;
            start = (start + 1) % CAPACITY;
        }
    }

    void display() const
    {
        for (int i = 0; i < count; i++)
        {
            int position = (start + i) % CAPACITY;
            cout << transactions[position] << " ";
        }

        cout << endl;
    }
};

int main()
{
    OriginalAccount original;
    CircularAccount redesigned;

    cout << "INSERTING SAME TRANSACTIONS\n";

    for (int i = 1; i <= 15; i++)
    {
        original.addTransaction(i * 100);
        redesigned.addTransaction(i * 100);
    }

    cout << "Original transactions: ";
    original.display();

    cout << "Circular transactions: ";
    redesigned.display();

    cout << "\nPERFORMANCE TEST\n";

    OriginalAccount oldAccount;
    CircularAccount newAccount;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < TOTAL; i++)
        oldAccount.addTransaction(i);

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < TOTAL; i++)
        newAccount.addTransaction(i);

    auto end2 = high_resolution_clock::now();

    cout << "Original shifting time: "
         << duration_cast<microseconds>(
                end1 - start1).count()
         << " microseconds" << endl;

    cout << "Circular buffer time: "
         << duration_cast<microseconds>(
                end2 - start2).count()
         << " microseconds" << endl;

    cout << "\nFINAL VALIDATION\n";

    cout << "Original: ";
    oldAccount.display();

    cout << "Redesigned: ";
    newAccount.display();

    return 0;
}
