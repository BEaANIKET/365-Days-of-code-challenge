class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int sum=0;
        int ans=0;
        sum=arrivalTime+delayedTime;
      if(sum>=24){ 
       while(sum>=24){

        ans= abs(24-sum);
           sum=sum-24;
            }
      }
        else{
      ans=sum;
        }
        return ans;
    }
};