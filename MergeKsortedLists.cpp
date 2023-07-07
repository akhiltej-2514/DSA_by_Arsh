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
   ListNode * merge(ListNode * l1,ListNode* l2){
       ListNode *cur=new ListNode(0);
       ListNode *dummy=cur;
       while(l1 && l2){
           if(l1->val<=l2->val){
               cur->next=l1;
               l1=l1->next;
           }
           else{
               cur->next=l2;
                l2=l2->next;
           }
            cur=cur->next;
       }
       if(l1!=NULL){
           cur->next=l1;
       }
       if(l2!=NULL){
           cur->next=l2;
       }
       return dummy->next;
   }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
         ListNode * ans=lists[0];
        for(int i=0;i<n-1;i++){
            ListNode * l1=ans;
            ListNode * l2=lists[i+1];
            ans=merge(l1,l2);
        }
        return ans;
    }
};