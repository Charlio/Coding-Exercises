
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root == NULL || root->left == NULL && root->right == NULL) return 0;
        else
            return 1 + max(height(root->left), height(root->right));
    }
  