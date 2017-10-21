/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node* pre_head = new Node();
    pre_head->data = INT8_MIN;
    pre_head->next = head;
    Node* curr = pre_head;
    Node* new_node = new Node();
    new_node->data = data;
    while(curr->next != NULL) {
        if(curr->next->data > data) {
            new_node->next = curr->next;
            curr->next->prev = new_node;
            curr->next = new_node;
            new_node->prev = curr;
            return pre_head->next;
        }
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->next = NULL;
    new_node->prev = curr;
    return pre_head->next;
}
