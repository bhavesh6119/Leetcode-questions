class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto k : knowledge){
            mp[k[0]]=k[1];
        }
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                int j=s.find(')',i+1);
                auto str=s.substr(i+1,j-i-1);
                if(mp.count(str)){
                    ans+=mp[str];
                }else{
                    ans+='?';
                }
                i=j;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};