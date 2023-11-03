class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>result;
        int i=0;
        int j=1;

        while(i<target.size() && j<=n){

            int num=target[i];
            result.push_back("Push");

            if(num==j){
                i++;
                j++;
            }
            else{
                result.push_back("Pop");
                j++;
            }
        }
        return result;
    }
};