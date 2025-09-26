#pragma once

#include <string>
using namespace std;

// Find a single character inside a string (case-insensitive).
// Returns index if found, or -1 if not found.
int where(const string& text, char ch);

// Find a substring inside a string (case-insensitive).
// Returns starting index if found, or -1 if not found.
int where(const string& text, const string& sub);
