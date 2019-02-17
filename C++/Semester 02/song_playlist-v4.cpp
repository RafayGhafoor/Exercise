#include <iostream>

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

struct Node
{
    Song s;
    Node *next = nullptr;
};

void addSong(Song &s, Node *&plhead, Node *&pltail, int &count)
{
    if (count == 0)
    {
        plhead = pltail = new Node;
        plhead->next = nullptr;
        plhead->s = s;
        count++;
    }
    else
    {
        pltail->next = new Node;
        pltail = pltail->next;
        pltail->next = nullptr;
        pltail->s = s;
        count++;
    }
}

void delPlaylist(Node *&plhead)
{
    while (!plhead)
    {
        delete[] plhead;
        plhead = plhead->next;
    }
}

void printPlaylist(Node *plhead)
{
    while (!plhead)
    {
        cout << plhead;
        plhead = plhead->next;
    }
}

int main()
{
    Node *plhead, *pltail;
    plhead = pltail = new Node;
    return 0;
}