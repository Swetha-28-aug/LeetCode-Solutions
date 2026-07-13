class Solution {
    int length(ListNode *head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
public:
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA=length(headA);
    int lenB=length(headB);
    int diff=abs(lenA-lenB);
        if(lenA>lenB){
            while(diff--){
                headA=headA->next;
            }
        }else{
            while(diff--){
                headB=headB->next;
            }
        }
    while(headA!=NULL){
        if(headA==headB){
            return headA;
        }
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
    }
};