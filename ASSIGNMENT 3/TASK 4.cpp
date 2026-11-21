#include <iomanip>
#include <iostream>
class Money {
    long long paise;
public:
    Money(long long rupees=0, int p=0) : paise(rupees*100+p) {}
    Money operator+(const Money& rhs) const {
        return Money(0, static_cast<int>(paise + rhs.paise));
    }
    bool operator==(const Money& rhs) const { return paise == rhs.paise; }
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        long long whole = m.paise / 100;
        long long fraction = m.paise % 100;
        if (fraction < 0) fraction = -fraction;
        if (m.paise < 0 && whole == 0) os << "-";
        return os << "Rs " << (m.paise < 0 ? -whole : whole)
                  << '.' << std::setw(2) << std::setfill('0') << fraction
                  << std::setfill(' ');
    }
};
int main() {
    Money a(120,75), b(79,25);
    Money c=a+b;
    std::cout << c << '\n' << std::boolalpha << (c==Money(200)) << '\n';
    Money x(0,75), y(0,50);
    std::cout << x+y << '\n';
}
