#include "../src/where.hpp"
#include <cctype> // for tolower

// Helper: make a lowercase copy of a string
string toLowerCopy(const string& s)
{
    string lower = s;
    for (size_t i = 0; i < lower.length(); i++)
    {
        lower[i] = tolower(static_cast<unsigned char>(lower[i]));
    }
    return lower;
}

// Character search
int where(const string& text, char ch, bool caseSensitive, int startPos)
{
    // Handle invalid starting position
    if (startPos < 0 || startPos >= static_cast<int>(text.length()))
        return -1;

    for (size_t i = startPos; i < text.length(); i++)
    {
        if (caseSensitive)
        {
            if (text[i] == ch)
                return static_cast<int>(i);
        }
        else
        {
            if (tolower(static_cast<unsigned char>(text[i])) == tolower(static_cast<unsigned char>(ch)))
                return static_cast<int>(i);
        }
    }
    return -1; // not found
}

// Substring search
int where(const string& text, const string& sub, bool caseSensitive, int startPos)
{
    if (sub.empty() || text.empty() || sub.length() > text.length())
        return -1;

    if (startPos < 0 || startPos >= static_cast<int>(text.length()))
        return -1;

    string searchText = text;
    string searchSub = sub;

    if (!caseSensitive)
    {
        searchText = toLowerCopy(text);
        searchSub = toLowerCopy(sub);
    }

    for (size_t i = startPos; i <= searchText.length() - searchSub.length(); i++)
    {
        bool match = true;

        for (size_t j = 0; j < searchSub.length(); j++)
        {
            if (searchText[i + j] != searchSub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
            return static_cast<int>(i);
    }

    return -1;
}