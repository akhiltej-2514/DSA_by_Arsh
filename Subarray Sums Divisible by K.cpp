class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
             ans+=mp[rem];
             mp[rem]++;
        }
        return ans;
    }
};
//IMP intialize ******   mp[0]=1 ******
// if u get a remainder rem at some point and you again get it it means there is a subarray whose sum is divisible by k
// so we store the remainders in a map and if we get the same remainder again we add the value of that remainder in the ans
// if we get a negative remainder we add k to it to make it positive because -1%5=-1 but we want 4
// and we increment the value of that remainder in the map