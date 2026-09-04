class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto pre : prerequisites){
            int u=pre[1];
            int v=pre[0];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]]){
                    q.push(adj[node][j]);
                }
            }
        }
        vector<int>temp;
        return ans.size()==n ? ans : temp;
    }
};