class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mini=nums[0];
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]-mini);
            mini=min(mini,nums[i]);
        }
        return ans;
    }
};