class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();

    int ans=0;
    vector<int>left_max(n,0);
    vector<int>right_max(n,0);
    int maxi=0;
    int mini=0;
    //filled the prefix max and suffix max 
    for(int i=1 ;i<n;i++){
        maxi = max(height[i-1],maxi);
        left_max[i]=maxi;

        mini =max(height[n - i],mini);
        right_max[n-i -1] = mini;

    }

    for(int i=0;i<n;i++){
        int water =min(left_max[i] ,right_max[i]) -height[i];
        if(water>0){
            ans+=water;
        }
    }
    return ans;
    }
};