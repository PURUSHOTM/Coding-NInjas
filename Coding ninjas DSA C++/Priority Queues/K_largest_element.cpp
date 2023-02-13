/*
Code : K largest elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
4
Sample Output :
12
16
20
25
*/

/*----------------------------------------------Solution----------------------------------------------------*/
#include <queue>

vector<int> kLargest(int input[], int n, int k)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (input[i] > maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(input[i]);
        }
    }
    vector<int> output;
    while (!maxHeap.empty())
    {
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return output;
}
