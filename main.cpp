#include "src/where.hpp"
#include <iostream>

using namespace std;

int main()
{
    string text = "The quick Brown Fox";

    // Test char search
    cout << "Searching for 'e' in \"" << text << "\": "
         << where(text, 'e') << endl;

    cout << "Searching for space in \"" << text << "\": "
         << where(text, ' ') << endl;

    // Test substring search (case-insensitive)
    cout << "Searching for \"quick\" in \"" << text << "\": "
         << where(text, "quick") << endl;

    cout << "Searching for \"brown\" in \"" << text << "\": "
         << where(text, "brown") << endl;

    cout << "Searching for \"quiet\" in \"" << text << "\": "
         << where(text, "quiet") << endl;

    return 0;
}