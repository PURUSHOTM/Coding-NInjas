/*
Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7
*/

/*-----------------------------------------------------Solution-----------------------------------------------------------*/
#include <stack>
int countnodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{

    int totalnodes = countnodes(root);
    int count = 0;

    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revinorder;

    BinaryTreeNode<int> *temp = root;

    while (temp)
    {
        inorder.push(temp);

        temp = temp->left;
    }
    temp = root;
    while (temp)
    {
        revinorder.push(temp);

        temp = temp->right;
    }

    while (count < totalnodes - 1)
    {
        BinaryTreeNode<int> *top1 = inorder.top();
        BinaryTreeNode<int> *top2 = revinorder.top();
        if (top1->data + top2->data == s)
        {
            cout << top1->data << " " << top2->data << endl;

            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
            top = top2;
            revinorder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
        else if (top1->data + top2->data > s)
        {
            BinaryTreeNode<int> *top = top2;
            revinorder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revinorder.push(top);
                    top = top->right;
                }
            }
        }
        else
        {
            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}