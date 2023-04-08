/*
Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/

/*----------------------------------------------------Solution------------------------------------------------------------*/
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    // Write your code here
    if (n == 0 || m == 0)
        return 0;
    int dp[n][m] = {0};

    // Initialization
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (arr[i][0]) ? 0 : 1;
        ans = max(ans, dp[i][0]);
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = (arr[0][i]) ? 0 : 1;
        ans = max(ans, dp[0][i]);
    }

    // Filling up dp table. Where each entry at (i,j) tells of largest size
    // of the subsquare possible ending at (i,j);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            if (arr[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] =
                    1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}