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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> curr;
        vector<int> res;
        
        if(!root) return {};

        curr.push_back(root);

        while(!curr.empty()){

            int size = curr.size();
            res.push_back(curr.back()->val);
            for (int i = 0; i < size; i++){
                TreeNode *n = curr.front();
                if(n->left) curr.push_back(n->left);
                if(n->right) curr.push_back(n->right);
                curr.pop_front(); 
            }

        }
        
        return res;
    }
};