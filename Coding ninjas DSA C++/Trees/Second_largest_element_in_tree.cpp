/*
Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
40
*/

/*------------------------------------------Solution--------------------------------------------------*/
pair<TreeNode<int> *, TreeNode<int> *> getSecondLargest(TreeNode<int> *root)
{
    if (root->children.size() == 0)
        return {root, NULL};
    pair<TreeNode<int> *, TreeNode<int> *> p(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> temp = getSecondLargest(root->children[i]);
        if (temp.first->data > p.first->data)
        {
            if (p.second == NULL)
            {
                if (temp.second == NULL || temp.second->data < p.first->data)
                    p.second = p.first;
                else
                    p.second = temp.second;
            }
            else if (temp.second == NULL)
                p.second = p.first;
            else if (temp.second->data > p.first->data)
            {
                p.second = temp.second;
            }
            else if (temp.second->data < p.first->data)
            {
                p.second = p.first;
            }
            p.first = temp.first;
        }
        else if (temp.first->data < p.first->data)
        {
            if (p.second == NULL || temp.first->data > p.second->data)
            {
                p.second = temp.first;
            }
        }
    }
    return p;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    return getSecondLargest(root).second;
}

/*--------------------------------------Solution 2--------------------------------------------*/

void helper(TreeNode<int> *root, TreeNode<int> **first, TreeNode<int> **second)
{
    if (root == NULL)
    {
        return;
    }
    if (!(*first))
    {
        *first = root;
    }
    else if (root->data > (*first)->data)
    {
        *second = *first;
        *first = root;
    }
    else if (!(*second) || root->data > (*second)->data)
        *second = root;

    for (int i = 0; i < root->children.size(); i++)
        helper(root->children[i], first, second);
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    TreeNode<int> *second = NULL;
    TreeNode<int> *first = NULL;
    helper(root, &first, &second);

    if (second == NULL)
        return NULL;
    if (first->data == second->data)
        return NULL;
    return second;
    // Write your code here
}