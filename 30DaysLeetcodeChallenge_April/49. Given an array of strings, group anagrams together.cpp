/*
49. Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        unordered_map<string, vector<string>> anagram_groups;
        
        for(string word: strs) {
            string anagram_word = countSort(word);
            anagram_groups[anagram_word].emplace_back(word);
        }
        
        vector<vector<string>> result;
        for(auto it : anagram_groups){
            result.push_back(it.second);
        }
        return result;
    }
    
    string countSort(string str) {
        vector<int> chars(26, 0);
        string result;
        
        for(char c: str)
            chars[c - 'a']++;
        
        for(int freq: chars)
            result += to_string(freq);
        return result;
    }
};
