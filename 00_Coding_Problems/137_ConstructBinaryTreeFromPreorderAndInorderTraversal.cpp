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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int pre_left, vector<int>& inorder, int in_left, int in_right) {
        if(in_left > in_right) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_left]);
        int pos = find(inorder.begin(), inorder.end(), preorder[pre_left]) - inorder.begin();
        root->left = buildTree(preorder, pre_left+1, inorder, in_left, pos-1);
        root->right = buildTree(preorder, pre_left+pos-in_left+1, inorder, pos+1, in_right);
        return root;
    }
    
};