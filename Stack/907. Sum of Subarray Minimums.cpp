class Solution {
public:
    #define MOD 1000000007;

    vector<int> getNSL(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }

                ans[i] = st.empty() ? -1 : st.top();
            }


            st.push(i);
        }

        return ans;
    }

     vector<int> getRSL(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i] = n;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                ans[i] = st.empty() ? n : st.top();
            }


            st.push(i);
        }

        return ans;
    }
    

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSL = getNSL(arr);
        vector<int> RSL = getRSL(arr);

        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            long long ls = i - NSL[i];
            long long rs = RSL[i] - i;

            long long total = ls*rs;
            long long totalway = arr[i] * (total);
            ans = (ans + totalway)%MOD;

        }

        return ans;
    }
};