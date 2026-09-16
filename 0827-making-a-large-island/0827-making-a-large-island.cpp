class DSU {
public:
    vector<int>rank,parent,size;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findparent(int node,vector<int>&parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node],parent);
    }
    void unionbysize(int u,int v,vector<int>&parent,vector<int>&size){
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    bool valid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                for(int k=0;k<4;k++){
                    int newi=i+row[k];
                    int newj=j+col[k];
                    if(valid(newi,newj,n) && grid[newi][newj]==1){
                        int nodeno=i*n+j;
                        int adjnodeno=newi*n+newj;
                        ds.unionbysize(nodeno,adjnodeno,ds.parent,ds.size);
                    }
                }
            }
        }
        int maxi=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                set<int>components;
                for(int k=0;k<4;k++){
                    int newi=i+row[k];
                    int newj=j+col[k];
                    if(valid(newi,newj,n) && grid[newi][newj]==1){
                     components.insert(ds.findparent(newi*n+newj,ds.parent));
                    }
                }
                int total=0;
                for(auto it : components){
                    total+=ds.size[it];
                }
                maxi=max(maxi,total+1);
            }
        }
        for(int c=0;c<n*n;c++){
            maxi=max(maxi,ds.size[ds.findparent(c,ds.parent)]);
        }
    return maxi;
    }
};