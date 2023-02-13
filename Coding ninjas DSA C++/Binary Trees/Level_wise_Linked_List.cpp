/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5
6 10
2 3
9
*/

/*--------------------------------------------Solution---------------------------------------------*/
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> output;
    if (root == NULL)
    {
        return output;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int currentLevelRemaining = 1;
    int nextLevelCount = 0;
    Node<int> *currentLevelHead = NULL;
    Node<int> *currentLevelTail = NULL;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *first = pendingNodes.front();
        pendingNodes.pop();
        Node<int> *newNode = new Node<int>(first->data);
        if (currentLevelHead == NULL)
        {
            currentLevelHead = newNode;
            currentLevelTail = newNode;
        }
        else
        {
            currentLevelTail->next = newNode;
            currentLevelTail = newNode;
        }
        if (first->left != NULL)
        {
            pendingNodes.push(first->left);
            nextLevelCount++;
        }
        if (first->right != NULL)
        {
            pendingNodes.push(first->right);
            nextLevelCount++;
        }
        currentLevelRemaining--;
        if (currentLevelRemaining == 0)
        {
            output.push_back(currentLevelHead);
            currentLevelHead = NULL;
            currentLevelTail = NULL;
            currentLevelRemaining = nextLevelCount;
            nextLevelCount = 0;
        }
    }
    return output;
}