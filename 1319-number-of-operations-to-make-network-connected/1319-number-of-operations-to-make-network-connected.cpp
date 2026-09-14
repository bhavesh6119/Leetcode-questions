class Solution {
public:
    int findparent(int node,vector<int>&parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node],parent);
    }
    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank){
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);

        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int countedges=0;
        for(auto connect : connections){
            int u=connect[0];
            int v=connect[1];
            if(findparent(u,parent)==findparent(v,parent)){
                countedges++;
            }else{
                unionbyrank(u,v,parent,rank);
            }
        }

        int countset=0;
        for(int i=0;i<n;i++){
            if(findparent(i,parent)==i){
                countset++;
            }
        }
        int ans=countset-1;

        if(countedges>=ans){
            return ans;
        }
        return -1;
    }
};