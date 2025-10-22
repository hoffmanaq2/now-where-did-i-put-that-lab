#pragma once

#include <string>
using namespace std;

// Find a single character inside a string.
// caseSensitive = true by default.
// startPos = 0 by default.
int where(const string& text, char ch, bool caseSensitive = true, int startPos = 0);

// Find a substring inside a string.
// caseSensitive = true by default.
// startPos = 0 by default.
int where(const string& text, const string& sub, bool caseSensitive = true, int startPos = 0);
