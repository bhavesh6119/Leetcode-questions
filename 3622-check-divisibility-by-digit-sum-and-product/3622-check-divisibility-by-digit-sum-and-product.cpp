class Solution {
public:
    bool checkDivisibility(int n) {
    //    if(n<=9){
    //     return false;
    //    }
       int number=n;
       int sum=0;
       int product=1;
       while(number){
        int num=number%10;
        sum+=num;
        product*=num;
        number/=10;
       } 
       if(n%(sum+product)==0){
        return true;
       }
       return false;
    }
};