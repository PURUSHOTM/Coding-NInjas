/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2

*/

/*___________________________________________________solution_____________________________________________________________________*/
int pairSum(int *input, int n)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.count(input[i]) == 0)
            m[input[i]] = 1;
        else
            m[input[i]] += 1;
        if (m.count(-input[i]))
        {
            count = count + m[-input[i]];
            if (input[i] == 0)
                count--;
        }
    }
    return count;
}

/*___________________________________________________solution_____________________________________________________________________*/
int pairSum(int *arr, int n)
{
    unordered_map<int, int> freq;
    int pairCount = 0;
    for (int i = 0; i < n; ++i)
    {
        int complement = -arr[i];
        if (freq.find(complement) != freq.end())
        {
            pairCount += freq[complement];
        }
        ++freq[arr[i]];
    }
    return pairCount;
}

/*___________________________________________________solution_____________________________________________________________________*/
#include <unordered_map>
int pairSum(int *arr, int n)
{
    // Write your code here
    int count = 0;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        if (ump.count(-1 * arr[i]) > 0)
        {
            count += ump[-1 * arr[i]];
        }
        ump[arr[i]]++;
    }

    return count;
}