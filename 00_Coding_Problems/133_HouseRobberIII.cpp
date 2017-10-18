/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int left = rob(root->left);
        int right = rob(root->right);
        
        int left_next = 0;
        if(left != 0) {
            left_next = rob(root->left->left) + rob(root->left->right);
        }        
        
        int right_next = 0;
        if(right != 0) {
            right_next = rob(root->right->left) + rob(root->right->right);
        }
        
        return max(root->val+left_next+right_next, left+right);
    }
};