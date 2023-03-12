//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
        int sum=0,start=0,flag=0;
       for(int i=0;i<n;i++){
          sum=sum+arr[i];
          if(s>=1){
         while (sum>s){
             sum=sum-arr[start];
             start++;
         }
         if (sum==s){
             cout<<start+1<<" "<<i+1;
             flag=1;
         break;
         }
       
       }
           
       }
         if (flag==0){
             cout<<-1;
  
         }
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends