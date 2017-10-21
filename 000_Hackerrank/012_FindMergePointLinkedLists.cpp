/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node* currA = headA;
    Node* currB = headB;
    
    while(currA != currB) {
        if(currA->next == NULL)
            currA = headB;
        else
            currA = currA->next;
        if(currB->next == NULL)
            currB = headA;
        else
            currB = currB->next;
    }
    return currA->data;
}
