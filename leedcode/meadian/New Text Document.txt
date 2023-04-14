
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     stack<int>s;
     for(int i=0,j=0;i<pushed.size();i++){
       s.push(pushed[i]);
       while(!s.empty() && s.top()==popped[j]){
         s.pop();
         j++;
       }
     }
     return s.empty();
    }

//Other solution
/*
stack<int>s;
int i=0;int j=0;
for(int x :pushed){
  pushed[i]=x;
  while(x>0 && pushed[i-1]==popped[j]){
    --i;
    ++j;
  }
}
return i==0;
*/
};

