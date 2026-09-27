class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string curr="";
        for(char ch:s){
            if(ch=='(') {
                //then curr push into stack 
                st.push(curr);
                curr = "";//new current 
            }
            else if(ch==')'){
                reverse(curr.begin(),curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else{
                curr+=ch;

            }
        }
        return curr;
    }
};