#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <list>

using namespace std;

template <class Node_entry>
struct Node
{
    // data members
    Node_entry entry;
    Node<Node_entry> *next;
    Node<Node_entry> *back;
    // constructors
    Node();
    Node(Node_entry, Node<Node_entry> *link_back = NULL,
         Node<Node_entry> *link_next = NULL);
};

template <class List_entry>
class List
{
  public:
    // methods of the List ADT
    List();
    int size() const;
    bool full() const;
    bool empty() const;
    void clear();
    int count;
    error_code traverse(void (*visit)(List_entry &));
    error_code retrieve(int position, List_entry &x) const;
    error_code remove(int position, List_entry &x);
    error_code insert(int position, const List_entry &x);

  protected:
    // data members for a contiguous list implementation

    List_entry entry[15];
    mutable int current_position;
    mutable Node<List_entry> *current;

    Node<List_entry> *set_position(int position) const;
};

template <class List_entry>
int List<List_entry>::size() const
{
    return count;
};

template <class List_entry>
void List<List_entry>::set_position(int position) const
{
    if (current position <= position)
        for (; current position != position; current position++)
            current = current->next;
    else
        for (; current position != position; current position−−)
            current = current->back;
};

template <class List_entry>
error_code List<List_entry>::insert(int position, const List_entry &x)
{
    Node<List_entry> *new_node, *following, *preceding;
    if (position < 0 || position > count)
        return range_error;

    if (position == 0)
    {
        if (count == 0)
            a
                following = NULL;
        else
        {
            set_position(0);
            following = current;
        }
        preceding = NULL;
    }
    else
    {
        set_position(position − 1);
        preceding = current;
        following = preceding->next;
    }
    new_node = new Node<List_entry>(x, preceding, following);
    if (new_node == NULL)
        return overflow;
    if (preceding != NULL)
        preceding->next = new_node;
    if (following != NULL)
        following->back = new_node;
    current = new_node;
    current_position = position;
    count++;
    return success;
};

class Editor : public List<string>
{
  public:
    Editor(ifstream *file_in, ofstream *file_out);
    bool get_command();
    void run_command();

  private:
    ifstream *infile;
    ofstream *outfile;
    char user_command;
    // auxiliary functions
    error_code next_line();
    error_code previous_line();
    error_code goto_line();
    error_code insert_line();
    error_code substitute_line();
    error_code change_line();
    void write_file();
    void read_file();
    void find_string();
};

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage:\n\t edit inputfile outputfile" << endl;
        exit(1);
    }
    ifstream file_in(argv[1]); // Declare and open the input stream.
    if (file_in == 0)
    {
        cout << "Cant open input file " << argv[1] << endl;
        exit(1);
    }
    ofstream file_out(argv[2]); // Declare and open the output stream.
    if (file_out == 0)
    {
        cout << "Cant open output file " << argv[2] << endl;
        exit(1);
    }
    Editor buffer(&file_in, &file_out);
    while (buffer.get_command())
        buffer.run_command();
}

Editor::Editor(ifstream *file_in, ofstream *file_out)
{
    infile = file_in;
    outfile = file_out;
};

bool Editor::get_command()
{
    if (current != NULL)
        cout << current_position << " : " << current->entry.c_str() << "\n??" << flush;
    else
        cout << "File is empty.\n??" << flush;
    cin >> user_command; // ignores white space and gets command
    user_command = tolower(user_command);
    while (cin.get() != '\n')
        ; // ignore user’s enter key
    if (user_command == 'q')
        return false;
    else
        return true;
};

template <class List_entry>
void Editor::run_command()
{
    string temp_string;
    cout << "Press h or ? for help or enter a valid command: ";

    if (user_command == 'b')
    {
        if (empty())
            cout << " Warning: empty buffer " << endl;
        else
            while (previous_line() == success)
                ;
        goto point;
        ;
    }
    if (user_command == 'c')
    {
        if (empty())
            cout << " Warning: Empty file" << endl;
        else if (change_line() != success)
            cout << " Error: Substitution failed " << endl;
        goto point;
        ;
    }
    if (user_command == 'd')
    {
        if (remove(current_position, temp_string) != success)
            cout << " Error: Deletion failed " << endl;
        goto point;
        ;
    }
    if (user_command == 'e')
    {
        if (empty())
            cout << "Warning: Buffer is empty" << endl else while (next_line() == success);
        goto point;
    }
    if (user_command == 'f')
    {
        if (empty())
            cout << " Warning: Empty file" << endl;
        else
            find_string();
        goto point;
        ;
    }
    if (user_command == 'g')
    {
        if (goto_line() != success)
            cout << " Warning: No such line" << endl;
        goto point;
    }
    if (user_command == '?' || user_command == "h")
    {
        cout << "Valid commands are: b(egin) c(hange) d(el) e(nd)"
             << endl
             << "f(ind) g(o) h(elp) i(nsert) l(ength) n(ext) p(rior) " << endl
             << "q(uit) r(ead) s(ubstitute) v(iew) w(rite) " << endl;
    }
    if (user_command == 'i')
    {
        if (insert_line() != success)
            cout << " Error: Insertion failed " << endl;
        goto point;
        ;
    }
    if (user_command == 'l')
    {
        cout << "There are " << size() << " lines in the file." << endl;
        if (!empty())
            cout << "Current line length is " << strlen((current->entry).c_str()) << endl;
        goto point;
        ;
    }
    if (user_command == 'n')
    {
        if (next_line() != success)
            cout << " Warning: at end of buffer" << endl;
        goto point;
        ;
    }
    if (user_command == 'p')
    {
        if (previous_line() != success)
            cout << " Warning: at start of buffer" << endl;
        goto point;
        ;
    }
    if (user_command == 'r')
    {

        read_file();
        goto point;
        ;
    }
    if (user_command == 's')
    {
        if (substitute_line() != success)
            cout << " Error: Substitution failed " << endl;
        goto point;
        ;
    }
    if (user_command == 'v')
    {

        traverse(write);
        goto point;
        ;
    }
    if (user_command == 'w')
    {

        if (empty())
            cout << " Warning: Empty file" << endl;
        else
            write_file();
        goto point;
        ;
    }
point:
};
void Editor::read_file()
{
    bool proceed = true;
    if (!empty())
    {
        cout << "Buffer is not empty; the read will destroy it." << endl;
        cout << " OK to proceed? " << endl;
        cout << "(Y)es or (N)0" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y')
            clear();
    }
    int line_number = 0, terminal_char;
    while (proceed)
    {
        ifstream read_in;
        read_in.open("hw.txt");
        string in_string;
        read_in >> in_string;
        if (terminal_char == EOF)
        {
            proceed = false;
            if (strlen(in_string.c_str()) > 0)
                insert(line_number, in_string);
        }
        else
            insert(line_number++, in_string);
    }
};

error_code Editor::insert_line()
{
    int line_number;
    cout << " Insert what line number? " << flush;
    cin >> line_number;
    while (cin.get() != 'n')
        ;
    cout << " What is the new line to insert? " << flush;
    string userString;
    cin >> userString;
    string to_insert = userString;
    return insert(line_number, to_insert);
};:blush: