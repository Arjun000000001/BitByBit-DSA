#include <iostream>
using namespace std;

/*
  Function: PrintSubstring
  Purpose : Print all subsequences of a given string using recursion
  Params  :
    index -> current position in original string
    str   -> input string
    temp  -> temporary string storing current subsequence
*/
void PrintSubstring(int index, string& str, string temp)
{
    // Base case: all characters processed
    if (index == str.length())
    {
        cout << temp << " ";
        return;
    }

    // Include current character
    PrintSubstring(index + 1, str, temp + str[index]);

    // Exclude current character
    PrintSubstring(index + 1, str, temp);
}

int main()
{
    string str = "ABC";
    string temp = "";

    PrintSubstring(0, str, temp);

    return 0;
}
