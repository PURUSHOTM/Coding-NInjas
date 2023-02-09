/*
Next Number
Send Feedback
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0
*/
/*----------------------------------------------Solution-----------------------------------------------------------*/
// Recursive method to reverse a linked list
Node *reverse(Node *head)
{
    Node *temp = head;
    if (head->next)
    {
        head = reverse(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
    }
    return head;
}
/* First reverse the number, add 1 to it and traverse it for carry to travel till the most significant digit and then if carry exists, append to linked list and reverse again to get final result */
Node *NextLargeNumber(Node *head)
{
    head = reverse(head);
    int carry = 1, num;
    Node *ptr = head, *prev = NULL;
    while (ptr)
    {
        num = ((ptr->data) + carry) % 10;
        carry = ((ptr->data) + carry) / 10;
        ptr->data = num;
        prev = ptr;
        ptr = ptr->next;
    }
    if (carry)
    {
        Node *tail = new Node(carry);
        prev->next = tail;
    }
    return reverse(head);
}