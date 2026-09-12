class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        int n=wordList.size();

        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                char original=s[i];
                for(char c='a' ;c<='z' ;c++){
                    s[i]=c;
                    if(st.find(s) != st.end()){
                        if(endWord==s){
                            return step+1;
                        }
                        st.erase(s);
                        q.push({s,step+1});
                    }
                }
                s[i]=original;
            }
        }
        return 0;
    }
};