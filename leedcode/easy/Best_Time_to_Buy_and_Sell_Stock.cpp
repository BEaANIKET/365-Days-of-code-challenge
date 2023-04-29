class Solution {
public:
  int maxProfit(vector<int>& prices) {
 int mxprofit=0;
 int minval=INT_MAX;
 
 for(int i=1;i<prices.size();i++){
     minval=min(minval,prices[i-1]);
     mxprofit=max(mxprofit,prices[i]-minval);
 }
 return mxprofit;
    }
};