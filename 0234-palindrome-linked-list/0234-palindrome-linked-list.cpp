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
    ListNode *reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
       while(fast!=NULL && fast->next!=NULL ){
        fast=fast->next->next;
        slow=slow->next;
       }
       ListNode *second=reverse(slow);
       bool flag=true;
       while(second!=NULL){
        if(second->val!=head->val){
            flag=false;
            break;
        }
        second=second->next;
        head=head->next;
       }
       return flag;
    }
};