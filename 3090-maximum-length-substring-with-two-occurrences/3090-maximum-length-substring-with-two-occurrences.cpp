class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int maxsize=0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            if(mp[s[j]]<2){
            mp[s[j]]++;
            j++;
            }else{
                mp[s[i]]--;
                i++;
            }
            maxsize=max(maxsize,j-i);
        }
        return maxsize;
    }
};