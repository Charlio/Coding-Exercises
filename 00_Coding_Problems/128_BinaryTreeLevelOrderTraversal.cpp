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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(res, root, 0);
        return res;
    }
    
    void levelOrder(vector<vector<int>>& res, TreeNode* root, int level) {
        if(root == NULL) return;
        if(res.size() < level + 1)
            res.push_back(vector<int>());
        levelOrder(res, root->left, level+1);
        res[level].push_back(root->val);
        levelOrder(res, root->right, level+1);
    }
    
};