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
    // vector<vector<int>>arr;
    vector<int>ans;
    void lot(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            vector<int>temp;
            int sz=q.size();
            while(sz--) {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // arr.push_back(temp);
            ans.push_back(temp.back());
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        lot(root);
        // for(auto &i:arr) {
        //     for(auto &j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};