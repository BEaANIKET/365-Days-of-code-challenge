class Solution {
public:

    bool possible(vector<int>& dist, double hour,int speed){

        int n=dist.size();

        double min_time=0.0;

        for(int i=0;i<n-1;i++){
            
            double time=(double)dist[i]/(double)speed;
            min_time+=ceil(time);
            
        }

        min_time+=(double)dist[n-1]/(double)speed;

        if(min_time<=hour){
            return true;
        }

        else{
            return false;
        }

    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start=1;
        int end=1e7;

        int min_speed=-1;
        while(start<=end){

            int mid_speed=start+(end-start)/2;

            if(possible(dist,hour,mid_speed)){
                min_speed=mid_speed;
                end=mid_speed-1;
            }
            else{
                start=mid_speed+1;
            }
        }
        return min_speed;
    }
};