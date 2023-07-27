// by swaping 

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};


// by recursion;
class Solution {
public:

    void solve(vector<char>& s,int start,int end){
        if(start>=end)
               return ;

            int temp=s[end];
            s[end]=s[start];
            s[start]=temp;
            start++;
            end--;
            solve(s,start,end);
    }  
    void reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
    }
};