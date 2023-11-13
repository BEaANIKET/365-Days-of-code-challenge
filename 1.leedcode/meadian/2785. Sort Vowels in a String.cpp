class Solution {
public:
     
     bool isVowel(char ch){
         ch=tolower(ch);

         if(ch=='a' || ch=='i' || ch=='e' || ch=='o' || ch=='u'){
             return true;
         }
         return false;
     }
    string sortVowels(string s) {
        
        map<char , int >mp;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                mp[s[i]]++;
            }
        }

        string temp ="AEIOUaeiou";
        int j =0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){

                while(mp[temp[j]] == 0){
                    j++;
                }

                s[i]=temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
    }
};