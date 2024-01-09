class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int leser = 0;
        int device = 0;
        int j=0;
        for(int i=0;i<bank.size();i++){
            string s=bank[i];
            device=0;
            j=0;
            while(j<s.length()){
                if(s[j] == '1'){
                    device++;
                    
                }

                j++;
            }
            if(device!=0){
                leser+=(prev * device);
                prev=device;
            }
        }
        return leser;
    }
};