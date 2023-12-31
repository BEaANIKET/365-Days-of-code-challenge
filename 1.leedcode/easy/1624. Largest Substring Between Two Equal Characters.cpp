class Solution {
public:

    
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int>mp;
        int ans=-1;
        for(int i=s.length()-1;i>=0;i--){
            if(mp.count(s[i])){
                ans = max(ans,mp[s[i]]-i -1);
            }            
            else{
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};