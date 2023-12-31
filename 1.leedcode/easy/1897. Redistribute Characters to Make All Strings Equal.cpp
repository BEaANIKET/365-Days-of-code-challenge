class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<s.length();j++){
                mp[s[j]]++;
            }
        }

        for(auto val : mp){
            if(val.second % n != 0){
                return false;
            }
        }
        return true;
    }
};