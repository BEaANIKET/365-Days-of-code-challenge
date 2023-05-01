//1. solution 
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n =salary.size();
        int j=0;
        double sum=0;
        if(n==3){
         return salary[1];
        }
        else{
        for(int i=1;i<n-1;i++){
            j++;
            sum+=salary[i];
         }
        }
        double avg=sum/j;
        return avg;
    }
};

//2.solution;
//optimize solution;
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n =salary.size();
        int j=n-1;
        int i=0;
        double sum=0;

        if(n==3){
         return salary[1];
        }

        else{
            while(i<j){
                sum=salary[i]+salary[j]+sum;                         
                if((j-i)==2){
                    i++;
                    sum+=salary[i];
                    break;
                }
                else {
                    i++;
                    j--;
                }
              
                
            }
        }
        double avg=(sum-(salary[0]+salary[n-1]))/(n-2);
        return avg;
    }
};