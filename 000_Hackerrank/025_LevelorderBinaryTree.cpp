
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void levelOrder(node * root) {
    queue<node*> tree_queue;
    if(root != NULL)
        tree_queue.push(root);
    while(!tree_queue.empty()) {
        node* curr = tree_queue.front();
        tree_queue.pop();
        cout << curr->data << " ";
        if(curr->left != NULL)
            tree_queue.push(curr->left);
        if(curr->right != NULL)
            tree_queue.push(curr->right);
    }
}
