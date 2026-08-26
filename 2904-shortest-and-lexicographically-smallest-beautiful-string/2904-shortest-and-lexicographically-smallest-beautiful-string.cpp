class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        int len=INT_MAX;
        string ans="";
        while(j<n){
            if(s[j]=='1'){
                count++;
            }
            if(count>k){
                if(s[i]=='1'){
                    count--;
                }
                i++;
            }
            if(count==k){
                while(s[i]=='0'){
                    i++;
                }
                int currlen=j-i+1;
                string curr=s.substr(i,currlen);
                if(currlen<len){
                    len=currlen;
                    ans=curr;
                }else if(currlen==len && curr<ans){
                    ans=curr;
                }
            }
            j++;
        }
        return ans;
    }
};