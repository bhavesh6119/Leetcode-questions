class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
            }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j=0;j<graph[node].size();j++){
                    if(color[graph[node][j]]==-1){
                        color[graph[node][j]]=(color[node]+1)%2;
                        q.push(graph[node][j]);
                    }else{
                        if(color[graph[node][j]]==color[node]){
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};