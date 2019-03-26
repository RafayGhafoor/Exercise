#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*

- A library has any number of books

- Library can print details of all books

- Library can issue a book

- A book can print itself

- All books have an author, title, ISBN and number of copies.

- Books are either issuable or reference books

- Issuable book has a date of issue (in number of days format (int) ),

(-1, if the book is unissued) {i) for each copy} {ii) borrowers}

- Issuable books can tell whether they are available, who they are issued to.

- Reference books are either periodicles or not (Periodicles have Issue number or Edition number)
  (Both Issuable and Reference books can print themselves)

*/

class Book
{
    string author, title, ISBN;
    int copies;

  public:
    Book(string author, string title, string ISBN, int copy)
    {
        this->author = author;
        this->title = title;
        this->ISBN = ISBN;
        this->copies = copy;
    }

    int getNoOfCopies() const
    {
        return copies;
    }

    void print()
    {
        cout << title << endl << author << endl << ISBN << endl << copies;
    }
};

class Issuable : public Book
{
    vector<string> borrowers; // Contains users to whom the book is issued
    vector<int> days;

  public:
    Issuable(string auth, string t, string isbn, int cpy, vector<string> brw, vector<int> &d) : Book(auth, t, isbn, cpy), borrowers(brw), days(d)
    {
    }

    // Issuable(vector<string> borrowers, int days, bool issued)
    // {
    //     for (int i = 0; i < borrowers.size(); i++)
    //         borrowers[i] = borrowers[i];
    //     issued = is_issued;
    //     if (!is_issued)
    //         days = -1;
    //     else
    //         days = days;
    // }

    // Specialization/Overriding of parent class function
    void print()
    {
        Book::print();
        for (int i = 0; i < copies; i++)
            cout << days[i] << ", "  << borrowers[i] << endl;
    }
};

class Reference : public Book
{
    bool is_periodicle;

    //   public:
};

// class Library
// {

//   public:
//     Library()
//     {
//     }
// };
int main()
{
    string a = "Hello";
    vector<string> t;
    vector<int> n;
    Issuable abc(a, a, a, 20, t, n);
    abc.print();
}