/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s) {
    node* curr = root;
    for(char ch : s) {
       if(ch == '1') {
           curr = curr->right;
           if(curr->left == NULL && curr->right == NULL) {
               cout << curr->data;
               curr = root;
           }
       } else {
           curr = curr->left;
           if(curr->left == NULL && curr->right == NULL) {
               cout << curr->data;
               curr = root;
           }
       }
    } 
}
