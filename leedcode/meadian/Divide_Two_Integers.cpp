class Solution {
public:
    int divide(int dividend, int divisor) {
      if(dividend==INT_MIN && divisor==-1)return INT_MAX;
      if(dividend==INT_MIN && divisor==1)return INT_MIN;
      long long dd=abs(dividend);
      long long dv=abs(divisor);
      int count;
      int ans=0;
      int res=0;
      while(dv<=dd){
        int sum=dv;
        count=1;
        while(sum<dd-sum){
            sum+=sum;
            count+=count;           
        }
        res+=count;
        dd=dd-sum;


      }
    if(dividend<0 && divisor>=0){
        return -res;
    }
    if(dividend>=0 && divisor<0){
        return -res;
    }
    
    return res;
    }
};