class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int n=s.size();
        int maxdepth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }else if(s[i]==')'){
                depth--;
            }
            maxdepth=max(maxdepth,depth);
        }
        return maxdepth;
    }
};