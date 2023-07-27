class Solution {
public:
int output=0;
   void solve(int num){
       int sum=0;
        while(num>0){
            int rem=num%10;
            sum=sum+rem;
            num=num/10;
        }
        if(sum>9){
            solve(sum);
        }
        else{
            output = sum;
            return;
        }
    }
    int addDigits(int num) {
     solve(num);
     return output;
    }
};