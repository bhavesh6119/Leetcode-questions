class Solution {
public:
    string removeOuterParentheses(string s) {
        int outer=0;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(outer>0){
                    ans+=s[i];
                }
                outer++;
            }else{
                outer--;
                if(outer>0){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};