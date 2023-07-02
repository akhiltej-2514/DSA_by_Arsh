class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int ways=0;
        int n=nums.size();
        mp[0]=1; 
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ways+=mp[sum-k];
            mp[sum]++;
        }
        return ways;
    }
};

//intuition
//You know it ;)
//...3.....6   (we can there is sum 0f 3 between 3 and 6)

//imp
//intaliize mp[0]=1; // sum of making 0 is 1 -> taking