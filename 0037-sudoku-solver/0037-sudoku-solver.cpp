class Solution {
public:
    bool check(int num,vector<vector<char>>&board,int i,int j){
        char c=num+'0';//take the number char
        for(int col=0;col<9;col++){//find in the curr col
            if(board[i][col]==c){
                return 0;//if exist return 0
            }
        }
        for(int row=0;row<9;row++){//find in the curr row
            if(board[row][j]==c){
                return 0;
            }
        }
        int row=i/3*3;//to find the start of the box in rows
        int col=j/3*3;//to find the start of the box in col
        for(int a=row;a<row+3;a++){//iterate
            for(int b=col;b<col+3;b++){
                if(board[a][b]==c){//if found return 0
                    return 0;
                }
            }
        }
        return 1;//if not found anywhere
    }
    bool find(int i,int j,vector<vector<char>>&board){
        if(i==9){//base condition
            return 1;
        }
        if(j==9){//if we reach the last col then proceed to next row 
            return find(i+1,0,board);
        }
        if(board[i][j]!='.'){//if we dont find the empty cell in the current column move to next column
            return find(i,j+1,board);
        }

        for(int num=1;num<10;num++){//iterate on the numbers
            if(check(num,board,i,j)){//here we check for the conditions
                board[i][j]='0'+num;//if condition in true then place the number char
                if(find(i,j+1,board)){//go to next column 
                    return 1;//if it return true that means the number has been placed correctly
                }
                board[i][j]='.';//otherwise backtrack make it empty again
            }
        }
        return 0;//if not properly placed
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(0,0,board);//just pass onto function
    }
};