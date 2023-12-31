class Solution {
public:
    int minOperations(string s) {

        int num1 = 0;
        int num2 = 0;
        int b1=0;
        int b2=1;

        for(int i=0;i<s.length();i++){
            if(s[i]-'0' != b1){
                num1++;
            }
            if(s[i]-'0'!=b2){
                num2++;
            }
            b1 = (b1==0) ? 1 : 0;
            b2 = (b2==0) ? 1 : 0;
        }

        return min(num1,num2);
        
    }
};