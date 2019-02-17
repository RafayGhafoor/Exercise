#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
struct Song {
  float version;
  char *title;
  char *artist;
  int *duration;
};

Song *InputSongs(int);
void OutputSongsLibrary(const Song *, int);
void DeAllocate(Song *, int);
bool searchSong(char *title, Song *songList);
void deallocate_song(Song *songList);
void copy_Song(Song &s1, Song &s2);

int main() {
  Song *songsArr;
  int size = 1000;
  songsArr = InputSongs(size);

  /*Search function will search the tect added in the search character array
    and will return 1 or 0 and result will be printed in the form of "Match
   found" or "Match not found" at the end of the function */
  bool found = 0;
  char *search = new char[39];
  search = " &Fugly Fugly Kya Hai - DownloadMing.S";
  found = searchSong(search, songsArr);

  /*Copy function will deep copy the value of second song struct in the first
   * song struct.*/
  copy_Song(songsArr[0], songsArr[1]);

  OutputSongsLibrary(songsArr, size);

  if (found == 1)
    cout << endl << "Match Found!!!" << endl;
  else
    cout << endl << "Match not Found." << endl;

  deallocate_song(songsArr);

  delete[] search;

  return 0;
}

Song *InputSongs(int size) {
  Song *sArr;
  sArr = new Song[size];
  ifstream fin("SongList.txt");
  char temp[200];
  for (int x = 0; x < size; x++) {
    sArr[x].duration = new int;
    fin >> sArr[x].version;
    fin.ignore();
    fin.getline(temp, 200, ',');
    sArr[x].title = new char[strlen(temp) + 1];
    strcpy(sArr[x].title, temp);
    fin.getline(temp, 200, ',');
    sArr[x].artist = new char[strlen(temp) + 1];
    strcpy(sArr[x].artist, temp);
    fin >> *(sArr[x].duration);
  }
  fin.close();
  return sArr;
}
void OutputSongsLibrary(const Song *arr, int size) {
  cout << left << setw(80) << "Title" << setw(80) << "Artist" << setw(20)
       << "Duration"
       << "Version" << endl;
  for (int x = 0; x < size; x++) {
    cout << setw(80) << arr[x].title << setw(80) << arr[x].artist << setw(20)
         << *(arr[x].duration) << arr[x].version << endl;
  }
}

bool searchSong(char *title, Song *songList) {
  int n = 0;
  n = strlen(title);
  int i = 0;
  for (int j = 0; j < 1000; j++) {
    for (i; title[i] == songList[j].title[i]; i++)
      ;
    if ((i - 1) == n) {
      return true;
      break;
    }
    i = 0;
  }
  return false;
}

void copy_Song(Song &s1, Song &s2) {
  s2.version = s1.version;
  delete s2.duration;
  s2.duration = new int;
  s2.duration = s1.duration;
  delete[] s2.title;
  s2.title = new char[strlen(s1.title) + 1];
  strcpy(s2.title, s1.title);
  delete[] s2.artist;
  s2.artist = new char[strlen(s1.artist) + 1];
  strcpy(s2.artist, s1.artist);
}

void deallocate_song(Song *songsArr) { delete[] songsArr; }
void DeAllocate(Song *arr, int size) {
  for (int x = 0; x < size; x++) {
    delete[] arr[x].title;
    delete[] arr[x].artist;
    delete arr[x].duration;
  }
}