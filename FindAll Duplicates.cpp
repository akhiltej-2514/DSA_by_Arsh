class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1]>0){
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};
// this is the best solution for this problem
// we may come from o(n^2) to o(nlogn) by sorting and then comparing to o(n)and o(n) space by visited array
// but this is the best solution with o(n) time and o(1) space

//core idea :
//Same mark by negation as a lot of people use, if you ever come across a value that is positive after negating if you know you've seen it before!
//Imagine going through the list and finding a 5 somewhere random (let's say at index 1). What the first line says is go to index "5" (whatever may be there) and make it negative whatever the current value 
//is (say a 1 sits there, make it -1). Now say we come across another 5 at index 3, we again go to index 5 and make it negative. Now the 1 that is at index 5 is now positive, and when 
//we check we'll know we've visited this value twice. That means whatever value we're at in our loop is the duplicated value.

//see here 5 is answer 

//**  ans.push_back(abs(nums[i])); **// this is the key point we are pushing abs(nums[i]) not nums[i] because we have negated the value at that index