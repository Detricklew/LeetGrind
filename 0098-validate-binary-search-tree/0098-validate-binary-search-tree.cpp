/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValid(root->left, LONG_MIN, root->val) && isValid(root->right, root->val, LONG_MAX);
    }
    
    bool isValid(TreeNode* root, long mini, long maxi){
        if (!root) return true;

        if(root->val >= maxi || root->val <= mini){
            return false;
        }

        return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);

    }
    
};