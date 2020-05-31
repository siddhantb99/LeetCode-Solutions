/*
Edit Distance
Solution
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> ans(len2 + 1, vector<int>(len1 + 1));
        int i, j;
        for(i = 0; i <= len1; i++){
            ans[0][i] = i;
        }
        
        for(i = 0; i <= len2; i++){
            ans[i][0] = i;
        }
        
        for(i = 1; i <= len1; i++){
            for(j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]){
                    ans[j][i] = ans[j - 1][i - 1];
                    continue;
                }
                else{
                    ans[j][i] = min({ans[j - 1][i - 1], ans[j][i - 1], ans[j - 1][i]}) + 1;
                }
                    
            }
        }
        return ans[len2][len1];
    }
};
