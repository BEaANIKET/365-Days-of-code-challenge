class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        map<string, bool> mp;
        string ans = "" ;
        for(int i=0; i<d.size(); i++){
            mp[d[i]] = true;
        }

        for(int i=0; i<s.length(); i++){
            bool flag = false;
            string temp = "";
            while( i < s.length() && s[i] != ' '){
                temp += s[i];
                i++;
            }

            string test = "";

            for(int j=0; j<temp.length(); j++){
                test += temp[j];
                if(mp[test]){
                    ans += test;
                    flag = true;
                    ans += ' ';
                    break;
                }
            }
            if( !flag ){
                ans += temp;
                ans += ' ';
            }
        }

        if(ans[ans.size()-1] == ' '){
            ans.pop_back()
;        }

        return ans;
    }
};