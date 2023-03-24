class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int sum=0,carry=0;
        string ans;
        while(i>=0 || j>=0 || carry){
         sum=carry;
         if(i>=0){
           sum+=a[i]-'0';
           i--;
         }
         if(j>=0){
           sum+=b[j]-'0';
           j--;
         }
         if(sum>1){
           ans+=to_string(sum%2);
           carry=1;

         }
         else{
           ans+=to_string(sum);
           carry=0;

         }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};