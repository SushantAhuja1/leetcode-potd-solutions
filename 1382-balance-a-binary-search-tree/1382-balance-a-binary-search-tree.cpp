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
    vector<int>inorder;
    void travel(TreeNode* root) {
        if(!root) return;
        travel(root->left);
        inorder.push_back(root->val);
        travel(root->right);
    }
    TreeNode* solve(int l,int r) {
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = solve(l,mid-1);
        node->right = solve(mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        travel(root);
        int n=inorder.size();
        return solve(0,n-1);
    }
}; 