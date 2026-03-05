/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>arr;
        ListNode* x = head;
        while(x) {
            arr.push_back(x->val);
            x=x->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* root = new ListNode(arr[0]);
        x=root;
        for(int i=1;i<arr.size();i++) {
            ListNode* curr = new ListNode(arr[i]);
            x->next = curr;
            x = curr;
        }
        return root;
    }
}; 