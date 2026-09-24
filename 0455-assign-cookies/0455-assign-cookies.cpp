class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size()-1;
        int m=s.size()-1;
        int count=0;
        while(n>=0 && m>=0){
            if(g[n]<=s[m]){
                count++;
                n--;
                m--;
            }else if(g[n]>s[m]){
                n--;
            }
        }
        return count;
    }
};