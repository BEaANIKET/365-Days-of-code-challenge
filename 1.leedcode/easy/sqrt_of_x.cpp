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


class Solution {
public:
    int mySqrt(int x) {
        long long int start=1;
        long long int end=x;
        int ans=-1;
        long long int mid;

        if(x<=0)
            return 0;
            
        while(start<=end){
             mid=start + (end-start)/2;

            if(mid*mid==x){
                return mid;
            }

            else if(mid*mid>x){
                end=mid-1;
            }
            else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};