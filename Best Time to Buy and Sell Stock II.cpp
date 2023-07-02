class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i])
             ans+=nums[i+1]-nums[i];
        }
        return ans;
    }
};

// Path: Best Time to Buy and Sell Stock II.cpp
// add all the profits if the next day is greater than the previous day
//ans+=max(ans,nums[i+1]-nums[i]);