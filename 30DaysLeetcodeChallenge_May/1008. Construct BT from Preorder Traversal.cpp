/*
Construct Binary Search Tree from Preorder Traversal
Solution
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_value = INT_MAX){
        TreeNode dummy_root(INT_MAX);
        stack<TreeNode *> s({&dummy_root});
        for (int x : preorder) {
            auto n = new TreeNode(x);
            TreeNode *p = nullptr;
            while (s.top()->val < x) {
                p = s.top();
                s.pop();
            }
            if (p) {
                p->right = n;
            } else {
                s.top()->left = n;
            }
            s.push(n);
        }
        return dummy_root.left;
    }
};
