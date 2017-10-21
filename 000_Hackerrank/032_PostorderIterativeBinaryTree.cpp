/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void postOrder(node *root) {
    if(root == NULL) return;
    vector<int> vals;
    vector<node*> stack;
    stack.push_back(root);
    while(!stack.empty()) {
        node* tmp = stack.back();
        stack.pop_back();
        vals.push_back(tmp->data);
        if(tmp->left != NULL)
            stack.push_back(tmp->left);
        if(tmp->right != NULL)
            stack.push_back(tmp->right);
    }
    while(!vals.empty()) {
        cout << vals.back() << " ";
        vals.pop_back();
    }
}
