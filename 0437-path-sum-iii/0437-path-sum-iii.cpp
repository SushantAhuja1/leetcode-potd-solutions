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
    #define ll long long
    int getPaths(TreeNode* root, ll targetSum, ll sum) {
        if(!root) return 0;
        ll paths=0;
        sum+=root->val;
        if(sum==targetSum) {
            paths++;
        }
        paths+=getPaths(root->left,targetSum,sum);
        paths+=getPaths(root->right,targetSum,sum);
        sum-=root->val;
        return paths;
    }
    int solve(TreeNode* root, int targetSum) {
        if(!root) return 0;
        ll ans=0;
        ans+=getPaths(root,targetSum,0);
        ans+=solve(root->right,targetSum);
        ans+=solve(root->left,targetSum);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};