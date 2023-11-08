class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int H=abs(sx-fx);
        int V=abs(sy-fy);

        int minTime=max(H,V);
        if(H==0 && V==0 && t==1){
            return false;
        }

        if(t>=minTime){
            return true;
        }

        else{
            return false;
        }

    }
};