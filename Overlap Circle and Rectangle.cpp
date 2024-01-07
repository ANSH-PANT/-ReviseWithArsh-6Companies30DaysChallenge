class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       int xm = min(max(xCenter, x1), x2),
		ym = min(max(yCenter, y1), y2);
	return (xCenter-xm)*(xCenter-xm)+(yCenter-ym)*(yCenter-ym)<=radius*radius; 
    }
};
