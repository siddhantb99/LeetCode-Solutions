/*
Uncrossed Lines
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int size1 = A.size();
        int size2 = B.size();
        if(!size1 || !size2)
            return 0;
        vector<vector<int>> ans(size1 + 1, vector<int>(size2 + 1,0));
        int i, j;
        for(i = 1; i < size1 + 1; i++){
            for(j = 1; j < size2 + 1; j++){
                if(A[i - 1] == B[j - 1]){
                    ans[i][j] = 1 + ans[i - 1][j - 1];
                }
                else{
                    ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                }
            }
        }
        return ans[size1][size2];
    }
};
