/*
 Interval List Intersections
Solution
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int size1 = A.size();
        int size2 = B.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < size1 && j < size2){
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if(lo <= hi){
                vector<int> temp;
                temp.push_back(lo);
                temp.push_back(hi);
                ans.push_back(temp);
            }
            if(A[i][1] > B[j][1])
                j++;
            else
                i++;
        }
        return ans;
    }
};
