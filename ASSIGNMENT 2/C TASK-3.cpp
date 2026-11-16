
#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

// Weight in grams
double charge(int grams, bool express = false,
              bool insured = false)
{
    double amount = grams * 0.05;

    if (express)
        amount += 50;

    if (insured)
        amount += 30;

    cout << "Integer overload selected: ";

    return amount;
}

// Weight in kilograms
double charge(double kg, bool express = false,
              bool insured = false)
{
    double amount = kg * 50;

    if (express)
        amount += 50;

    if (insured)
        amount += 30;

    cout << "Double overload selected: ";

    return amount;
}

// Parcel object
double charge(const Parcel& p)
{
    double amount = p.weight * 50;

    if (p.express)
        amount += 50;

    if (p.insured)
        amount += 30;

    cout << "Parcel overload selected: ";

    return amount;
}

int main()
{
    Parcel p = {3.0, true, true};

    cout << "Call 1: " << charge(2) << endl;

    cout << "Call 2: " << charge(2.0f) << endl;

    cout << "Call 3: " << charge(500) << endl;

    cout << "Call 4: " << charge(1.5) << endl;

    cout << "Call 5: " << charge(2, true) << endl;

    cout << "Call 6: " << charge(p) << endl;

    return 0;
}
