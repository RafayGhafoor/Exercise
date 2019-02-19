#include <cstring>
#include <iostream>

using namespace std;

class Vector
{
  public:
    // Default Constructor
    Vector()
    {
        vec = nullptr;
        size = cap = 0;
    }

    // Parametric Constructor
    Vector(int capacity)
    {
        vec = new int[capacity];
        cap = capacity, size = 0;
    }

    ~Vector()
    {
        if (vec)
        {
            delete[] vec;
            vec = nullptr;
        }
    }

  private:
    int *vec; // Dynamically allocated array
    int size, cap;

    void push_back(int num)
    {
        if (size == cap)
        {
            // Double the capacity
            int *ptr = new int[cap * 2];

            for (int i = 0; i < cap; i++)
                ptr[i] = vec[i];

            delete[] vec;
            vec = nullptr;

            vec = ptr;
            cap *= 2;
        }

        vec[size++] = num;
    }
};

int main()
{
    Vector v1, v2(50), v3; // Empty dynamic array, Spaces allocated for 50 members
    for (int i = 0; i < 100; i++)
    {
        v2.push_back(i);
    }
    Vector v3 = v2; // Copy Constructor i.e., v3(v2)
    // v3 = v2; Assignment
    return 0;
}