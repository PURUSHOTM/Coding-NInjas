/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

/*___________________________________________________solution_____________________________________________________________________*/
#include <unordered_map>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
    }

    int maxFreqElement;
    // if more than one element have the same count value then return the element whose index is low
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == maxFreq)
        {
            maxFreqElement = arr[i];
            break;
        }
    }
    return maxFreqElement;
}

/*___________________________________________________solution_____________________________________________________________________*/
#include <unordered_map>
int highestFrequency(int *input, int n)
{

    unordered_map<int, int> max;
    for (int i = 0; i < n; i++)
    {
        max[input[i]]++;
    }

    int key = 0;
    int value = 0;

    for (int i = 0; i < n; i++)
    {
        if (max[input[i]] > value)
        {
            key = input[i];
            value = max[input[i]];
        }
    }
    return key;
}

/*___________________________________________________solution_____________________________________________________________________*/
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> mp;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(arr[i]) > 0)
        {
            count = mp[arr[i]] + 1;
            mp[arr[i]] = count;
        }
        else
        {
            mp[arr[i]] = 1;
        }
    }
    int maxnumber = arr[0];
    int maxcount = mp[arr[0]];
    for (int i = 1; i < n; i++)
    {
        if (mp[arr[i]] > maxcount)
        {
            maxnumber = arr[i];
            maxcount = mp[arr[i]];
        }
    }
    return maxnumber;
}