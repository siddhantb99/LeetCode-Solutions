/*
Kth Smallest Element in a BST
Solution
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 = k = BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inorder(root, k, count);
        return count;
    }
    void inorder(TreeNode* root, int &k, int &count){
        if(!root)
            return;
        inorder(root->left, k, count);
    
        k--;
        if(k == 0){
            count = root->val;
            return;
        }
        inorder(root->right, k, count);
        return;
    }
};
