class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* small=new ListNode(-1);
        ListNode* big=new ListNode(-1);
        ListNode* shead=small;
        ListNode* bhead=big;
        ListNode* cur=head;
        while(cur){
            if(cur->val<x){          // IMP line it cant be cur->val<=x because if it is <= then order of elements will change dry run for 1->4->3->2->5->2 and x=3
                shead->next=cur;
                shead=shead->next;
            }else{
                bhead->next=cur;
                bhead=bhead->next;
            }
            cur=cur->next;
        }
        shead->next=big->next;
        bhead->next=NULL;        // IMP line  if we dont write this then it will be a cycle and will give TLE
        return small->next;    
    }
};
// very new and important concept

// 1. take two dummy nodes small and big
// 2. take two pointers shead and bhead
// 3. take a cur pointer and traverse the linked list
// 4. if cur->val<x then shead->next=cur and move shead to shead->next
// 5. else bhead->next=cur and move bhead to bhead->next
// 6. move cur to cur->next
// 7. shead->next=big->next means connect small list to big list
// 8. bhead->next=NULL means end of big list
// 9. return small->next
// Time Complexity: O(n)
// Space Complexity: O(1)

// important points:
// 
