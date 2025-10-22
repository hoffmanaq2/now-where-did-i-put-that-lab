#include "src/where.hpp"
#include <iostream>

using namespace std;

int main()
{
    string text = "The quick brown fox";

    cout << "Case-sensitive (default) searches:\n";
    cout << "Searching for 'e': " << where(text, 'e') << endl;
    cout << "Searching for 'e' from position 0: " << where(text, 'e', true, 0) << endl;
    cout << "Searching for 'e' from position 1: " << where(text, 'e', true, 1) << endl;
    cout << "Searching for 'e' from position 2: " << where(text, 'e', true, 2) << endl;
    cout << "Searching for 'e' from position 3: " << where(text, 'e', true, 3) << endl;
    cout << "Searching for 'e' from position 500: " << where(text, 'e', true, 500) << endl;

    cout << "\nCase-insensitive search:\n";
    cout << "Searching for 'B' in \"" << text << "\" (case-insensitive): "
         << where(text, 'B', false) << endl;
    cout << "Searching for \"FOX\" (case-insensitive): "
         << where(text, "FOX", false) << endl;

    cout << "\nSubstring search with starting position:\n";
    cout << "Searching for \"o\" starting at 0: " << where(text, "o", true, 0) << endl;
    cout << "Searching for \"o\" starting at 12: " << where(text, "o", true, 12) << endl;
    cout << "Searching for \"o\" starting at 17: " << where(text, "o", true, 17) << endl;

    return 0;
}
