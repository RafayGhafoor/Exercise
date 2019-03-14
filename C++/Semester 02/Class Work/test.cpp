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
  void addDef(const string &w, const string &m) { ents.push_back(entry(w, m)); }

  void print()
  {
    cout << "\n\nDisplaying Word: Meanings\n\n";
    for (int i = 0; i < ents.size(); i++)
      cout << "[" << i + 1 << "] " << ents[i].word << " : " << ents[i].meaning
           << endl;
  }

  string lookUp(const string &word)
  {
    for (int i = 0; i < ents.size(); i++)

      if (word == ents[i].word)
        return ents[i].meaning;

    return "Not found!";
  }
};

int main()
{
  Dictionary my_dict;

  my_dict.addDef("Hello", "Greetings!");
  my_dict.addDef("World", "A place where we all live!!");

  string out = my_dict.lookUp("Hello");
  cout << out << endl;

  out = my_dict.lookUp("World");
  cout << out << endl;

  out = my_dict.lookUp("Something!");
  cout << out << endl;

  my_dict.print();
}