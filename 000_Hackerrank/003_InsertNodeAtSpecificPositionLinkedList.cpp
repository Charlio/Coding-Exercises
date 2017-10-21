/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    Node* pre_head = new Node();
    pre_head->data = INT8_MAX;
    pre_head->next = head;
    Node* curr = pre_head;
    for(int i = 0; i < position && curr->next != NULL; i++) {
        curr = curr->next;
    }
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = curr->next;
    curr->next = new_node;
    return pre_head->next;
}
