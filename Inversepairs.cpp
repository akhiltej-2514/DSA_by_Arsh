
long long merge(long long arr[], int low, int mid, int high){
  int left=low;
  int right=mid+1;
  long long cnt=0;
  vector<long long >tp;
  while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
        tp.push_back(arr[left]);
        left++;
    }
    else{
         cnt+=(mid-left+1);
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
  return cnt;
}

  long long mergeSort(long long arr[], int low, int high){
      long long cnt=0;
    if(low < high){
        int mid = (low+high)/2;
        cnt+=mergeSort(arr, low, mid);
       cnt+=mergeSort(arr, mid+1, high);
       cnt+=merge(arr, low, mid, high);
    }
    return cnt;
  }

    long long int inversionCount(long long arr[], long long N)
    { long long cnt=0;
       cnt=mergeSort(arr,0,N-1);
        return cnt;
    }



//[2, 4,].  [ 1, 3, 5]

