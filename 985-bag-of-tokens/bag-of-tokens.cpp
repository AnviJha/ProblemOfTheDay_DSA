class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort( tokens.begin() , tokens.end() );
        int n=tokens.size();
        if (n==0) return 0;
        if(tokens[0]>power) return 0;

        int i=0;
        int j=n-1;

        int score=0;
        int currpow=power;

        while(i<j) {
            
            if(tokens[i] <= currpow ){
                //reduce the power and add the score 
                currpow-=tokens[i];
                score++;
                i++;
            }else{
                //try to reduce the score and increase the power , reduce the point for high power 
                currpow+=tokens[j];
                score--;
                j--;

            }
        }
            if(tokens[i] <= currpow){
                //then only add the score 
                currpow-=tokens[j];
                score++;
            }
        
        return score ;
    }
};