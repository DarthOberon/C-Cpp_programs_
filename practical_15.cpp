# include <iostream>
using namespace std;

class Complex{
    public:
    int real, imag;

    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other){
        return Complex(real + other.real, imag + other.imag);
    }
    
    void print(){
        cout << real << "+ i" << imag << endl;

    }
};

int main(){
    Complex c1(3,2);
    Complex c2(9,8);

    Complex sum = c1 + c2;
    sum.print();

    return 0;
}