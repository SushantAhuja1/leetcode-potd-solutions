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
        if(!head) return 0;
        if(head->next==NULL) return 1;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL || k==0) return head;
        ListNode* temp=head;
        int cnt=0,n=getLength(head);
        k=k%n;
        if(k==0) return head;
        ListNode* prevToStart=NULL;
        while(temp!=NULL && cnt<n-k) {
            cnt+=1;
            prevToStart=temp;
            temp=temp->next;
        }
        ListNode* start=temp;
        ListNode* dummy=temp;
        while(dummy->next!=NULL) {
            dummy=dummy->next;
        }
        dummy->next=head;
        head=start;
        prevToStart->next=NULL;
        return head;
    }
};


// 1->2->3->4->5- and k=2 length=5 so start=n-k=5-2=3
//  \-<-<-|-<-<-| 