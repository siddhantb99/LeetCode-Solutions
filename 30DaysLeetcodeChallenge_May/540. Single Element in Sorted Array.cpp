/*
Single Element in a Sorted Array
Solution
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        int ans;
        while(low < high){
            mid = (high - low) / 2 + low;
            //cout<< low<<" "<< mid<<" "<<high<<endl;
            if(mid % 2  == 0){
                if(nums[mid] == nums[mid + 1])
                    low = mid + 2;
                else
                    high = mid;
            }
            else{
                if(nums[mid] == nums[mid + 1]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return nums[low];
    }
};
