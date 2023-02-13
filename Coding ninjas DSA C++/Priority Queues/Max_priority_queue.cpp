/*
Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/

/*---------------------------------------Solution--------------------------------------------*/
#include <climits>
#include <vector>
class PriorityQueue
{
    vector<int> data;

public:
    void insert(int element)
    {
        data.push_back(element);
        int childIndex = data.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (data[parentIndex] > data[childIndex])
            {
                return;
            }
            int temp = data[childIndex];
            data[childIndex] = data[parentIndex];
            data[parentIndex] = temp;
            childIndex = parentIndex;
        }
    }
    int getMax()
    {
        if (data.size() == 0)
        {
            return INT_MIN;
        }
        return data[0];
    }
    int removeMax()
    {
        if (data.size() == 0)
        {
            return INT_MIN;
        }
        int ans = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        int parentIndex = 0;
        int leftIndex = parentIndex * 2 + 1;
        int rightIndex = leftIndex + 1;
        while (leftIndex < data.size())
        {
            int maxIndex = parentIndex;
            if (data[leftIndex] > data[maxIndex])
            {
                maxIndex = leftIndex;
            }
            if (rightIndex < data.size() && data[rightIndex] > data[maxIndex])
            {
                maxIndex = rightIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }
            int temp = data[maxIndex];
            data[maxIndex] = data[parentIndex];
            data[parentIndex] = temp;
            parentIndex = maxIndex;
            leftIndex = parentIndex * 2 + 1;
            rightIndex = leftIndex + 1;
        }
        return ans;
    }
    int getSize() { return data.size(); }
    bool isEmpty() { return data.size() == 0; }
};