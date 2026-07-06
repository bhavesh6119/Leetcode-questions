class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);//if any open parenthesis push it to the stack
            }else{
                if(st.empty()){//if empty retrun false
                    return 0;
                }else if(s[i]==')'){//if this is the parenthesis
                    if(st.top()!='('){//check corresponding parenthesis on top of the stack
                        return 0;
                    }else{
                        st.pop();//otherwise pop if matched 
                    }
                    //same for others also
                }else if(s[i]=='}'){
                    if(st.top()!='{'){
                        return 0;
                    }else{
                        st.pop();
                    }
                }else{
                    if(st.top()!='['){
                        return 0;
                    }else{
                        st.pop();
                    }
                }
            }
        }
        return st.empty();//if all goes well all pairs atre valid then return true
    }
};