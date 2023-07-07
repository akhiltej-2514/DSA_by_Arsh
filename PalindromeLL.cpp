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
// 1 2 3 1 2 3 5
//       s       
//           f            
   ListNode *reverse( ListNode* head){
       ListNode *prev=NULL,*cur=head,*nxt;
       while(cur!=NULL){
           nxt=cur->next;
           cur->next=prev;
           prev=cur;
           cur=nxt;
       }
       return prev;
   }
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL){return true;}
        ListNode *slow =head,*fast=head,* dummy=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverse(slow->next);
        slow=slow->next;

        while(slow!=NULL){
            if(slow->val !=dummy->val){
                return false;
            }
            slow=slow->next;
            dummy=dummy->next;
        }
        return true;
    }
};

// https://leetcode.com/problems/palindrome-linked-list/
// find just before mid using slow and fast pointer and inntialize dummy=head
// reverse the second half of the linked list by passing slow->next to reverse function slow->next has the Mid
// move slow to slow->next to start comparing
// if slow->val != dummy->val return false else move slow and dummy to next
// return true if all elements are same

// Time Complexity: O(n)
// Space Complexity: O(1)

/// IMP line is comparing condition while(slow!=NULL) /THINK WHY slow?? because slow points to second half.. if it reach NULL all node over and also take care of odd and even length of linked list
