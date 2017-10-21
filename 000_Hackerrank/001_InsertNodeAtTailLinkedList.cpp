/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node* dummy = new Node();
    dummy->data = INT8_MAX;
    dummy->next = head;
    Node* curr = dummy;
    while(curr->next != NULL) 
        curr = curr->next;
    Node* tmp = new Node();
    tmp->data= data;
    tmp->next = NULL;
    curr->next = tmp;
    return dummy->next;
}
