/*
Merge Sort Code

Given the starting 'l' and the ending 'r' positions of the array 'ARR', your task is sorting the elements between 'l' and 'r'.

Note:
Change in the input array itself. So no need to return or print anything.

Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Input format :
The first line contains an integer 'N' representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output format :
You don't need to return anything. In the output, you will see the array after modification is done by you.

Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9

Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].

Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
*/

void merge(int *arr, int s, int e, int mid)
{
    // dynamically create a new array
    int *temp = new int[(e - s) + 1];
    int index1 = s, index2 = mid + 1, mainindex = 0;

    while (index1 <= mid && index2 <= e)
    {
        if (arr[index1] <= arr[index2])
        {
            temp[mainindex++] = arr[index1++];
        }
        else
        {
            temp[mainindex++] = arr[index2++];
        }
    }
    // reamaining element
    while (index1 <= mid)
    {
        temp[mainindex++] = arr[index1++];
    }

    while (index2 <= e)
    {
        temp[mainindex++] = arr[index2++];
    }

    // copying element to the main array
    for (int i = 0, j = s; i < (e - s) + 1; i++, j++)
    {
        arr[j] = temp[i];
    }
    delete[] temp;
}

void divide(int *arr, int s, int e)
{
    // 02 base case
    if (s >= e)
        return;

    // 03 find mid
    int mid = (s + e) / 2;

    // 04 recall divide function for first half
    divide(arr, s, mid);

    // 05 recall divide function for second half
    divide(arr, mid + 1, e);

    // divide completed
    // 06 time to merge the sorted array
    merge(arr, s, e, mid);
}

void mergeSort(int input[], int size)
{
    // 01
    divide(input, 0, size - 1);
}