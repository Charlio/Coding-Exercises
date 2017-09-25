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

    int balanced_height(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = balanced_height(root->left);
        if (left_height == -1) return -1;
        int right_height = balanced_height(root->right);
        if (right_height == -1) return -1;
        if (abs(left_height - right_height) > 1 ) return -1;
        return max(left_height, right_height) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return balanced_height(root) != -1;
    }
};