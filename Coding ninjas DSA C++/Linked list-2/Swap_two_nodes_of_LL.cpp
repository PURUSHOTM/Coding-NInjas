/*
Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40
90 80 90 25 65 85 70
*/
/*----------------------------------------------Solution-----------------------------------------------------------*/
Node *swapNodes(Node *head, int i, int j)
{
    // write your code here
    Node *p = head;
    Node *q = head;
    for (int index = 0; index < i; index++)
    {
        p = p->next;
    }
    for (int index = 0; index < j; index++)
    {
        q = q->next;
    }
    int x = p->data;
    p->data = q->data;
    q->data = x;
    return head;
}

/*

*/
/*----------------------------------------------coding ninjas Solution-----------------------------------------------------------*/
Node *swapNodes(Node *head, int i, int j)
{
    if (i == j)
    {
        return head;
    }
    Node *currentNode = head, *prev = NULL;
    Node *firstNode = NULL, *secondNode = NULL, *firstNodePrev = NULL,
         *secondNodePrev = NULL;
    int pos = 0;
    while (currentNode != NULL)
    {
        if (pos == i)
        {
            firstNodePrev = prev;
            firstNode = currentNode;
        }
        else if (pos == j)
        {
            secondNodePrev = prev;
            secondNode = currentNode;
        }
        prev = currentNode;
        currentNode = currentNode->next;
        pos++;
    }
    if (firstNodePrev != NULL)
    {
        firstNodePrev->next = secondNode;
    }
    else
    {
        head = secondNode;
    }
    if (secondNodePrev != NULL)
    {
        secondNodePrev->next = firstNode;
    }
    else
    {
        head = firstNode;
    }
    Node *currentFirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentFirstNode;
    return head;
}