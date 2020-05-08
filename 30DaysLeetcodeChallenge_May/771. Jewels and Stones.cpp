/*
 Jewels and Stones
Solution
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int size = J.length();
        int size1 = S.length();
        int i,j;
        int ans = 0;
        for(i = 0; i < size; i++){
            for(j = 0; j < size1; j++){
                if(J[i] == S[j])
                    ans++;
            }
        }
        return ans;
    }
};
