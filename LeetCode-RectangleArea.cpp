class Solution {
public:
    bool valueInRange(int x, int min, int max) {
        return x>=min && x<=max;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x11 = A;
        int x12 = C;
        int x21 = E;
        int x22 = G;
        int y11 = B;
        int y12 = D;
        int y21 = F;
        int y22 = H;
        int deltax = 0;
        int deltay = 0;
        //x_overlap
        if(valueInRange(x11,x21,x22) || valueInRange(x21,x11,x12)) {
            vector<int> x = {x11,x12, x21,x22};
            sort(x.begin(),x.end());
            deltax = x[2]-x[1];
            
        }
        //y_overlap
        if(valueInRange(y11,y21,y22) || valueInRange(y21,y11,y12)) {
            vector<int> y = {y11,y12, y21,y22};
            sort(y.begin(),y.end());
            deltay = y[2]-y[1];
        }
        return (x12-x11)*(y12-y11)+(x22-x21)*(y22-y21)-deltax*deltay;
    }
};
