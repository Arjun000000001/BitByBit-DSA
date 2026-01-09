/*
Concept: Recursion
Problem: Print digits of a number
Approach: Extract last digit and recurse on remaining number
*/

#include <iostream>
using namespace std;

void PrintDigit(int n)
{
    if (n == 0)
        return;

    int lastDigit = n % 10;
    cout << lastDigit << " ";

    PrintDigit(n / 10);
}

int main()
{
    int num = 12345;
    PrintDigit(num);
    return 0;
}
