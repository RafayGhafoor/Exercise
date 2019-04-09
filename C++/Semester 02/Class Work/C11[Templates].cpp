#include <iostream>

using namespace std;

template <typename T> class myVec {
  T *vec;
  int cap, size;

public:
  myVec {
    vec = nullptr;
    cap = size = 0;
  }

  myVec(const myVec<T> &obj) {
    size = obj.size;
    cap = obj.cap;
    vec = new T[cap];
    for (int i = 0; i < size; i++)
      vec[i] = obj[i];  
  }

  myVec(int c) {
    cap = c;
    size = 0;
    vec = new T[cap];
  }

  void push_back(const T &obj) {
    if (size < cap)
      vec[size++] = obj;

    else {
      T *temp = new T[cap * 2];
      for (int i = 0; i < size; i++)
        temp[i] = vec[i];

      temp[size] = obj;
      delete[] vec;
      vec = temp;
      size++;
      cap *= 2;
    }
  }

  T &const operator[](const int &index) { return vec[index]; }
};

int main() {}
