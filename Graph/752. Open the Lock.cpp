class Solution {
public:

    void helper(string temp, unordered_set<string>& vis, queue<string>& q ){

        
        for(int i=0; i<4; i++){

            char ch = temp[i];

            char inc = ch == '9' ? '0' : ch+1;
            char dec = ch == '0' ? '9' : ch-1;
            
            temp[i] = inc;
            if(!vis.count(temp)){
                vis.insert(temp);
                q.push(temp);
            }

            temp[i] = dec;
            if(!vis.count(temp)){
                vis.insert(temp);
                q.push(temp);
            }

            temp[i] = ch;
        }

        return ;

    }

    int openLock(vector<string>& deadends, string target) {

        string s = "0000";
        queue<string>q;
        q.push(s);
        unordered_set<string> vis (begin(deadends), end(deadends));

        if(vis.count(s)){
            return -1;
        }

        int lvl = 0;

        while(!q.empty()){

            int n = q.size();

            while(n--){

                string temp = q.front();
                q.pop();

                if(temp == target ){
                    return lvl;
                }

                helper (temp, vis, q);
            }

            lvl++;
        }

        return -1;
    }
};