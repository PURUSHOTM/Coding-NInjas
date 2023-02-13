/*
Construct Tree from Postorder and Inorder
Send Feedback
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements.
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
Sample Output 1:
1
2 3
4 5 6 7
Sample Input 2:
6
2 9 3 6 10 5
2 6 3 9 5 10
Sample Output 2:
5
6 10
2 3
9
*/

/*----------------------------------------Solution--------------------------------------------*/
BinaryTreeNode<int> *tree(int *post, int ps, int pe, int *in, int &postorder)
{
    if (ps > pe)
        return NULL;

    BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(post[postorder--]);

    int k;
    for (k = ps; k <= pe; k++)
    {
        if (in[k] == post[postorder + 1])
            break;
    }
    temp->right = tree(post, k + 1, pe, in, postorder);

    temp->left = tree(post, ps, k - 1, in, postorder);

    return temp;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{

    int post = postLength - 1;

    return tree(postorder, 0, postLength - 1, inorder, post);
}