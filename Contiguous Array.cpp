/*
Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       vector<int>vec;
        if(nums.size()== 0) return 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == 0) vec.push_back(-1);
            else{
                vec.push_back(1);
            }
        }
        int ans = 0;
        unordered_map<int,int>m;
        int sum = vec[0];
        m[sum] = 0;
        for(int i = 1; i < vec.size();i++){
            sum += vec[i];
            if(sum == 0){
                ans = max(ans,i+1);
            }
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }else{
                ans = max(ans,i-m[sum]);
            }
        }
        return ans;
    }
};
