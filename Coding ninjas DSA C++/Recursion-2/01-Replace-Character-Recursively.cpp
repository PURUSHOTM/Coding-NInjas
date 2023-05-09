/*
Replace Character Recursively

Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.

Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :
Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/

#include <iostream>
using namespace std;

void get(char *input, char c1, char c2, int size)
{
    // 02 Base Case
    if (input[size] == '\0')
        return;

    // 03 Small Work
    if (input[size] == c1)
    {
        input[size] = c2;
    }

    // 04 Recursive Call while increasing size
    get(input, c1, c2, size + 1);
}

void replaceCharacter(char input[], char c1, char c2)
{
    // 01
    get(input, c1, c2, 0);
}