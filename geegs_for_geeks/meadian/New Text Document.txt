//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int i=0;
        int j=0;
        int k=0;
        for(auto x:S1)sum1+=x;
        for(auto y:S2)sum2+=y;
        for(auto z:S3)sum3+=z;
        while(i<N1 && j<N2 && k<N3){
            if(sum1==sum2 && sum2==sum3)return sum1;
            if(sum1>sum2 || sum1>sum3){sum1=sum1-S1[i];i++;}
            if(sum2>sum1 || sum2>sum3){sum2=sum2-S2[j];j++;}
            if(sum3>sum1 || sum3>sum2){sum3=sum3-S3[k];k++;}
        }
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends