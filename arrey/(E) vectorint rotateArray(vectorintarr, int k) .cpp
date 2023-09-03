vector<int> rotateArray(vector<int>arr, int k) {
    int n=arr.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        if(i-k>=0){
            ans[i-k]=arr[i];
        }
        else {
            ans[(i+n)-k]=arr[i];
        }
    }

    return ans;
}
