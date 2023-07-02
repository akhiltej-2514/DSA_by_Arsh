class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            ans=max(ans,(r-l)*min(height[r],height[l]));
            if(height[r]<height[l]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};

//intiation
/*
The widest container (using first and last line) is a good candidate, because of its width.
 Its water level is the height of the smaller one of first and last line.
All other containers are less wide and thus would need a higher water level in order to hold more water.
The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

*/