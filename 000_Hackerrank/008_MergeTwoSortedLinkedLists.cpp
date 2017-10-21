/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method

    Node* currA = headA;
    Node* currB = headB;
    Node* pre_head = new Node();
    pre_head->data = INT8_MAX;
    pre_head->next = NULL;
    Node* curr = pre_head;
    
    while(currA!= NULL && currB != NULL) {
        if(currA->data <= currB->data) {
            curr->next = currA;
            currA = currA->next;
        } else {
            curr->next = currB;
            currB = currB->next;
        }
        curr = curr->next;
    }
    if(currA == NULL)
        curr->next = currB;
    else
        curr->next = currA;
    return pre_head->next;
}
