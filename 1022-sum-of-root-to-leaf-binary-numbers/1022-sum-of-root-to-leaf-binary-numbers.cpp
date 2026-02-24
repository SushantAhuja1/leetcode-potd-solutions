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
    int ans=0;
    void solve(TreeNode* root, string path) {
        if(!root) return;
        path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL) {
            ans+=stoi(path,nullptr,2);
            return;
        }
        solve(root->left,path);
        solve(root->right,path);
    }
    int sumRootToLeaf(TreeNode* root) {
        string path="";
        solve(root,path);
        return ans;
    }
};