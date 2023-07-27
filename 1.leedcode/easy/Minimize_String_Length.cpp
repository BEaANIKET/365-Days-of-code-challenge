class Solution {
public:
    int minimizedStringLength(string s) {
        set<int>ss;
        for(int i=0;i<s.length();i++){
            if(ss.find(s[i])==ss.end()){
                    ss.insert(s[i]);
            }
        }
        return ss.size();
        
    }
};