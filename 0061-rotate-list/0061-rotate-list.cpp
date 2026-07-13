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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int cnt=0;
        ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
         k %= cnt;
        if (k == 0)
            return head;
        temp=head;
        int steps=cnt-k-1;
        while(steps--){
            temp=temp->next;
        }
        ListNode *newhead=temp->next;
        temp->next=NULL;

        ListNode *tail=newhead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        return newhead;
    }
};