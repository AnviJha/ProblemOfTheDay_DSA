class Solution {
public:
    string convert(string s, int numRows) {
    
        if(s.size()<=numRows || numRows == 1){
            return s;
        }
        vector<string>rows(numRows);
        int direction = -1;
        int currRow = 0;

        for(char ch :s) {
            rows[currRow]+=ch;
            //change direction if row is zero or last 
            if(currRow == 0  || currRow == (numRows -1) ){
                direction*=-1;
            }
            currRow+=direction;
        }
        //append
        string ans;
        for(auto row :rows){
            ans+=row;
        }

        return ans;
    }
};
/*
Create a string for each row.
Traverse each character and append it to the current row.
Reverse direction when reaching the top or bottom row.
Concatenate all rows to get the answer.
*/