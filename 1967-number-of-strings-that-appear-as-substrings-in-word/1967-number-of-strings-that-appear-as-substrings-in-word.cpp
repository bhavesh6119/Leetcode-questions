class Solution {
public:
    void LPSfind(vector<int>&LPS,string n){
        int first=0;
        int second=1;
        while(second<n.size()){
            if(n[first]==n[second]){
                LPS[second]=first+1;
                second++;
                first++;
            }else{
                if(first==0){
                    LPS[second]=0;
                    second++;
                }else{
                    first=LPS[first-1];
                }
            }
        }
    }
    bool KMP_find(string &pattern,string &word){
        vector<int>LPS(pattern.size(),0);
        int first=0;
        int second=0;
        LPSfind(LPS,pattern);
        while(second<word.size() && first<pattern.size()){
            if(pattern[first]==word[second]){
                first++;
                second++;
            }else{
                if(first==0){
                    second++;
                }else{
                    first=LPS[first-1];
                }
            }
        }
        if(first==pattern.size()){
            return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=KMP_find(patterns[i],word);
        }
        return count;
    }
};