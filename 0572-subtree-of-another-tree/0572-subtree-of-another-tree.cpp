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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if (root->val == subRoot->val){
            if(helper(root,subRoot)) return true;
        }

        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);

    }

    bool helper(TreeNode* root, TreeNode* root2){
        if (!root && !root2) return true;
        if (!root || !root2) return false;

        if (root->val != root2->val) return false;

        return (helper(root->right, root2->right) && helper(root->left, root2->left));
    }
};