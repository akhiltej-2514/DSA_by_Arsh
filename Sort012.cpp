class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,m=0,r=n-1;
        while(m<=r){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;m++;
            }
            else if(nums[m]==1){
                m++;
            }else{
                swap(nums[m],nums[r]);
                r--;
            }
        }
    }
};

//Note :
//******Most important thing is to while(m<=r) not while(m<n)?????Think or dry run you will get it
// 3 pointer approach intialize l=0,m=0,r=n-1
// if 0 swap(l,m) l++,m++//Think Why?? you will get it
// if 1 m++ //simply it is at its correct position
// if 2 swap(m,r) r-- //Think Why?? you will get it
