#include <iostream>

using namespace std;

class nDVector {

private:
  float *dims;
  int n;

public:
  nDVector() {
    dims = 0;
    n = 0;
  }

  nDVector(int nd) {
    dims = new float[nd];
    n = nd;
  }

  nDVector(const nDVector &obj) {
    n = obj.n;
    dims = new float[n];
    for (int i = 0; i < n; i++)
      dims[i] = obj.dims[i];
  }

  float &operator[](int i) { return dims[i]; }

  const nDVector &operator+(const float &temp) {
    for (int i = 0; i < n; i++)
      dims[i] += temp;
    return (*this);
  }

  const nDVector &operator=(const nDVector &obj) {
    if (dims != nullptr)
      delete[] dims;
    n = obj.n;
    dims = new float[n];
    for (int i = 0; i < n; i++)
      dims[i] = obj.dims[i];
    return (*this);
  }

  nDVector operator-() {
    nDVector temp = (*this);
    for (int i = 0; i < n; i++)
      temp[i] *= -1;
    return temp;
  }

  int getN() { return n; }

  float getElement(int i) { return dims[i]; }
};

nDVector operator+(float nd, nDVector &obj) {
  nDVector temp(obj.getN());
  for (int i = 0; i < obj.getN(); i++)
    temp[i] = obj[i] + nd;
  return temp;
}

const nDVector &operator++() // Pre-Increment
{
  for (int i = 0; i < n; i++)
    dims[i]++;
  return *this;
}

const nDVector operator++(int dummy) // Post-Increment
{
  nDVector temp = *this;
  for (int i = 0; i < n; i++)
    dims[i]++;
  return temp;
}

ostream &operator<<(ostream &out, nDVector &obj) {
  out << "( ";
  for (int i = 0; i < obj.getN() - 1; i++)
    out << obj[i] << " , ";
  out << obj[obj.getN() - 1];
  out << " )" << endl;
  return out;
}

nDVector inputVector(int mango) {
  nDVector temp(mango);
  cout << "Enter " << mango << " numbers:\n";
  for (int i = 0; i < mango; i++)
    cin >> temp[i];
  return temp;
}

int main() {
  nDVector v1 = inputVector(3);
  nDVector v2 = inputVector(3);
  cout << "v1 = " << v1 << endl << "v2 = " << v2 << endl;
  v2 = 5.1 + v2;
  cout << "after adding 5.1: " << v2;
  nDVector v3 = -v1;
  cout << v3;

  // system("pause");
}