/*
Odd Even Linked List
Solution
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* temp = head->next;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        if(!temp)
            return head;
        while(temp2){
            temp2 = temp2->next;
            if(temp2->next)
                temp1->next = temp2->next;
            else{
                break;
            }
            temp1 = temp1->next;
            if(temp1->next)
                temp2->next = temp1->next;
            else{
                temp1->next = temp;
                temp2->next = NULL;
                return head;
            }
        }
        
        temp1->next = temp;
        return head;
    }
    
};
