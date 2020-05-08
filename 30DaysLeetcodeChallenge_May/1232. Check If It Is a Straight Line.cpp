/*
Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if(size == 2)
            return true;
        double slope = (double) (coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0]);
        for(int i = 1; i < size - 1; i++){
            double v = (double) (coordinates[i + 1][1] - coordinates[i][1])/(coordinates[i + 1][0] - coordinates[i][0]);
            if(v == slope)
                continue;
            else
                return false;
        }
        return true;
    }
};
