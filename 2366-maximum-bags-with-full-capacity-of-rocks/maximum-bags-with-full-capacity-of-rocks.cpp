class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //jiski capacity kum hai uski full hone mai time nahi lagega 
        vector<int>bag;
        int n=rocks.size();
        // That is the number of additional rocks needed to make the bag full.
        for(int i=0;i<n;i++) {
            bag.push_back(capacity[i] - rocks[i]);
        }
        sort(bag.begin() , bag.end() );

            int count=0;

       
        for (int x : bag) {

            if (x <= additionalRocks) {
                additionalRocks -= x;
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }
};