class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0){
          return 0;
        }
    int i=0;
    while(i<s.size() && s[i]==' '){
      i++;
    }  

    s=s.substr(i);
     int min=INT_MIN;
    int max =INT_MAX;
    int sign=+1;
    long long ans=0;
    if(s[0]=='-'){sign =-1;}
    i=(s[0]=='+' || s[0]=='-')?1:0;
    while(i<s.length()){
      if(s[0]==' ' || !isdigit(s[i])){break;}
      ans=ans*10 + s[i]-'0';
      if(sign==-1 && -1*ans<=min){return min;}
      if(sign==+1 && ans>=max){return max;}
      i++;
    }
return (int)(sign*ans);
    }
};