
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
        int top=0;
        int down=n-1;
        int left=0;
        int right=m-1;
        int direaction=0;
        int count=0;
        while(top<=down && left<=right)
        {
            if(direaction==0)
            {
                for(int i=left;i<=right;i++)
                {
                    count=count+1;
                    if(count==k)
                    {
                       return a[top][i];
                    }
                }
                top=top+1;
                direaction=direaction+1;
                
            }
            else if(direaction==1)
            {
                for(int i=top;i<=down;i++)
                {
                    count=count+1;
                    if(count==k)
                    {
                       return a[i][right];
                    }
                    
                }
                right=right-1;
                direaction=direaction+1;
            }
            else if(direaction==2)
            {
                for(int i=right;i>=left;i--)
                {
                    count=count+1;
                    if(count==k)
                    {
                       return a[down][i];
                    }
                }
                down=down-1;
                direaction=direaction+1;
            }
            else if(direaction==3)
            {
                for(int i=down;i>=top;i--)
                {
                    count=count+1;
                    if(count==k)
                    {
                      return a[i][left];
                    }
                }
                left=left+1;
                direaction=direaction+1;
            }
            direaction=(direaction)%4;
        }
        
        
    }
};




//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends