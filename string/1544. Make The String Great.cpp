class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){

            int t = 0;
            if(!st.empty())
                t = st.top();
            int c = s[i];
            if(abs(t-c) == 32){
                st.pop();
            }
            else{
                st.push(c); 
            }
        }

        string ans;

        while(!st.empty()){
            cout<<"helloo";
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};