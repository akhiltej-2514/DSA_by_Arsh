class Solution {
public:
   int x[8]={1,1,1,-1,-1,-1,0,0};
   int y[8]={1,0,-1,1,0,-1,1,-1};
    void gameOfLife(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        int nx=i+x[k];
                        int ny=j+y[k];
                     if(nx<n && ny<m && nx>=0 && ny>=0){
                         if(mat[nx][ny]==1||mat[nx][ny]==2){
                             cnt++;
                         }

                     }
                    }
                    if(cnt==3){
                        mat[i][j]=3;
                    }
    
                }else{
                     int cnt=0;
                    for(int k=0;k<8;k++){
                        int nx=i+x[k];
                        int ny=j+y[k];
                     if(nx<n && ny<m && nx>=0 && ny>=0){
                         if(mat[nx][ny]==1||mat[nx][ny]==2){
                             cnt++;
                         }

                     }
                    }
                    if(cnt<2){
                        mat[i][j]=2;
                    }
                    if(cnt>3){
                        mat[i][j]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    mat[i][j]=0;
                }else if(mat[i][j]==3){
                    mat[i][j]=1;
                }
            }
        }

    }
};

//live->dies->2------>1
//dead--->live->3------>0