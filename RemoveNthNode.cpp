class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL){return NULL;}
        ListNode * slow=head;
        ListNode * fast=head;
        while(n-- && fast){
            fast=fast->next;
        }
        if(fast==NULL){return head->next;}
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
// intution:
// 1. take two pointers slow and fast
// 2. move fast pointer n times
// 3. if fast==NULL return head->next means first node is to be deleted
// 4. move slow and fast till fast->next!=NULL means slow will be pointing to the node just before the node to be deleted
// 5. slow->next=slow->next->next means delete the node
// 6. return head
