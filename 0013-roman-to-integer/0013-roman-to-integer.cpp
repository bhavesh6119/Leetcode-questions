class Solution {
public:
    int nums(char val){
        if(val=='I'){
            return 1;
        }else if(val=='V'){
            return 5;
        }else if(val=='X'){
            return 10;
        }else if(val=='L'){
            return 50;
        }else if(val=='C'){
            return 100;
        }else if(val=='D'){
            return 500;
        }else{
            return 1000;
        }
    }
    int romanToInt(string s) {
        int n=s.size();
        int result=0;;
        for(int i=0;i<n-1;i++){
            if(nums(s[i])<nums(s[i+1])){
                result-=nums(s[i]);
            }else{
                result+=nums(s[i]);
            }
        }
        result+=nums(s[n-1]);
        return result;
    }
};