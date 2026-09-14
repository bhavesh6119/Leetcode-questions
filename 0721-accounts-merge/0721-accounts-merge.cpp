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

        if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];
                if(mp.find(s)==mp.end()){
                    mp[s]=i;
                }else{
                    unionbyrank(i,mp[s],parent,rank);
                }
            }
        }

        vector<vector<string>>mails(n);
        for(auto m : mp){
            string mail=m.first;
            int node=findparent(m.second,parent);
            mails[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0){
                continue;
            }
            sort(mails[i].begin(),mails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto mail : mails[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};