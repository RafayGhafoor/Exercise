#include <cstring>
#include <iostream>
using namespace std;

// Problem:

// Write a function CountWordsWithoutVowels that receive a character array as an
// input parameter and returns the count of the words without vowels. The
// function CountWordsWithoutVowels finds a word in the character array and then
// it must call/use the function ContainsVowel to check if the word contains a
// vowel or not.

// Example

// If input string = “sly fox can spy and fly”, then the function
// CountWordsWithoutVowels will call the function ContainsVowel six times, and
// will return 3 because the input contains three words without vowels.

bool containsVowel(char word[], int start, int end) {
  char vowels[] = "aeiou";

  for (int i = start + 1; i < end; i++)
    for (int j = 0; vowels[j] != 0; j++)
      if (word[i] == vowels[j])
        return true;

  return false;
}

int countWordsWithoutVowels(char word[]) {
  int st = -1, count = 0, i = 0;
  for (; word[i] != 0; i++) {
    if (word[i] == ' ') {
      if (!containsVowel(word, st, i))
        count++;

      st = i;
    }
  }

  if (!containsVowel(word, st, i))
    count++;

  return count;
}

int main() {

  char w[] = "sly fox can spy and fly";

  char vowels[] = "aeiou";

  int count = 0, j = 0;

  for (int i = 0; w[i] != 0; i++)

    if (w[i + 1] == ' ' || w[i + 1] == 0) {
      bool found = true;

      for (; j <= i && found; j++)

        for (int index = 0; vowels[index] != 0 && found; index++)

          if (w[j] == vowels[index])
            found = false;

      j = i + 2;

      if (found)
        count++;
    }
  cout << "The count is: " << count << endl;
  cout << "The count is: " << countWordsWithoutVowels(w) << endl;
}