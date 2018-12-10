#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char names[5][30];
    int votes[5], total_votes = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Please enter name for candidates no. " << i << " : ";
        cin >> names[i];
        cout << "Enter number of votes received by the candidate: ";
        cin >> votes[i];
        total_votes += votes[i];
    }

    // \t means 4 spaces
    cout << "Candidate\tVotes Received\t% of Total Votes" << endl;
    
    // Curious about How Formatting is done?
    // Read 2nd answer with 32 UPVOTES: 
    // https://stackoverflow.com/questions/15884284/c-printing-spaces-or-tabs-given-a-user-input-integer
    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << string(strlen(names[i]), ' ')
             << string(strlen("votes received\t"), ' ') << votes[i]
             << string(strlen("% of total votes"), ' ')
             << (votes[i] * 1.0) / total_votes << endl;
    }

    // cout << "The Winner of the Election is: "
    //      << "2";
}
