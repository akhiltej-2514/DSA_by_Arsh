class Solution {
public:
void  merge(vector<int>&arr, int low, int mid, int high){
  int left=low;
  int right=mid+1;
  vector<int>tp;
  while(left<=mid && right<=high){

    if(arr[left]<=arr[right]){
        tp.push_back(arr[left]);
        left++;
    }
    else{
         tp.push_back(arr[right]);
         right++;
    }
  }
    while(left<=mid){
        tp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
         tp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=tp[i-low];
    }
}
int countpairs(vector<int>&nums,int low,int mid,int high){
    int c=0;
    int right=mid+1;
    for(int left=low;left<=mid;left++){
        while(right<=high && nums[left]>2*(long long)nums[right]){
            right++;
        }
        c+=(right-(mid+1));
    }
    return c;
}

int mergeSort(vector<int>&arr, int low, int high){
    int c=0;
    if(low < high){
        int mid = (low+high)/2;
       c+= mergeSort(arr, low, mid);
       c+= mergeSort(arr, mid+1, high);
       c+= countpairs(arr,low,mid,high);
        merge(arr, low, mid, high);
    }
    return c;
}
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums,0,nums.size()-1);
    }
};
