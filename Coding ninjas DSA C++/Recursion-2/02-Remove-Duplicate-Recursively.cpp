/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S
Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

void removeDuplicate(char input[])
{
    // 01 Base Case
    if (input[0] == '\0')
    {
        return;
    }

    // 02.1 Small work: If the given string has no adjacent element in its 0th and 1st index then pass the array while shifting 0th index to 1st index. then calling the function
    if (input[0] != input[1])
    {
        removeDuplicate(input + 1);
    }
    else // 02.2 If the array has adjacent element in its 0th and 1st index then run a loop till null, shift all the string element to one previous index, then after loop call the recursion

    {
        int i = 1;
        for (; input[i] != '\0'; i++)
        {
            input[i - 1] = input[i];
        }
        // 02.3 Shift null to left
        input[i - 1] = input[i];

        // 03 Recursive call
        removeDuplicate(input);
    }
}