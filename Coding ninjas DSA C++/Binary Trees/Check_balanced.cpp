/*
Check Balanced
Send Feedback
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format
The first and only line of output contains true or false.
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

/*-------------------------------------------Solution---------------------------------------------*/
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return true;

    int leftH = height(root->left);
    int rightH = height(root->right);

    if (abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

/*-----------------------------------------Coding-Ninjas solution-----------------------------------------------*/
class BalancedReturnType
{
public:
    int height;
    bool balanced;
};
BalancedReturnType *isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        BalancedReturnType *ans = new BalancedReturnType();
        ans->height = 0;
        ans->balanced = true;
        return ans;
    }
    BalancedReturnType *ans1 = isBalancedHelper(root->left);
    BalancedReturnType *ans2 = isBalancedHelper(root->right);
    bool flag;
    if (!(ans1->balanced) || !(ans2->balanced) || abs(ans1->height - ans2->height) > 1)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    BalancedReturnType *output = new BalancedReturnType();
    output->height = max(ans1->height, ans2->height) + 1;
    output->balanced = flag;
    return output;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    return isBalancedHelper(root)->balanced;
}