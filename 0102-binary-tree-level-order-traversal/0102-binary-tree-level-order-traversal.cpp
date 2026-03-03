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
    vector<vector<int>> ans;
    void lot(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int sz=q.size();
            vector<int>temp;
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        lot(root);
        return ans;
    }
};