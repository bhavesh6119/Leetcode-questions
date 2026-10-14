class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }
        string ans="";
        int nines=sum/9;
        for(int i=0;i<nines;i++){
            ans+='9';
        }
        int remainder=sum%9;
        if(remainder>0){
            ans+=(remainder+'0');
        }
        int zeroes=num-ans.size();
        for(int i=0;i<zeroes;i++){
            ans+='0';
        }

        return ans;
    }
};