/*
Subarray Sum Equals K
Solution
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size(),ans=0;
        m[nums[0]]=1;
        if(nums[0]==k)
            ans++;
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
            if(m.find(nums[i]-k) != m.end())
                ans += m[nums[i]-k];
            if(nums[i]==k)
                ans++;
            m[nums[i]]++;
        }
        return ans;
    }
};
