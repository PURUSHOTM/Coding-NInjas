/*
All possible ways
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 < b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways:
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

/*
Time complexity: O(A ^ (1 / B))
Space complexity: O(A ^ (1 / B))
where A and B are the two given integers
*/

/*----------------------------------------------------Solution------------------------------------------------------------*/

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int smallAns = power(a, b / 2);
    return smallAns * smallAns * power(a, b % 2);
}
int getAllWaysHelper(int a, int b, int currNum, int currSum)
{
    int result = 0;
    // Calling power of 'i' raised to 'b'
    int p = power(currNum, b);
    while (p + currSum < a)
    {
        // Recursively check all greater values of 'i'
        result += getAllWaysHelper(a, b, currNum + 1, p + currSum);
        currNum++;
        p = power(currNum, b);
    }
    /*
    If sum of powers is equal to 'a'
    then increase the value of result
    */
    if (p + currSum == a)
    {
        result++;
    }
    // Return the final result
    return result;
}
int getAllWays(int a, int b)
{
    return getAllWaysHelper(a, b, 1, 0);
}