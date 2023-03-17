/*
Check if a Binary Tree is BST
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/

/*------------------------------------Solution--------------------------------------------*/

#include <climits>
bool solve(BinaryTreeNode<int> *root, int mn, int mx)
{
    if (root == NULL)
        return 1;

    if (root->data > mx || root->data < mn)
        return 0;
    return (solve(root->left, mn, root->data - 1) && solve(root->right, root->data, mx));
}
bool isBST(BinaryTreeNode<int> *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

/*------------------------------------Solution 2---------------------------------------------*/

#include <algorithm>
#include <limits.h>

int maxi(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->data, (max(maxi(root->left), maxi(root->right))));
}

int mini(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;

    return min(root->data, (min(mini(root->left), mini(root->right))));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;

    int leftmax = maxi(root->left);
    int rightmin = mini(root->right);

    bool output = (root->data <= rightmin) and (root->data > leftmax) and
                  isBST(root->left) and isBST(root->right);

    return output;
}