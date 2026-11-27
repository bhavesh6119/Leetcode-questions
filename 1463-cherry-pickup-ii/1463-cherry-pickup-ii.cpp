class Solution {
public:
    int find(int i,int j1,int j2,int m,int n,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n ){
            return -1e9;
        }
        if(i==m-1){
            if(j1==j2){
                return arr[i][j1];
            }else{
                return arr[i][j1]+arr[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=-1e9;
        for(int s=-1;s<=+1;s++){
            for(int t=-1;t<=+1;t++){
                int value=0;
                
                if(j1==j2){
                    value=arr[i][j1];
                }else{
                    value=arr[i][j1]+arr[i][j2];
                }
                value+=find(i+1,j1+s,j2+t,m,n,arr,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        int total=find(0,0,n-1,m,n,grid,dp);
        return total;
    }
};