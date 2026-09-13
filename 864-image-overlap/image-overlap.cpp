class Solution {
public:

   int count_overlap(vector<vector<int>>& img1, vector<vector<int>>& img2 ,int r,int c) {
        
        int n=img1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                //overlap
                if(i+r <0 || i+r>n-1 || j+c <0 ||j+c >n-1){
                    continue;
                }
                if(img1[i][j] ==1 && img2[i+r][j+c]==1 ){
                    count++;
                }
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        //left right overlapping .column offset 
        int n=img1.size();
        int count=0;
        for( int rowoffset = -n+1 ; rowoffset<n ; rowoffset++ ) {
            for(int coloffset = -n+1 ; coloffset<n ;coloffset++ ){
               count =max(count ,count_overlap(img1 ,img2 ,rowoffset, coloffset) );
            }
        }
        return count;
    }
};