/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

/*------------------------------------------Solution-------------------------------------------------*/
#include <stack>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    int currentLevelRemaining = 1;
    int nextLevelCount = 0;
    bool flag = true;
    while (!s1.empty() || !s2.empty())
    {
        if (flag)
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";
            currentLevelRemaining--;
            if (top->left != NULL)
            {
                s2.push(top->left);
                nextLevelCount++;
            }
            if (top->right != NULL)
            {
                s2.push(top->right);
                nextLevelCount++;
            }
            if (currentLevelRemaining == 0)
            {
                cout << "\n";
                currentLevelRemaining = nextLevelCount;
                nextLevelCount = 0;
                flag = false;
            }
        }
        else
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";
            currentLevelRemaining--;
            if (top->right != NULL)
            {
                s1.push(top->right);
                nextLevelCount++;
            }
            if (top->left != NULL)
            {
                s1.push(top->left);
                nextLevelCount++;
            }
            if (currentLevelRemaining == 0)
            {
                cout << "\n";
                currentLevelRemaining = nextLevelCount;
                nextLevelCount = 0;
                flag = true;
            }
        }
    }
}