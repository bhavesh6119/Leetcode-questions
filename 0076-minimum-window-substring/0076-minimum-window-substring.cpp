class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size();
        int m=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        int start=0;
        int end=0;
        int total=n;
        int ans=INT_MAX;
        int index=-1;

        while(end<m){
            mp[s[end]]--;
            if(mp[s[end]]>=0){
                total--;
            }
            while(total==0 && start<=end){
                if(ans>(end-start)+1){
                    ans=(end-start)+1;
                    index=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0){
                    total++;
                }
                start++;
            }
            end++;
        }
        if(index==-1){
            return "";
        }
        return s.substr(index,ans);
    }
};