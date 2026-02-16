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
    unordered_map<int,int>mp;
    vector<pair<int,int>>vec;
    int getSum(TreeNode* root) {
        if(!root) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        return root->val+getSum(root->left)+getSum(root->right);
    }
    void traverse(TreeNode* root) {
        if(!root) return;
        int subTreeSum=getSum(root);
        mp[subTreeSum]++;
        traverse(root->left);
        traverse(root->right);
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        return a.second>b.second;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        for(auto &it:mp) {
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        // for(auto &i:vec) {
        //     cout<<i.first<<" : "<<i.second<<endl;
        // }
        vector<int>ans;
        int maxFrq=vec[0].second;
        for(auto &i:vec) {
            if(i.second==maxFrq) {
                ans.push_back(i.first);
            } else {
                break;
            }
        }
        return ans;
    }
};