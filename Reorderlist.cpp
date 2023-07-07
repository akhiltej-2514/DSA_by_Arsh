class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;   
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){ 
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head){
           next=head->next;
           head->next=prev;
           prev=head;
           head=next; 
        }
        return prev;
    }
    void reorderList(ListNode* head) {
         ListNode* mid=getMiddle(head);
         ListNode* reversed=reverseList(mid->next);
         mid->next=NULL; // set next of middle element to null to avoid cyclic path
         while(head && reversed){
             ListNode* temp=head->next;     
             ListNode* tempr=reversed->next;
             head->next=reversed;          
             head->next->next=temp;
             head=temp;
             reversed=tempr;
         }

    }
};
//1->5->2->3->NULL 4->NULL
//L*tp=head->next->next
//L*tp2=->next->next
//head->next=revhead;
//rev->rp;


//intuition: 1->2->3->4->5->6->7->8->9->10->11->12->13->14->15
//very important to understand the logic
// 1.find the middle element
// 2.reverse the second half of the list reverse second head=reverse(mid->next);
// 3. set mid->next=NULL to avoid cyclic path

////4. merge the two lists (very tricky) to simulate 
////i. store the next of head in temp bcz we will lose the link
////ii. store the next of reversed in tempr bcz we will lose the link
////iii. head->next=revhead; // set the next of head to reversed head
////iv. head->next->next=temp; // set the next of reversed head to temp
////v. head=temp; // move head to temp
////vi. reversed=tempr; // move reversed to tempr
////vii. repeat the above steps till head and reversed are not null
////viii. return head


