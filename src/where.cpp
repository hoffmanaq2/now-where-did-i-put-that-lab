#include "../src/where.hpp"
#include <cctype> // for tolower

// Helper function: make a lowercase copy of a string
string toLowerCopy(const string& s)
{
    string lower = s;
    for (size_t i = 0; i < lower.length(); i++)
    {
        lower[i] = tolower(static_cast<unsigned char>(lower[i]));
    }
    return lower;
}

// Find a single character (case-insensitive)
int where(const string& text, char ch)
{
    char lowerCh = tolower(static_cast<unsigned char>(ch));

    for (size_t i = 0; i < text.length(); i++)
    {
        if (tolower(static_cast<unsigned char>(text[i])) == lowerCh)
        {
            return static_cast<int>(i);
        }
    }

    return -1; // not found
}

// Find a substring (case-insensitive)
int where(const string& text, const string& sub)
{
    if (sub.empty() || text.empty() || sub.length() > text.length())
    {
        return -1;
    }

    string lowerText = toLowerCopy(text);
    string lowerSub = toLowerCopy(sub);

    for (size_t i = 0; i <= lowerText.length() - lowerSub.length(); i++)
    {
        bool match = true;

        for (size_t j = 0; j < lowerSub.length(); j++)
        {
            if (lowerText[i + j] != lowerSub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return static_cast<int>(i);
        }
    }

    return -1; // not found
}