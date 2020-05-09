/*
Valid Perfect Square
Solution
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(double i = 1; i * i <= num; i++) { 
            if((num % (int)i == 0) && (num / i == i)) { 
                return true; 
            } 
        } 
    return false; 
    }
};
