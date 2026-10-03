class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int length_maxi=0;

        for(int i=0;i<s.length();i++){
            //base index set whenever stack is empty 
            if(s[i]=='(') st.push(i);
            else{
                 st.pop();
                if(st.empty()){
                    //set that index as left index
                    st.push(i);
                }else{
                    length_maxi=max(length_maxi, i-st.top());
                }
            }
        }
        return length_maxi;
    }
};