class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int size=0;
        int maxsize=0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            if(mp[s[j]]<2){
            mp[s[j]]++;
            size++;
            j++;
            }else{
                mp[s[i]]--;
                size--;
                i++;
            }
            maxsize=max(maxsize,size);
        }
        return maxsize;
    }
};