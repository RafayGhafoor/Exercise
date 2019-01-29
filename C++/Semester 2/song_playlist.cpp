#include <cstring>
#include <ctime>
#include <iostream>
// #include <string>

using namespace std;

struct Duration
{
    int min;
    int sec;
};

struct Song
{
    char title[101];
    char artist[101];
    Duration time;
    int tno;
};

void swapping(Song &s, Song &t)
{
    Song temp;
    temp = s;
    s = t;
    t = temp;
}

bool deletion(Song pl[], int &count)
{
    if (count == 0)
        return false;
    for (int i = count - 1; i >= 0; i--)
    {
        swapping(pl[i], pl[count]);
    }
    //	strcpy(pl[count].title, 0);
    //	strcpy(pl[count].artist, 0);
    //	pl[count].time.min = 0;
    //	pl[count].time.sec = 0;
    count--;
    return true;
}

bool add(char *titles, char *artist, int m, int s, Song pl[], int &count)
{
    if (count >= 100)
        return false;
    strcpy(pl[count].title, titles);
    strcpy(pl[count].artist, titles);
    pl[count].time.min = m;
    pl[count].time.sec = s;
    count++;
    return true;
}

void orderByTitle(Song *pl[], int count)
{
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(pl[i]->title, pl[j]->title) > 0)
                swap(pl[i], pl[j]);
}

// void shuffle(Song pl[], int count)
// {
//     int x = 0;
//     srand(time(0));
//     for (int i = 0; i < 100; i++)
//     {
//         x = rand() % 101;
//         swapping(pl[i], pl[x]);
//     }
// }

bool addSong(char *title, char *artist, int m, int s, Song *pl[], int &count)
{
    if (count >= 100)
        return false;
    Song *sp = new Song;
    strcpy(sp->title, title);
    strcpy(sp->artist, artist);
    sp->time.min = m;
    sp->time.sec = s;
    sp->tno = count;
    pl[count++] = sp;
    sp = nullptr;
    return true;
}

void printPlaylist(Song *pl[], int count)
{
    for (int i = 0; i < count; i++)
        if (pl[i]->time.sec < 10)
            cout << pl[i]->title << " - " << pl[i]->artist << " " << pl[i]->time.min
                 << ":0" << pl[i]->time.sec << pl[i]->tno << endl;
        else
            cout << pl[i]->title << " - " << pl[i]->artist << " " << pl[i]->time.min
                 << ":" << pl[i]->time.sec << " ; " << pl[i]->tno << endl;
}

int main()
{
    Song *pl[100];
    // Song pl[100];
    int count = 0;
    char title[][100] = {"Hello", "abc", "def"};
    char artist[][100] = {"Adele", "cba", "fed"};
    for (int i = 0; i < 3; i++)
    {
        addSong(title[i], artist[i], 2, 30, pl, count);
    }
    printPlaylist(pl, 3);
}