#include <cmath>
#include <iostream>
#include <stdexcept>
class Complex {
    double re, im;
public:
    Complex() : re(0), im(0) {}
    Complex(double real) : re(real), im(0) {}
    Complex(double real,double imag) : re(real), im(imag) {}
    double real() const { return re; }
    double imag() const { return im; }
    double magnitude() const { return std::sqrt(re*re+im*im); }
    Complex operator+(const Complex& z) const {
        return {re+z.re,im+z.im};
    }
    Complex operator-(const Complex& z) const {
        return {re-z.re,im-z.im};
    }
    Complex operator*(const Complex& z) const {
        return {re*z.re-im*z.im,re*z.im+im*z.re};
    }
    Complex operator/(const Complex& z) const {
        double den=z.re*z.re+z.im*z.im;
        if (den==0.0) throw std::domain_error("Division by zero impedance");
        return {(re*z.re+im*z.im)/den,(im*z.re-re*z.im)/den};
    }
    bool operator==(const Complex& z) const {
        const double eps=1e-9;
        return std::abs(re-z.re)<eps && std::abs(im-z.im)<eps;
    }
    friend std::ostream& operator<<(std::ostream& os,const Complex& z) {
        return os << z.re << (z.im<0 ? " - " : " + ")
                  << std::abs(z.im) << 'j';
    }
};
int main() {
    const double pi=3.141592653589793;
    double f=50.0, w=2*pi*f, R=10.0, L=0.1, C=100e-6;
    Complex zr(R);
    Complex zl(0,w*L);
    Complex zc(0,-1.0/(w*C));
    Complex series=zr+zl+zc;
    Complex parallel=(zr*zl)/(zr+zl);
    std::cout << "Resistor: " << zr << ", |Z|=" << zr.magnitude() << '\n';
    std::cout << "Series RLC: " << series << ", |Z|=" << series.magnitude() << '\n';
    std::cout << "Parallel R-L: " << parallel << ", |Z|=" << parallel.magnitude() << '\n';
    try { std::cout << (zr/Complex()) << '\n'; }
    catch (const std::domain_error& e) { std::cout << e.what() << '\n'; }
}
