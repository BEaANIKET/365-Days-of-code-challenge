class Solution {
public:
int res=0;

void solve(TreeNode * node,bool goleft,int currpathlen){
    if(!node)
    return ;

     res=max(res,currpathlen);

    if(goleft){
        solve(node->left,false,currpathlen+1);
        solve(node->right,true,1);

    }
    else{
        solve(node->right,true,currpathlen+1);
        solve(node->left,false,1);
    }

}
    int longestZigZag(TreeNode* root) {
      solve(root,true,0);
      solve(root,false,0);
      return res;  
    }
};