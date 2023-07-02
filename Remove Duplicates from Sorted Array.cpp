class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{
                nums[i-cnt]=nums[i];
            }
        }
        return n-cnt;
    }
};

// // if duplicate cnt++ if not then it should belong to nums[i-cnt] dry run if you confuse easy peasy
// n-cnt is the size of the array after removing duplicates