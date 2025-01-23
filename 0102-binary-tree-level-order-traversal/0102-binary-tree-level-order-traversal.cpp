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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> next;
        queue<TreeNode*> curr;
        vector<vector<int>> res;
        
        if(!root) return {};

        curr.push(root);

        while(!curr.empty()){
            vector<int> tmp;
            
            while(!curr.empty()){
                TreeNode *n = curr.front();
                if(n->left) next.push(n->left);
                if(n->right) next.push(n->right);
                tmp.push_back(n->val);
                curr.pop(); 
            }

            res.push_back(tmp);
            swap(curr, next);
        }
        
        return res;
    }
};