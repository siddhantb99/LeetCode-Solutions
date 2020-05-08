/*
Leftmost Column with at Least a One
Solution
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
*/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int ans = INT_MAX;
        vector<int> dimen = binaryMatrix.dimensions();
        int i;
        int j = dimen[1] - 1;
        int temp;
        for(i = 0; i < dimen[0]; i++){
            //cout<<binaryMatrix.get(i, j)<<endl;
            if(binaryMatrix.get(i, j) == 0)
                continue;
            else{
                temp = bins(i, j, binaryMatrix);
                if(temp < ans && temp > -1){
                    ans = temp;
                    j = ans;
                }
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
    
    int bins(int i, int j, BinaryMatrix &binaryMatrix){
        int low = 0;
        int high = j;
        int mid;
        int ans = INT_MAX;
        while(low <= high){
            mid = low + (high - low) / 2;
           // cout<<mid;
            if(binaryMatrix.get(i, mid) == 1){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};


