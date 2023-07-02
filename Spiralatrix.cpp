class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ar) {
        int n=ar.size();
        int m=ar[0].size();
        int top=0,down=n-1,right=m-1,left=0;
        vector<int>ans;
        int dir=0;
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(ar[top][i]);
                }
                top++;
            }
            else if(dir==1){
                 for(int i=top;i<=down;i++){
                    ans.push_back(ar[i][right]);
                }
                right--;
            }
             else if(dir==2){
                 for(int i=right;i>=left;i--){
                    ans.push_back(ar[down][i]);
                }
               down--;
            }
            else if(dir==3){
                 for(int i=down;i>=top;i--){
                    ans.push_back(ar[i][left]);
                }
               left++;
            }
            dir++;
            dir=(dir)%4;
        }
        return ans;
        
    }
};
