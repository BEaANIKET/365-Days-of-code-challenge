class Solution {
public:

    bool cheak(vector<int>& nums,int idx1,int idx2){
        vector<int>temp;
        for(int i=idx1;i<=idx2;i++){
            temp.push_back(nums[i]);
        }

        sort(temp.begin(),temp.end());

        if(temp.size()>=2){
            int diff=temp[1]-temp[0];
            for(int i=0;i<temp.size()-1;i++){
                int d=temp[i+1]-temp[i];
                if(d!=diff){
                    return false;
                }
            }

            return true;
        }
        return false;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>result;
        for(int i=0;i<l.size();i++){
            int idx1=l[i];
            int idx2=r[i];
            if(cheak(nums,idx1,idx2)){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }        

        return result;
    }
};