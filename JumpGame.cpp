class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxend=0;
        for(int i=0;i<n && maxend<n-1 && i<=maxend;i++){
            maxend=max(maxend,nums[i]+i);
        }
        return maxend>=n-1;
    }
};
//Aadarsh's solution