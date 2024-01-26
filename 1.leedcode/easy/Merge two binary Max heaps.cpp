
/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}


*/
class Solution{
    public:
    
    void heapify(vector<int>&ans , int n,int i){
        
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if( left < n && ans[largest] < ans[left]){
            largest = left;
        }
         
        if( right < n && ans[largest] < ans[right]){
            largest = right;
        }
        
        if(largest!=i){
            swap(ans[i],ans[largest]);
            heapify(ans,n,largest);
        }
        
        return ;
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        for(auto i : a ){
            ans.push_back(i);
        }
        for(auto i : b){
            ans.push_back(i);
        }
        
        n = ans.size();
        
        for(int i=n/2;i>=0;i--){
            heapify(ans,n,i);
        }
        
        return ans;
    }