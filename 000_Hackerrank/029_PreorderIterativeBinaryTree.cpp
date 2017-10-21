/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void preOrder(node *root) {
    vector<node*> stack;
    if(root == NULL) return;
    stack.push_back(root);
    while(!stack.empty()) {
        node* tmp = stack.back();
        stack.pop_back();
        cout << tmp->data << " ";
        if(tmp->right != NULL)
            stack.push_back(tmp->right);
        if(tmp->left != NULL)
            stack.push_back(tmp->left);
    }
}
