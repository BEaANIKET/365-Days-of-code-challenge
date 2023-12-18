class Solution {
public:
    string largestGoodInteger(string num) {
        
        int curr;
        int n=num.length();
        int prev=INT_MIN;
        char ans='A';

        for(int i=0;i<n-2;i++){
            
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                curr=num[i]-'0';
                cout<<curr;
                if(prev<curr){
                   prev=curr;
                   ans=curr + '0';
                }
               
            }
        }
        if(ans=='A'){
            return "";
        }
        string result;
        result.push_back(ans);
        result.push_back(ans);
        result.push_back(ans);
        return result;
        
    }
};