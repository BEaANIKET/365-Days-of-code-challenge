#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    int prev=arr[n-1];
    arr[n-1]=arr[0];

    for(int i=n-2;i>=0;i--){
        int curr=arr[i];
        arr[i]=prev;
        prev=curr;
        
    }
    return arr;
}
