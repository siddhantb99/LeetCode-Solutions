/*
Jump Game
Solution
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int i;
        int steps = 0;
        for(i = size - 2; i > -1; i--){
            steps--;
            if(nums[i] + steps >= 0)
                steps = 0;
        }
        if(steps < 0)
            return false;
        return true;
    }
};
