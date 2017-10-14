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
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>();
        return generateTrees(1, n+1);    
    }
    
    vector<TreeNode*> generateTrees(int left, int right) {
        vector<TreeNode*> dp;
        if(left >= right) {
            dp.push_back(NULL);
        } else {
            for(int i = left; i < right; i++) {
                vector<TreeNode*> leftTrees = generateTrees(left, i);
                vector<TreeNode*> rightTrees = generateTrees(i+1, right);
                for(int j = 0; j < leftTrees.size(); j++) {
                    for(int k = 0; k < rightTrees.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTrees[j];
                        root->right = rightTrees[k];
                        dp.push_back(root);
                    }
                }
            }
        }
        return dp;
    }
};