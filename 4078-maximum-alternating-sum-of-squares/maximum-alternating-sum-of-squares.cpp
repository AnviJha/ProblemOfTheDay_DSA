class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq;
        int n=nums.size();

        for(int x:nums){
            sq.push_back(x*x);
        }

        sort(sq.begin() ,sq.end());
        
        int index = floor(n/2);
        long long neg = 0;
        long long pos = 0;
        for(int i =0;i<index;i++){
            neg += sq[i];
        }
        for(int i=index ; i<n ;i++){
            pos+=sq[i];
        }
        return pos - neg; 
    }
};