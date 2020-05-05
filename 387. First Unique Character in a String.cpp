/*
First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int hasharray[26] = {0};
        int i;
        int size = s.length();
        for(i = 0; i < size; i++){
            hasharray[s[i]%97]++; 
        }
        for(i = 0; i < size; i++){
            if(hasharray[s[i]%97] == 1)
                return i;
        }
        return -1;
    }
};
