class Solution {
public:
    int largestVariance(string s) {
       vector<int>count(26,0);
       for(char ch : s){
           count[ch-'a']++;
       }

       int result=0;
       for(char first='a';first<='z';++first){
           for(char second='a';second<='z';++second){
               if(count[first-'a']==0 || count[second-'a']==0){
                   continue;
               }


               int firstcount=0;
               int secondcount=0;
               bool lastsecond=false;

               for(const char &ch : s){
                   if(ch==first)++firstcount;
                   if(ch==second)++secondcount;

                   if(secondcount>0){
                       result = max(result,firstcount-secondcount);
                   }
                   else{
                       if(lastsecond){
                           result=max(result,firstcount-1);
                       }
                   }

                   if(secondcount>firstcount){
                       secondcount=0;
                       firstcount=0;
                       lastsecond=true;
                   }
               }
           }
       }
       return result;
    }
};