/*
Check Palindrome (recursive)
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include <cstring>
bool helper(char input[], int start, int end)
{
    if (start == end)
        return true;
    if (input[start] != input[end])
        return false;
    if (start < end)
    {
        return helper(input, start + 1, end - 1);
    }
}
bool checkPalindrome(char input[])
{
    int n = strlen(input);
    helper(input, 0, n - 1);
}