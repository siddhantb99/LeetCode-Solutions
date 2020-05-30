/*
K Closest Points to Origin
Solution
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        int size = points.size();
        if(size == 0)
            return ans;
        vector<pair<int, vector<int>>> m;
        for(auto a : points){
            m.push_back(make_pair((a[0]* a[0]) + (a[1]* a[1]), a));
        }
        sort(m.begin(), m.end());
        int i = 0;
        while(K){
            ans.push_back(m[i].second);
            i++;
            K--;
        }
        return ans;
    }
};
