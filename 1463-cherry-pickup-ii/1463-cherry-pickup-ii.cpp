class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2){
                    dp[m-1][j1][j2]=grid[m-1][j1];
                }else{
                    dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
                }
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi=-1e9;
                    for(int s=-1;s<=+1;s++){
                        for(int t=-1;t<=+1;t++){
                            int value=0;
                            
                            if(j1==j2){
                                value=grid[i][j1];
                            }else{
                                value=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+s>=0 && j1+s<n && j2+t>=0 && j2+t<n){
                                value+=dp[i+1][j1+s][j2+t];
                            }else{
                                value+=-1e9;
                            }
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }

        return dp[0][0][n-1];
    }
};