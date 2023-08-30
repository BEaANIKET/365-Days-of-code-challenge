class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val=0;
        for(auto str:operations){
            if(str=="--X"){
                --val;
            }
            else if(str=="X++"){
                val++;
            }
            else if(str=="X--"){
                val--;
            }
            else if(str=="++X"){
                ++val;
            }
        }
        return val;
    }
};