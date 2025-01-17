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
    bool isBalanced(TreeNode* root) {
    
        return helper(root, 0).first;
    }

    pair<bool,int> helper(TreeNode * root, int depth){
        if (!root) return {true,depth};

        pair<bool,int> left = helper(root->left, depth+1);
        pair<bool, int> right = helper(root->right, depth+1);
        
        if(!left.first || !right.first) return {false, max(left.second, right.second)};

        if (left.second == right.second) return {true,right.second};
        
        int maxi = max(left.second, right.second);
        int lessi = min(left.second, right.second);
        
        return { (maxi - 1) == lessi, maxi};
    }
};