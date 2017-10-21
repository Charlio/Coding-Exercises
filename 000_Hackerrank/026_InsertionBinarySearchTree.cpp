/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value) {
    if(root == NULL) {
        node* new_node = new node();
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
    } else {
        if(root->data <= value)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);
    }
   return root;
}
