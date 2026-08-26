class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;
        int n=s.size();
        int i=0;
        int j=0;
        int len=0;
        while(j<n){
            while(mp[s[j]]==1){
                mp[s[i]]=0;
                i++;
            }
            mp[s[j]]=1;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};