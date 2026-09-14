class Solution {
public:

    void DFS(int node,int parent,vector<vector<int>>&adj,vector<int>&value,vector<int>&low,vector<bool>&visited,vector<vector<int>>&bridges,int& count){
        value[node]=low[node]=count;
        visited[node]=1;
        
        for(int j=0;j<adj[node].size();j++){
            int neighbour=adj[node][j];
            if(neighbour==parent){
                continue;
            }
            else if(visited[neighbour]){
                low[node]=min(low[node],low[neighbour]);
            }
            else{
                count++;
                DFS(neighbour,node,adj,value,low,visited,bridges,count);
                low[node]=min(low[node],low[neighbour]);
                if(value[node]<low[neighbour]){
                    vector<int>temp;
                    temp.push_back(node);
                    temp.push_back(neighbour);
                    bridges.push_back(temp);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto connect : connections){
            int u=connect[0];
            int v=connect[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>value(n);
        vector<int>low(n);
        vector<bool>visited(n,0);
        int count=0;
        vector<vector<int>>bridges;
        DFS(0,-1,adj,value,low,visited,bridges,count);

        return bridges;
    }
};