class Solution {
public:
        bool static comp(vector<int>& box1 ,vector<int>& box2) {
           
            return box1[1] >box2[1];
        }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort according to number of boxes 
        sort(boxTypes.begin() , boxTypes.end() , comp);

        //count total units 
        int totalunits=0;
        int n=boxTypes.size();
        int box=0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]+box <= truckSize ){
                // its unit can be added 
                totalunits += boxTypes[i][0] * boxTypes[i][1];
                box+=boxTypes[i][0];
            }else if(box < truckSize && (truckSize - box) <= boxTypes[i][0]){
                //take fraction of it 
                totalunits += (truckSize-box)*boxTypes[i][1];
                break;
            }else{
                break;
            }
        }
    return totalunits;
    }
};