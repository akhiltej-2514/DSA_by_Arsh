class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i==0 ||(i>0 && (nums[i]!=nums[i-1]))){
            int target=0-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]>target)r--;
                else if (nums[l]+nums[r]<target)l++;
                else{
                    vector<int>tp;
                    tp.push_back(nums[i]);
                    tp.push_back(nums[l]);
                    tp.push_back(nums[r]);
                    ans.push_back(tp);
                    while(l<r and nums[l]==nums[l+1]){l++;}
                    while(l<r and nums[r]==nums[r-1]){r--;}
                    l++;
                    r--;
                }
            }
        }     }
        return ans;   
    }
};

//(i==0 ||(i>0 && (nums[i]!=nums[i-1])) this is to avoid duplicates remove this and see the difference u will get it all the duplicates
//while(l<r and nums[l]==nums[l+1]){l++;}  //this is to avoid duplicates