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
    int kthSmallest(TreeNode* root, int k) {
        pair<int,int> res = helper(root, k, 0);

        return res.second;
    }

    pair<int,int> helper(TreeNode* root, int k, int pos){
        if(!root) return {pos,-1};


        pair<int,int> check = helper(root->left, k, pos);

        pos = check.first + 1;

        if(pos == k) return {pos, root->val};

        if(check.second != -1) return check;

        pair<int,int> check2 = helper(root->right, k, pos);

        return {check2.first, max(check.second,check2.second)};
    }
};