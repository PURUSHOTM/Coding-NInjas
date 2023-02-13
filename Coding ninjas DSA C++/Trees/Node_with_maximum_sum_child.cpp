/*
Node with maximum child sum
Send Feedback
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/

/*----------------------------------------------Solution--------------------------------------------------*/

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    TreeNode<int> *ans = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *x = maxSumNode(root->children[i]);
        int xSum = x->data;
        for (int i = 0; i < x->children.size(); i++)
        {
            xSum = xSum + x->children[i]->data;
        }
        if (xSum > sum)
        {
            ans = x;
            sum = xSum;
        }
    }
    return ans;
}

/*-----------------------------------------Solution 2---------------------------------------------*/

#include <climits>
template <typename T>
class MaxNodePair
{
public:
    TreeNode<T> *node;
    int sum;
};
MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    MaxNodePair<int> *ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;
    for (int i = 0; i < root->children.size(); i++)
    {
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);
        if (childAns->sum > ans->sum)
        {
            ans = childAns;
        }
    }
    return ans;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    return maxSumNodeHelper(root)->node;
}