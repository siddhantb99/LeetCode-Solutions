/*
1401. Circle and Rectangle Overlapping
Medium

Given a circle represented as (radius, x_center, y_center) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return True if the circle and rectangle are overlapped otherwise return False.

In other words, check if there are any point (xi, yi) such that belongs to the circle and the rectangle at the same time.

*/
class Solution {
public:
    int dist(int a1, int a2, int x){
    if(x < a1)
        return abs(a1-x);
    if(x > a2) 
        return abs(x-a2);
    return 0;
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int a = dist(x1, x2, x_center);
        int b=dist(y1, y2, y_center);
        return a * a + b * b <= radius * radius;
    }
};
