class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        queue<int>q;
        vector<bool>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
            }
            visited[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(visited[j]==1){
                        continue;
                    }
                    if(adj[node][j]==1 && !visited[j]){
                        q.push(j);
                        visited[j]=1;
                    }
                }
            }
        }
        return count;
    }
};