/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void topView(node * root) {
    node* curr = root;
    if(root == NULL) return;
    vector<int> stack;
    while(curr != NULL) {
        stack.push_back(curr->data);
        curr = curr->left;
    }
    while(!stack.empty()) {
        cout << stack.back() << " ";
        stack.pop_back();
    }
    curr = root->right;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
}
