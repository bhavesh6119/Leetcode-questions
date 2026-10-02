class Solution {
public:
    void generate(vector<string>& ans,string& str,int index,int open,int close){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open>0){
            str[index]='(';
            generate(ans,str,index+1,open-1,close);
        }
        if(close>open){
            str[index]=')';
            generate(ans,str,index+1,open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str(2*n,' ');
        generate(ans,str,0,n,n);

        return ans;
    }
};