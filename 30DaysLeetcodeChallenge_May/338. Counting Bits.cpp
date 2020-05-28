/*
Counting Bits
Solution
Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0)
            return ans;
        ans.push_back(1);
        if(num == 1)
            return ans;
        int count = 2;
        ans.push_back(1);
        num++;
        for(int i = 3; i < num; i++){
            ans.push_back(ans[i % count] + 1);
            if(i % count == 0){
                count = count + count;
            }
        }
        return ans;
    }
};
