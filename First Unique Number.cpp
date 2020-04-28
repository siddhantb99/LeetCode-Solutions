/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
*/

class FirstUnique {
public:
    list<int> unique;
    unordered_map<int, list<int>::iterator> pos;

    FirstUnique(vector<int>& nums) {
        for(int x : nums){
            if (!pos.count(x))
                unique.push_back(x), pos[x] = --unique.end(); 
            else if (pos[x] != unique.end())
                unique.erase(pos[x]), pos[x] = unique.end(); 
        }
    }
    
    int showFirstUnique() {
      return unique.empty()? -1 : unique.front(); 
    }
    
    void add(int value) {
        if (!pos.count(value))
            unique.push_back(value), pos[value] = --unique.end(); 
        else if (pos[value] != unique.end())
            unique.erase(pos[value]), pos[value] = unique.end(); 
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
