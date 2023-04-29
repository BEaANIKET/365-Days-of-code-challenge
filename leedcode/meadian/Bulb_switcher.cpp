#include<math.h>
class Solution {
public:
    int bulbSwitch(int n) {
      double num=sqrt(n);
      int output =floor(num);
      return output;  
    }
};