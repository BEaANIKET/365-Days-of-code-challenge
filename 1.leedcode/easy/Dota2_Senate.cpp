class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiant,dire;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }
        if(radiant.size()==0){
            return "Dire";
        }
        if(dire.size()==0){
            return "Radiant";
        }

        while(! radiant.empty() && ! dire.empty()){
            if(radiant.front()<dire.front()){
                dire.pop();
                int r =radiant.front();
                radiant.push(n+r);
                radiant.pop();
            }
            else{
                radiant.pop();
                int p=dire.front();
                dire.push(n+p);
                dire.pop(); 
            }
        }
        return radiant.size()==0?"Dire":"Radiant";
    }
};