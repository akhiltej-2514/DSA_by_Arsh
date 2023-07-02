class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int cnt=0;
        while(i<n){
            if(nums[i]==0)cnt++;
            else {
                swap(nums[i],nums[i-cnt]);
            }
            i++;
        }
     }
};
// if zero cnt++ ifnot then it should belong to nums[i-cnt] dry run if you confuse easy peasy