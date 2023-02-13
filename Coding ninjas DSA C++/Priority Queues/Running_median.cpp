/*
Running Median
Send Feedback
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/
/*----------------------------------------------------Solution--------------------------------------------------*/
#include <queue>
void findMedian(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap; // For each element in the data stream
    for (int i = 0; i < n; i++)
    {
        if (maxHeap.size() && arr[i] > maxHeap.top())
        {
            minHeap.push(arr[i]);
        }
        else
        {
            maxHeap.push(arr[i]);
        }
        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }
        int median;
        int totalSize =
            maxHeap.size() + minHeap.size(); // When number of elements is odd
        if (totalSize % 2 == 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                median = maxHeap.top();
            }
            else
            {
                median = minHeap.top();
            }
        } // When number of elements is even
        else
        {
            median = 0;
            if (!maxHeap.empty())
                median += maxHeap.top();
            if (!minHeap.empty())
                median += minHeap.top();
            median /= 2;
        }
        cout << median << " ";
    }
}