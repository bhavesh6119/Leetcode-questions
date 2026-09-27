class Solution {
public:
    string reverseParentheses(string s) {
       int n= s.size();
       vector<int> link(n);
       stack<int>st;
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if (s[i]==')'){
            link[i]=st.top();
            st.pop();
            link[link[i]]=i;
        }
       }
       string ans="";
       for(int i=0,dir=1;i<n;i+=dir){
        if(s[i]>='a'){
            ans+=s[i];
        }else{
            i=link[i];
            dir=-dir;
        }
       }
       return ans;
    }
};