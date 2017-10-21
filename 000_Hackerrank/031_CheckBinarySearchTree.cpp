/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool checkBST(Node* root) {
    if(root == NULL) return true;
    vector<Node*> stack;
    stack.push_back(root);
    Node* curr = root->left;
    int prev = INT8_MIN;
    while(curr != NULL || !stack.empty()) {
        while(curr != NULL) {
            stack.push_back(curr);
            curr = curr->left;
        }
        Node* tmp = stack.back();
        stack.pop_back();
        if(tmp->data <= prev) 
            return false;
        else
            prev = tmp->data;
        curr = tmp->right;
    }
    return true;
}
