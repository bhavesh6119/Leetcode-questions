class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>small(26,0);//to count the frequency of the characters
        vector<bool>visited(26,0);//to see if the appeared or not 
        int n=s.size();
        for(int i=0;i<n;i++){//first note the frequency
            small[s[i]-'a']++;
        }
        stack<char>st;
        for(int i=0;i<n;i++){
           small[s[i]-'a']--;//reduce the frequency of current element
           if(visited[s[i]-'a']){//if already visited continue
            continue;
           }
           while(!st.empty() && st.top()>s[i] && small[st.top()-'a']>0){//if top is larger than the current then
           //check if its freq is greater than 0
            visited[st.top()-'a']=0;//if yes then make it unvisited
            st.pop();//and pop it
           }
           visited[s[i]-'a']=1;//else make then current visited 
           st.push(s[i]);//push it onto the stack
        }
        string ans="";
        while(!st.empty()){
            char c=st.top();
            ans+=c;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};