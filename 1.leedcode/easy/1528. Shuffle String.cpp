class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str(s.length(),'X');
        
        for(int i=0;i<indices.size();i++){
            str[indices[i]]=s[i];
        }

        return str;
        
    }
};