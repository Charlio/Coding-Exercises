/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node* pre_head = new Node();
    pre_head->data = INT8_MAX;
    pre_head->next = head;
    Node* curr = pre_head;
    for(int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return pre_head->next;
}
