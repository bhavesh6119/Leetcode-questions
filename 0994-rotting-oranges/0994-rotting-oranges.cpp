class Solution {
public:
    int r;
    int c;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        int timer=0;
        while(!q.empty()){
            timer++;
            int curr_size=q.size();
            while(curr_size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]==1){
                        grid[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer==0 ? 0 : timer-1;
    }
};