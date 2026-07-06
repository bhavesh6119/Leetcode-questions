class Solution {
public:
    int minAddToMakeValid(string s) {
        // //TC=O(n) and SC=O(n) due to stack
        // stack<char>st;
        // int count=0;
        // for(int i=0;i<s.size();i++){//iterating 
        //     if(s[i]=='('){//if there is left present push it to the stack
        //         st.push(s[i]);
        //     }else{//if right appears
        //         if(st.empty()){//if satck is empty then its not a pair increse the count of left to be added 
        //             count++;
        //         }else{//if left is present pair is valid then pop from stack
        //             st.pop();
        //         }
        //     }
        // }
        // return count+st.size();//as there might be some left parenthesis in the stack that needs right one so its the total parenthesis required to make the string valid
        

        //optimised approachh 
        //SC=O(1);
        int left=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;//here we are just maintaining the count of left parenthesis as pushing onto the stack takes space
            }else{
                if(left==0){//if it is 0 that means stack is empty
                    count++;//increase the count of left required
                }else{
                    left--;//otherwise pop it out or reduce it if there is a pair
                }
            }
        }
        return left+count;//total required parenthesis
    }
};