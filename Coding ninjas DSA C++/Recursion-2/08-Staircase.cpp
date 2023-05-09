/*
Staircase

A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

Input format :
Integer N
Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4
Sample Output 1 :
7

Sample Input 2 :
5
Sample Output 2 :
13
*/

int staircase(int n)
{
    // Base Case
    if (n < 0)
        return 0;

    // Edge Case
    if (n == 0)
        return 1;

    // Recursive call

    // if The child take one step at a time
    int a = staircase(n - 1);

    int b = staircase(n - 2);

    int c = staircase(n - 3);

    return a + b + c;
}