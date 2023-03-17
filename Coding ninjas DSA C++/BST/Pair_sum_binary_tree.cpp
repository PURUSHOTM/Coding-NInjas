/*
Pair Sum Binary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

/*----------------------------------------------Solution----------------------------------------------*/
#include <bits/stdc++.h>
int k = 0;
void convert(BinaryTreeNode<int> *root, int *arr)
{
    if (root == NULL)
        return;
    arr[k++] = root->data;
    convert(root->left, arr);
    convert(root->right, arr);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{
    int arr[100000000];

    convert(root, arr);

    sort(arr, arr + k);

    int i = 0;
    int j = k - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == sum)
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else if (arr[i] + arr[j] < sum)
            i++;
    }
}
