class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans*=2;                // this line comes first Why? take example 1->0->0->0 and dry run it for 1 ans will be 1 if code is ans*=2  as first line.
            ans+=head->val;
            head=head->next;
        }
        return ans;
    }
};
//1 0 0 0
//evry thime multiply by 2 and add the current value