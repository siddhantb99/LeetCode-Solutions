/*
844. Backspace String Compare
Easy

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        int del = 0;
        int i;
        for(i = len1 -1; i > -1; i--){
            if(S[i] == '#'){
                del++;
                S.replace(i, 1, std::string(""));
            }
            else{
                if(del != 0){
                    S.replace(i, 1, std::string(""));
                    del--;
                }
            }
        }
        del = 0;
        for(i = len2 -1; i > -1; i--){
            if(T[i] == '#'){
                del++;
                T.replace(i, 1, std::string(""));
            }
            else{
                if(del != 0){
                    T.replace(i, 1, std::string(""));
                    del--;
                }
            }
        }
        if(S == T)
            return true;
        return false;
        
    }
};
