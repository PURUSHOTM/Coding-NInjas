/*
Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S.
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/

// Change in the given string itself. So no need to return or print anything

#include <string.h>
void helper(char input[], int s)
{

    if (input[s] == '\0' || input[s + 1] == '\0')
    {
        return;
    }
    helper(input, s + 1);
    if (input[s] == 'p' && input[s + 1] == 'i')
    {
        for (int i = strlen(input); i >= s + 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[s] = '3';
        input[s + 1] = '.';
        input[s + 2] = '1';
        input[s + 3] = '4';
    }
}
void replacePi(char input[])
{
    // Write your code here

    helper(input, 0);
}
