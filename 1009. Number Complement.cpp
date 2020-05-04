/*
Number Complement
Solution
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:

Input: 5
Output: 2
*/
class Solution {
public:
    int findComplement(int num) {
        int c = 1;
        while (c < num) 
            c = (c << 1) + 1;
        return num ^ c;
    }
};
