class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i=0;i<s.size();i++){//iterating on the string s
            if(s[i]!='#'){
                st.push(s[i]);//pushing the values if tehy are not hash
            }else{
                if(!st.empty()){//if # is there check if stack is empty then return 0
                    st.pop();
                }
            }
        }
        string str1(st.size(),' ');//make a string to store the values of stack
        int i=st.size()-1;
        while(!st.empty()){
            str1[i]=st.top();
            i--;
            st.pop();
        }
        //same for the other t string 
        for(int i=0;i<t.size();i++){
            if(t[i]!='#'){
                st.push(t[i]);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string str2(st.size(),' ');
        int j=st.size()-1;
        while(!st.empty()){
            str2[j]=st.top();
            j--;
            st.pop();
        }
        return str1==str2;//return true only if both the resultant strings are matched after omitting the letters before #
    }
};