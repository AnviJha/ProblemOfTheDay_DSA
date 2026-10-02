class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string>ans;
        gp(n,0,0,temp,ans);
        return ans;
    }
    void gp(int n,int left,int right,string &temp,vector<string>&ans){
        if(left+right==2*n){
            ans.push_back(temp);
            return ;
        }
        if(left<n){
            //add left
            temp.push_back('(');
        gp(n,left+1,right,temp,ans);
        temp.pop_back();
        } 
        if(right<left){
             //add right
             temp.push_back(')');
        gp(n,left,right+1,temp,ans);
        temp.pop_back();
        }
       
    }
};