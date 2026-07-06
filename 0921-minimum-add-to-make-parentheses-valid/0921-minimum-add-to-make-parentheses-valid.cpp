class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.size();i++){//iterating 
            if(s[i]=='('){//if there is left present push it to the stack
                st.push(s[i]);
            }else{//if right appears
                if(st.empty()){//if satck is empty then its not a pair increse the count of left to be added 
                    count++;
                }else{//if left is present pair is valid then pop from stack
                    st.pop();
                }
            }
        }
        return count+st.size();//as there might be some left parenthesis in the stack that needs right one so its the total parenthesis required to make the string valid
    }
};