class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0;
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(c==0){
                ele=nums[i];
                c++;          //imp;
            }
            else if(ele==nums[i]){
                c++;
            }
            else{
                c--;
            }
        }
        return ele;
    }
};

//intuiation 
// if there is a elemnet with n/2 frequency then all other elements will be <=n/2
// so we can cancel them out
// and the last element will be the majority element

//imp
//if(c==0) {......c++;} see c is count of ele so if c==0 then we have to make c=1 and ele=nums[i];