class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int n;
    int m;
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>>q;

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                grid[0][j]=0;
            }
        }
        for(int i=1;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=0;
            }
        }
        for(int j=1;j<m;j++){
            if(grid[n-1][j]==1){
                q.push({n-1,j});
                grid[n-1][j]=0;
            }
        }
        for(int i=1;i<n-1;i++){
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                grid[i][m-1]=0;
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi=r+row[k];
                int newj=c+col[k];
                if(valid(newi,newj) && grid[newi][newj]==1){
                    q.push({newi,newj});
                    grid[newi][newj]=0;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};