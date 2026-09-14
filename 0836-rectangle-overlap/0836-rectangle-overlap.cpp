class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // float art1= (rec1[2]-rec1[0])*(rec1[3]-rec1[1]);
        // float art2= (rec2[2]-rec2[0])*(rec2[3]-rec2[1]);
        // if((art2-art1)>0 || (art1-art2)>0 ||){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        int x1=rec1[0];
        int x2=rec1[2];
        int x3=rec2[0];
        int x4=rec2[2];
        int y1=rec1[1];
        int y2=rec1[3];
        int y3=rec2[1];
        int y4=rec2[3];
        if((x4>x1&&x2>x3)&&(y4>y1&&y2>y3)){
            return true;
        }
        else{
            return false;
        }
    }
};