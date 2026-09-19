class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // nearest x 
        int xnear,ynear;
        if(xCenter <x1){
            xnear=x1;
        }else if(xCenter >x2){
            xnear=x2;
        }else{
            xnear=xCenter;
        }
        // nearest y
        if(yCenter <y1){
            ynear=y1;
        }else if(yCenter >y2){
            ynear=y2;
        }else{
            ynear=yCenter;
        }

        //  the distance from this point to the center of the circle, check if this is less than or equal to the radius.
    int dist=sqrt((xnear - xCenter)*(xnear - xCenter) + (ynear - yCenter)*(ynear - yCenter));

    return dist<=radius;
    }
};