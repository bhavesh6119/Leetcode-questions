class Solution {
public:
    bool check(int i,int j,vector<string>&board,int n){
        int row=i;
        int col=j;
        while(row>-1 && col>-1){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--;
            col--;
        }
        row=i;
        col=j;
        while(row>-1 && col<n){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--;
            col++;
        }
        return 1;
    }
    void find(int row,vector<string>&board,vector<bool>&column,vector<vector<string>>&ans,int n){
        if(row==n){//base condition
            ans.push_back(board);//push the computed way
            return;
        }
        for(int j=0;j<n;j++){//iterate on the cols
            if(column[j]==0 && check(row,j,board,n)){//check for any corresponding queens
                column[j]=1;//make it true as the col is filled
                board[row][j]='Q';//place the queen there
                find(row+1,board,column,ans,n);//move to next row
                column[j]=0;//if the placement is not possible backtrack and unmark it
                board[row][j]='.';//sane with this
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;//for final answer
        vector<string>board(n);//for storing the temporary ways 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');//make it 2d initialising from '.'
            }
        }
        
        vector<bool>column(n,0);//to check if the corresponding col is filled or not
        find(0,board,column,ans,n);//pass on to function
        return ans;
    }
};