class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX,len=n-k;
        int sum=0;
        int totalsum=0;
        int mini=INT_MAX;
        for(int i=0;i<len;i++){
            sum+=nums[i];
        }
         for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        ans=min(ans,sum);
        j=len;
        while(j<n){
            sum+=nums[j];
            sum-=nums[i];
            ans=min(ans,sum);
            j++;
            i++;
        }
         return totalsum-ans;
        }
};
//same as finding n-k size minimum size sub arry it is as simple as maximizig the outer k;