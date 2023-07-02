class Solution {
public:
    bool search(int i,int j,vector<vector<char>>& board,string word,int index){
        if(index==word.size()){
           return  true;
        }
        if(i<0 ||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[index] ||board[i][j]=='*') return false;
         char tp=board[i][j];
         board[i][j]='*';
         bool ans= search(i+1,j,board,word,index+1)||search(i,j+1,board,word,index+1)||search(i-1,j,board,word,index+1)||search(i,j-1,board,word,index+1);
         board[i][j]=tp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(search(i,j,board,word,index)){
                    return true;
                }
            }
        }
        return false;   
    }
};