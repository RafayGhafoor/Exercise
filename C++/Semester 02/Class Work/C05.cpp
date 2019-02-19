#include <cstring>
#include <iostream>

using namespace std;

class Vector {
public:
  // Default Constructor
  Vector() {
    vec = nullptr;
    size = cap = 0;
  }

  // Parametric Constructor
  Vector(int capacity) {
    vec = new int[capacity];
    cap = capacity, size = 0;
  }

  ~Vector() {
    if (vec) {
      delete[] vec;
      vec = nullptr;
    }
  }

  // Copy Constructor | Deep Copy
  Vector(const Vector &obj) {
    vec = new int[obj.cap];

    for (int i = 0; i < obj.size; i++)
      vec[i] = obj.vec[i];

    size = obj.size;
    cap = obj.cap;
  }

  void push_back(int input) {
    if (!cap)
      vec = new int[++cap];

    else if (size == cap) {
      // Double the capacity
      int *temp = new int[cap * 2];

      for (int i = 0; i < cap; i++)
        temp[i] = vec[i];

      delete[] vec;
      vec = nullptr;

      vec = temp;
      cap *= 2;
    }
    vec[size++] = input;
  }

  void pop_back() {
    // Removes the last thing
    // If size has fallen half the capacity, it shrinks the array
    if (size == cap / 2) {
      int *temp = new int[cap / 2];

      for (int i = 0; i < cap; i++)
        temp[i] = vec[i];

      delete[] vec;
      vec = nullptr;
      vec = temp;
      cap /= 2;
    }

    if (size)
      size--;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << vec[i] << '\t';
    }
  }

  void assign(const Vector &obj) {
    delete[] vec;
    vec = nullptr;
    vec = new int[obj.cap];
    cap = obj.cap;
    size = obj.size;
    for (int i = 0; i < size; i++)
      vec[i] = obj.vec[i];
  }

private:
  int *vec; // Dynamically allocated array
  int size, cap;
};

int main() {
  Vector v1, v2(50); // Empty dynamic array, Space allocated for 50 members
  for (int i = 0; i < 100; i++)
    v2.push_back(i);

  v2.print();
  // Default Copy Constructor / Shallow Copying is called which does member-wise
  // copy
  Vector v3 = v2; // Copy Constructor i.e., v3(v2), Memberwise Copy

  //   v3 = v2; Assignment
  // v1.assign(v2);
  return 0;
}