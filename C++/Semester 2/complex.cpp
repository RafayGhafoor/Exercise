// Utility functions, interface

#include <iostream>

using namespace std;

class Complex
{
private: // Access Specifier
  float real, imaginary;

public:
  void set(float r, float i) { real = r, imaginary = i; }

  Complex add(const Complex &obj)
  {
    Complex ans;
    ans.real = obj.real + real;
    ans.imaginary = obj.imaginary + imaginary;
    return ans;
  }
  void print() { cout << real << " + " << imaginary << "i\n"; }
};

int main()
{

  Complex c, d, e;
  c.set(6.1, 2.3);
  d.set(3.5, 4.2);
  e = c.add(d);
  e.print();
}