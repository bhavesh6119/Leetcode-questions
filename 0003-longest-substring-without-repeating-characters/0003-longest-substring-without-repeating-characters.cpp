class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>arr(256,0);
        int first=0;
        int second=0;
        int length=0;
        while(second<s.size()){
            while(arr[s[second]]){
                arr[s[first]]=0;
                first++;
            }
            arr[s[second]]=1;
            length=max(length,second-first+1);
            second++;
        }
        return length;
    }
};