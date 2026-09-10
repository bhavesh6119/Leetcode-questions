class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};

    bool valid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[r][c]=steps;
            for(int k=0;k<4;k++){
                int newi=r+row[k];
                int newj=c+col[k];

                if(valid(newi,newj,n,m) && !visited[newi][newj]){
                    visited[newi][newj]=1;
                    q.push({{newi,newj},steps+1});
                }
            }
        }
        return dist;
    }
};