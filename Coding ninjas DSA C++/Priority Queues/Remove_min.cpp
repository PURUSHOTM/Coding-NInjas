/*
Code : Remove Min
Send Feedback
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.

*/

/*-------------------------------------Solution-----------------------------------------------*/
int removeMin()
{
    // Write your code here
    if (isEmpty())
    {
        return 0; // Priority Queue is empty
    }
    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();

    // down-heapify

    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndx = 2 * parentIndex + 2;

    while (leftChildIndex < pq.size())
    {
        int minIndex = parentIndex;
        if (pq[minIndex] > pq[leftChildIndex])
        {
            minIndex = leftChildIndex;
        }
        if (rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex])
        {
            minIndex = rightChildIndx;
        }
        if (minIndex == parentIndex)
        {
            break;
        }
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndx = 2 * parentIndex + 2;
    }

    return ans;
}