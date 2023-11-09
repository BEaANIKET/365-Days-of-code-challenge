class Solution {
public:
    #define mod 1000000007
    int countHomogenous(string s) {

        int ans=0;
        int p=0;
        int c=0;
       while(p<s.length() && c<s.length()){
            if(s[p]==s[c]){
                int len=(c+1)-p;
                ans=(ans+len)%mod;
                c++;
            }
            else{
                p=c;
            }
        }
        return ans;
    }
};