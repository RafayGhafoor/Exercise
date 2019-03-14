#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string arrtostr(int arr[], const int &size)
{
  string s;
  stringstream out;
  for (int i = 0; i < size; i++)
    out << arr[i];
  s += out.str();

  return s;
}

int bintodec(int n)
{
  int decNum = 0, i = 0, r;
  while (n)
  {
    r = n % 10;
    n /= 10;
    decNum += r * pow(2, i);
    ++i;
  }
  return decNum;
}

string binAdd(string n1, string n2 = "1", string oper = "+")
{
  string output = "", nout = "";
  stringstream out, o;

  int a1 = stoi(n1), a2 = stoi(n2), r;
  if (oper == "+")
    r = bintodec(a1) + bintodec(a2);
  else
    r = bintodec(a1) - bintodec(a2);

  while (r > 0)
  {
    out << (r % 2);
    r /= 2;
  }
  output += out.str();
  for (int x = 0, i = output.length() - 1; i >= 0; i--)
    o << output[i];
  nout += o.str();
  return nout;
}

class BinaryNum
{
private:
  int *binNum;
  int noOfBits;

public:
  friend ostream &operator<<(ostream &out, const BinaryNum &c);
  friend istream &operator>>(istream &in, BinaryNum &c);
  friend BinaryNum operator+(string num, const BinaryNum &c);

  BinaryNum();

  BinaryNum(string num);

  BinaryNum(const BinaryNum &obj);

  int &operator[](int i) { return binNum[i]; };

  const BinaryNum &operator+(BinaryNum &obj)
  {
    string t1 = arrtostr(obj.binNum, obj.noOfBits),
           t2 = arrtostr(binNum, noOfBits);

    string num = binAdd(t1, t2);

    noOfBits = num.length();

    binNum = new int[noOfBits];

    for (int i = 0; i < noOfBits; i++)
      binNum[i] = num[i] - 48;

    return *this;
  }

  const BinaryNum &operator-(BinaryNum &obj)
  {
    string t1 = arrtostr(obj.binNum, obj.noOfBits),
           t2 = arrtostr(binNum, noOfBits);
    string num = binAdd(t2, t1, "-");

    noOfBits = num.length();

    binNum = new int[noOfBits];

    for (int i = 0; i < noOfBits; i++)
      binNum[i] = num[i] - 48;

    return *this;
  }

  const BinaryNum &operator+(string &obj)
  {
    string t1 = obj, t2 = arrtostr(binNum, noOfBits);

    string num = binAdd(t1, t2);

    noOfBits = num.length();

    binNum = new int[noOfBits];

    for (int i = 0; i < noOfBits; i++)
      binNum[i] = num[i] - 48;

    return *this;
  }

  const BinaryNum &operator+=(BinaryNum &obj)
  {
    *this = *this + obj;
    return *this;
  }

  const BinaryNum &operator++()
  {
    string t = "";
    stringstream out;

    for (int i = 0; i < noOfBits; i++)
      out << binNum[i];
    t += out.str();

    string ans = binAdd(t);

    noOfBits = ans.length();

    binNum = new int[noOfBits];

    for (int i = 0; i < noOfBits; i++)
      binNum[i] = ans[i] - 48;

    return *this;
  }

  const BinaryNum &operator++(int dummy)
  {
    string t = "";
    stringstream out;

    for (int i = 0; i < noOfBits; i++)
      out << binNum[i];
    t += out.str();

    string ans = binAdd(t);

    noOfBits = ans.length();

    binNum = new int[noOfBits];

    for (int i = 0; i < noOfBits; i++)
      binNum[i] = ans[i] - 48;

    return *this;
  }

  BinaryNum &operator=(const BinaryNum &obj)
  {
    if (binNum)
    {
      delete[] binNum;
      binNum = nullptr;
    }

    noOfBits = obj.noOfBits;
    binNum = new int[obj.noOfBits];
    for (int i = 0; i < noOfBits; i++)
      binNum[i] = obj.binNum[i];

    return *this;
  }

  bool operator==(const BinaryNum &obj) const
  {
    if (obj.binNum && binNum)
      if (obj.noOfBits != noOfBits)
        return 0;
      else
      {
        for (int i = 0; i < noOfBits; i++)
          if (obj.binNum != binNum)
            return 0;
      }
    else
      return 0;
    return 1;
  }

  void Print();
};

BinaryNum::BinaryNum()
{
  binNum = nullptr;
  noOfBits = 0;
}

BinaryNum::BinaryNum(string num)
{
  noOfBits = num.length();
  binNum = new int[noOfBits];
  for (int i = 0; i < noOfBits; i++)
    binNum[i] = num[i] - 48;
}

BinaryNum::BinaryNum(const BinaryNum &obj)
{
  if (!noOfBits)
    delete[] binNum;

  noOfBits = obj.noOfBits;
  binNum = new int[obj.noOfBits];
  for (int i = 0; i < noOfBits; i++)
    binNum[i] = obj.binNum[i];
}

void BinaryNum::Print()
{
  if (binNum)
    for (int i = 0; i < noOfBits; i++)
      cout << binNum[i];
  cout << endl;
}

ostream &operator<<(ostream &out, const BinaryNum &c)
{
  for (int i = 0; i < c.noOfBits; i++)
    out << c.binNum[i];
  out << endl;
  return out;
}

istream &operator>>(istream &in, BinaryNum &c)
{
  string num = "";
  in >> num;

  c.noOfBits = num.length();
  c.binNum = new int[c.noOfBits];

  for (int i = 0; i < c.noOfBits; i++)
    c.binNum[i] = num[i] - 48;

  return in;
}

BinaryNum operator+(string num, const BinaryNum &c)
{
  BinaryNum output(c);
  string t1 = num, t2 = arrtostr(c.binNum, c.noOfBits);

  string n = binAdd(t1, t2);

  output.noOfBits = n.length();

  output.binNum = new int[output.noOfBits];

  for (int i = 0; i < output.noOfBits; i++)
    output.binNum[i] = n[i] - 48;

  return output;
}
