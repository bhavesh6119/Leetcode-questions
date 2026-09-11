class Solution {
public:
    int row[8]={-1,-1,1,1,-1,1,0,0};
    int col[8]={-1,1,-1,1,0,0,-1,1};
    int n;

    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(n==1){
            return 1;
        }
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1;

        while(!q.empty()){
            int count=q.size();
            while(count--){
                int r=q.front().first.first;
                int c=q.front().first.second;
                int step=q.front().second;
                q.pop();
                for(int k=0;k<8;k++){
                    int newi=r+row[k];
                    int newj=c+col[k];
                    if(valid(newi,newj) && !grid[newi][newj]){
                        if(newi==n-1 && newj==n-1){
                            return step+1;
                        }
                        grid[newi][newj]=1;
                        q.push({{newi,newj},step+1});
                    }
                }
            }
        }
        return -1;
    }
};