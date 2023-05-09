/*
Quick Sort Code

Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7
*/
#include<iostream>
using namespace std;

int part(int input[], int s, int e)
{
    // 04 Storing input of s index value to pivot variable
    int pivot = input[s];

    // 05 Using counter to check how many elements are smaller than pivot
    int count = 0;

    // 06.1 Running Loop from start +1 as we are not counting the same element we picked for comparision
    for (int i = s + 1; i <= e; i++)
    {
        // 06.2 If input [i] is smaller than pivot then increase counter
        if (input[i] <= pivot)
        {
            count++;
        }
    }
    // 07 Storing the index by adding it with start index
    int pivotIndex = s + count;

    // 08 once we get the index then we will place the element to its correct position
    swap(input[pivotIndex], input[s]);

    // 09 Storing start in i and end in j
    int i = s, j = e;

    // 10 IF i is smaller than pivotIndex and j is greater than pivotIndex then perform the loop
    while (i < pivotIndex && j > pivotIndex)
    {
        // 11.1 If value of array input[i] is smaller than pivot then increment i
        while (input[i] <= pivot)
        {
            i++;
        }
        // 11.2 If value of array input[j] is smaller than pivot then decrement j
        while (input[j] > pivot)
        {
            j--;
        }

        // 12 Then check IF i is smaller than pivotIndex and j is greater than pivotIndex then swap the element form i to j index value then increment i and decrement j
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(input[i++], input[j--]);
        }
    }
    // 13 After performing all tasks we will return pivotIndex
    return pivotIndex;
}

void temp(int *input, int s, int e)
{
    // 02 Base Case
    if (s >= e)
        return;
    for (int i = 0; i < (e - s) + 1; i++)
    {
        cout << input[i] << " ";
    }
    // 03 Getting Pivot element form the part function
    int p = part(input, s, e);

    // 14 Calling to sort for Left side index wise
    temp(input, s, p - 1);

    // 15 Calling to sort for Rigit side index wise
    temp(input, p + 1, e);
}

void quickSort(int input[], int size)
{
    // 01
    temp(input, 0, size - 1);
}