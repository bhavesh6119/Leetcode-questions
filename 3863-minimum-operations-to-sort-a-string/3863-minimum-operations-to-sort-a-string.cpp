class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        bool sorted=true;
        char mini=s[0];
        char maxi=s[0];
        for(int i=1;i<n;i++){
            if(s[i-1]>s[i]){
                sorted=false;
            }
            mini=min(s[i],mini);
            maxi=max(s[i],maxi);
        }

        if(sorted==true){
            return 0;
        }
        if(n==2){
            return -1;
        }
        if(s[0]==mini || s[n-1]==maxi){
            return 1;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]==mini || s[i]==maxi){
                return 2;
            }
        }
        return 3;
    }
};