/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/
/*------------------------------------------Solution------------------------------------------------------*/
class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;
};

Pair BST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int> *node = new Node<int>(root->data);

    Pair leftans = BST(root->left);
    Pair rightans = BST(root->right);

    Pair ans;

    if (leftans.head == NULL && rightans.head == NULL)
    {

        ans.head = node;
        ans.tail = node;
    }

    else if (!leftans.head && rightans.head)
    {
        ans.head = node;
        node->next = rightans.head;

        ans.tail = rightans.tail;
    }
    else if (leftans.head && rightans.head == NULL)
    {
        ans.head = leftans.head;
        leftans.tail->next = node;
        ans.tail = node;
    }
    else
    {
        ans.head = leftans.head;
        leftans.tail->next = node;
        node->next = rightans.head;
        ans.tail = rightans.tail;
    }
    return ans;
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return BST(root).head;
}