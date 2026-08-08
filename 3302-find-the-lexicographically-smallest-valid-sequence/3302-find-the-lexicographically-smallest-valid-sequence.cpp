class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>matchedchar(n,0);
        int matchedcount=0;
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                matchedcount++;
                j--;
            }
            matchedchar[i]=matchedcount;
            i--;
        }
        bool used=false;
        vector<int>ans;
        i=0;
        j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(used==false && i+1<n && matchedchar[i+1]>=m-j-1){
                ans.push_back(i);
                j++;
                used=true;
            }
            i++;
        }
        if(j==m){
            return ans;
        }
        return {};
    }
};