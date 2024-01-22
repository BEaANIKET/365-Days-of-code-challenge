class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;

        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }

        int ans =0;
        for(auto val : mp1){
            char key = val.first;
            int num = val.second;
            int num2 = mp2[key];
            cout<<"key:"<<key<<" num:"<<num<<" num2:"<<num2<<endl;
            if(mp1[key] > mp2[key]){
                ans+=(mp1[key]-mp2[key]);
            }
        }

        return ans;

    }
};