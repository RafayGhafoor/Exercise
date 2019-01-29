#include <iostream>

using namespace std;

struct Song
{
    int track_no, year;
    char title[200] = "", artist[200] = "";
};

void initialize(Song &sp)
{
    cout << "Please enter the track number of the song: ";
    cin >> sp.track_no;
    cout << "Please enter the title of the song: ";
    cin >> sp.title;
    cout << "Please enter the artist of the song: ";
    cin >> sp.artist;
    cout << "Please enter the release year of the song: ";
    cin >> sp.year;
}

void display(Song &sp)
{
    // Displays the members of the struct
    cout << "Title: " << sp.title << "\nArtist: " << sp.artist
         << "\nYear: " << sp.year << "\nTrack Number: " << sp.track_no << endl;
}

int main()
{
    struct Song sp[2]; // Create an array of type struct consisting 2 members

    for (int i = 0; i < 2; i++)
    {
        initialize(sp[i]);
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        display(sp[i]);
        cout << endl;
    }
}