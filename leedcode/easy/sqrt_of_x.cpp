class Solution {
public:
    int mySqrt(int x) {
  long long int high=x;
    long long int low=1;
    long long int ans=-1;
    if (x<=0){
      return 0;
    }
    while(low<=high){
    long long int  mid =(low+high)/2;
      long long int  sqr=mid*mid;
      if(sqr==x){return mid;}
      else if(sqr<x){
      
        ans=mid;
        low=mid+1;
      }
      else{
       high=mid-1;
      }
    } 
    return ans;   
    }
};