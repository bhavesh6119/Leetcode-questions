class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>Indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            Indeg[relations[i][1]-1]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!Indeg[i]){
                q.push(i);
            }
        }
        vector<int>previous_time(n,0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                Indeg[adj[node][j]]--;
                if(Indeg[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
                previous_time[adj[node][j]]=max(previous_time[adj[node][j]],previous_time[node]+time[node]);
            }
        }
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,previous_time[i]+time[i]);
            }
            return ans;
    }
};