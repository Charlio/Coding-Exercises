/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node* slow = head;
    Node* fast = head;
    for(int i = 0; i < positionFromTail; i++)
        fast = fast->next;
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
