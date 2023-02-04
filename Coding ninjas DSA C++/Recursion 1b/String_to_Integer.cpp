/*
String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// Helper Function
int stringToNumber(char input[], int last)
{
    // Base Case
    if (last == 0)
    {
        return input[last] - '0';
    }
    // Recursive Call
    int smallAns = stringToNumber(input, last - 1);
    int a = input[last] - '0';
    return smallAns * 10 + a;
}

// Recursive Function
int stringToNumber(char input[])
{
    int len = length(input);
    return stringToNumber(input, len - 1);
}
