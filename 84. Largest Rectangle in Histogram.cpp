class Solution {
public:
    int largestRectangleArea(vector<int>& ar) {
        int n= ar.size();
        stack<long long>s;
        long long  left[n];
        long long  right[n];
      for(long long  i=0;i<n;i++){
          while(!s.empty()&&ar[s.top()]>=ar[i]){
              s.pop();
          }
          if(s.empty()){left[i]=0;}
          else{left[i]=s.top()+1;}
          s.push(i);
      }
      while(!s.empty()){s.pop();}
      
      for(long long  i=n-1;i>=0;i--){
          while(!s.empty()&&ar[s.top()]>=ar[i]){
              s.pop();
          }
          if(s.empty()){right[i]=n-1;}
          else{right[i]=s.top()-1;}
          s.push(i);
      }
      
     long long  maxi=0;
     for(long long i=0;i<n;i++){
         if((right[i]-left[i]+1)*ar[i]>maxi){
             maxi=(right[i]-left[i]+1)*ar[i];
         }
     }
      return maxi;
    }
};

//left[i] stores the index of the first bar the left which is smaller than the current bar
//right[i] stores the index of the first bar the right which is smaller than the current bar
//so the width of the rectangle will be right[i]-left[i]+1

//revise next greater element to right and next greater element to left things