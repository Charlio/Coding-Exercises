/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void inOrder(node *root) {
    vector<node*> stack;
    if(root == NULL) return;
    stack.push_back(root);
    node* curr = root->left;
    while(curr!= NULL || !stack.empty()) {
        while(curr != NULL){
          stack.push_back(curr);
          curr = curr->left;
        }
        node* tmp = stack.back();
        stack.pop_back();
        cout << tmp->data << " ";
        curr = tmp->right;
    }
}
