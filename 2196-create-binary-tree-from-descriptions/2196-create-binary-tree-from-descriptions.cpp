/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> mp;
    int n;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root;
        set<int> ch;
        n = descriptions.size();
        for (auto& des : descriptions) {
            int parent = des[0];
            int child = des[1];
            int isLeft = des[2];
            if (!mp.count(parent) && !mp.count(child)) {
                TreeNode* pNode = new TreeNode(parent);
                TreeNode* cNode = new TreeNode(child);
                if (isLeft) {
                    pNode->left = cNode;
                } else {
                    pNode->right = cNode;
                }
                mp[parent] = pNode;
                mp[child] = cNode;
                root = pNode;
            } else if (mp.count(parent) && !mp.count(child)) {
                TreeNode* pNode = mp[parent];
                TreeNode* cNode = new TreeNode(child);
                if (isLeft) {
                    pNode->left = cNode;
                } else {
                    pNode->right = cNode;
                }
                mp[child] = cNode;
                root = pNode;
            } else if (!mp.count(parent) && mp.count(child)) {
                TreeNode* pNode = new TreeNode(parent);
                TreeNode* cNode = mp[child];
                if (isLeft) {
                    pNode->left = cNode;
                } else {
                    pNode->right = cNode;
                }
                mp[parent] = pNode;
                root = pNode;
            } else {
                TreeNode* pNode = mp[parent];
                TreeNode* cNode = mp[child];
                if (isLeft)
                    pNode->left = cNode;
                else
                    pNode->right = cNode;
            }
            ch.insert(child);
        }
        for (auto& [node, val] : mp) {
            if (ch.find(node) == ch.end()) {
                root = val;
                break;
            }
        }
        return root;
    }
};