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
    TreeNode* convertBST(TreeNode* root) {
        int cumsum = 0;
        TreeNode* curr = root;
        vector<TreeNode*> stack;
        while(curr != NULL || !stack.empty()) {
            while(curr!= NULL) {
                stack.push_back(curr);
                curr = curr->right;
            }
            curr = stack.back();
            int tmp = curr->val;
            curr->val = tmp + cumsum;
            cumsum += tmp;
            stack.pop_back();
            curr = curr->left;
        }
        return root;
    }
};