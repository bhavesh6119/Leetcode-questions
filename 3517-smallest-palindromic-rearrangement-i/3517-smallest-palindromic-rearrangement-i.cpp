class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>small(26,0);
        int n=s.size();
        for(int i=0;i<n/2;i++){
            small[s[i]-'a']++;
        }
        string ans(n,' ');
        int index=0;
        for(int i=0;i<26;i++){
            while(small[i]){
                char c='a'+i;
                ans[index]=c;
                small[i]--;
                index++;
            }
        }
        if(n%2!=0){
            ans[n/2]=s[n/2];
        }
        for(int i=0;i<n/2;i++){
            ans[n-1-i]=ans[i];
        }
        return ans;
    }
};