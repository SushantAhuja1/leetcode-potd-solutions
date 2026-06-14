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
    int getLength(ListNode* head) {
        int length=0;
        ListNode* temp=head;
        while(temp) {
            length++;
            temp=temp->next;
        }
        return length;
    }
    int pairSum(ListNode* head) {
        int length=getLength(head);
        int ans=0;
        stack<int>st;
        ListNode* temp=head;
        for(int i=0;i<length/2;i++) {
            st.push(temp->val);
            temp=temp->next;
        }
        while(temp) {
            int sum=temp->val+st.top();
            st.pop();
            temp=temp->next;
            ans=max(ans,sum);
        }
        return ans;
    }
};