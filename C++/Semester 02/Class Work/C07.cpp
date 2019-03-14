#include <iostream>
#include <string>
#include <vector>
using namespace std;

class entry
{
private:
  string word, meaning; // Composition: One object inside another class;

public:
  entry(const string &w, const string &m)
      : word(w), meaning(m) {} // Member initialiation list
  friend class Dictionary;
};

class Dictionary
{
private:
  vector<entry> ents;

public:
  // string &operator[](const string &w)
  // {
  //   static string temp;
  //   for (int i = 0; i < ents.size(); i++)
  //     if (ents[i].word == w)
  //       return ents[i].meaning;
  //   temp = "Not found!";
  //   return temp;
  // }

  void addWord(const string &w, const string &m)
  {
    ents.push_back(entry(w, m));
  }
};

int main()
{
  Dictionary d;
  // d.addWord("hello", "greetings!");
  // string t = d["hello"];
  // cout << t << endl;
}