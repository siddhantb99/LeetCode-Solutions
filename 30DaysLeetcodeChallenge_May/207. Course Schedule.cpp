/*
Course Schedule
Solution
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>degree(numCourses),v;
        for(auto x:prerequisites) {
            mp[x[1]].push_back(x[0]);
            degree[x[0]]++;
        }
        for(int i=0 ; i<numCourses ; i++) 
            if(degree[i]==0) 
                v.push_back(i);
        for(int i=0 ; i<v.size() ; i++){
            for(auto y:mp[v[i]]){
                degree[y]--;
                if(degree[y]==0) v.push_back(y);
            }
        }
        return v.size() == numCourses;
    }
};
