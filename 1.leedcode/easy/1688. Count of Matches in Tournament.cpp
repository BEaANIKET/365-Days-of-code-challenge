class Solution {
public:
    int numberOfMatches(int n) {
        int round=0;
        while(n>1){
           round += n/2;

           if(n%2 ==0){
               n=n/2;
           }
           else{
               n=(n/2)+1;
           }
        }
        return round;
    }
};