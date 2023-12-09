class Solution {
public:

    bool ismake(string s1 , map<char,int> mp){

        for(int i=0;i<s1.length();i++){
            if(mp[s1[i]] == 0){
                return false;
            }

            mp[s1[i]]--;
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(int i=0;i<chars.length();i++){
            mp[chars[i]]++;
        }

        int ans=0;
        for(auto s : words){
            if(ismake(s,mp)){
                ans+=s.length();
            }
        }

        return ans;
    }
};