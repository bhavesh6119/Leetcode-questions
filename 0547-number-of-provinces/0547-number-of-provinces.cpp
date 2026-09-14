class Solution {
public:
    int findparent(int node, vector<int>&parent){
        if(node==parent[node]){
            return node;
        }

        parent[node]=findparent(parent[node],parent);
        return parent[node];
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
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        int m=isconnected[0].size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isconnected[i][j]==1){
                    unionbyrank(i,j,parent,rank);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(findparent(i,parent)==i){
                count++;
            }
        }
        return count;
    }
};