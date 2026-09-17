class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        //sort the trainer 
        sort(trainers.begin() ,trainers.end());
        //sort the players 
        sort(players.begin() , players.end());
        //iterate through i for players and jth for trainers 
        int n =players.size();
        int  m =trainers.size();
        int i=0,j=0;
        int count=0;

        while(i<n && j<m){
            if(players[i] <= trainers[j]){
                count++;
                i++;
                j++;
            }
            else if(players[i]>trainers[j] ){
                j++;
            }else{
                i++;
            }
        }

        return count;
    }
};