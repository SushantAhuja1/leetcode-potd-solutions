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
    vector<int>preOrder;
    void travel(TreeNode* root) {
        if(!root) return;
        preOrder.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        travel(root);
        TreeNode* dummy=root;
        for(int i=1;i<preOrder.size();i++) {
            dummy->left = NULL;
            dummy->right = new TreeNode(preOrder[i]);
            dummy = dummy->right;
        }
    }
};