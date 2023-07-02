class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return nums[0];
        int slow=0;
        int fast=0;
        while(fast<n){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

//Note : same like find the starting point of the loop in linked list
// undersand that here we are dealing with index not the value. so we are not using the value of the array
// we are using the index of the array as the value of the array 
// understand base case is n<=2
// and the slow and fast pointer are initialized with 0 not 1
//break condition is slow==fast and while condition is fast<n