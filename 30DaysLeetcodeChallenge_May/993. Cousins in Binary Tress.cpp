/*
Cousins in Binary Tree
Solution
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        vector<vector<int>> ans;
        if(!root)
            return true;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(level);
                level.resize(0);
                if(q.size())
                    q.push(NULL);
            }
            else{
                level.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        int count = 0;
        for(auto l : ans){
            count = 0;
            for(int k : l){
                if(k == x || k == y)
                    count++;
            }
            if(count == 2){
                return inorder(root, x, y);
            }
        }
         
        return false;
}
    bool inorder(TreeNode* root, int x, int y){
        if(!root)
            return true;
        if(root->left && root->right)
            if((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x))
                return false;
            
        return (inorder(root->left, x, y) && inorder(root->right, x, y));
    }
};
