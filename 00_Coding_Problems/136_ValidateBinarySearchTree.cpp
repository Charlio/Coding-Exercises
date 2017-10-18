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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        vector<TreeNode*> stack;
        while(curr!=NULL || !stack.empty()) {
            while(curr!=NULL) {
                stack.push_back(curr);
                curr = curr->left;
            }
            curr = stack.back();
            if(prev != NULL && prev->val >= curr->val) return false;
            stack.pop_back();
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};