
class Solution {
public:
    bool winnerOfGame(string colors) {
        int al=0;
        int bo=0;
        
        for(int i=1;i<colors.length()-1;i++){
            if('A'==colors[i-1] && 'A'==colors[i+1] && colors[i]== 'A'){
                al++;
            }
            else if('B'==colors[i-1] && 'B'==colors[i+1] && colors[i]== 'B'){
                bo++;
            }
        }
        return al>bo;
    }
};