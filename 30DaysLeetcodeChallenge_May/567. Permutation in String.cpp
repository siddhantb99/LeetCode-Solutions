/*
Permutation in String
Solution
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len2 < len1)
           return false;
        vector<int> pv(26,0), sv(26,0), res;
        int i;
        for(i = 0; i < len1; ++i){
            ++pv[s1[i]-'a'];
        }
        for(i = 0; i < len1; ++i){
            ++sv[s2[i]-'a'];
        }
        if(pv == sv)
           return true;

        for(i = len1; i < len2; ++i){
            ++sv[s2[i]-'a'];
            
            --sv[s2[i - len1]-'a']; 

            if(pv == sv)
                return true;
        }
        return false;
    }
};
