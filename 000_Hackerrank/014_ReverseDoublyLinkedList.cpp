/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    Node* new_head = Reverse(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
        return new_head;
}
